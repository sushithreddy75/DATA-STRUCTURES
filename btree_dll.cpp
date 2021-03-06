#include<bits/stdc++.h>
using namespace std;
struct bdnode
{
	int cnt;
	int *key;
	bdnode **ptr;
};
typedef bdnode* bdptr;
bdptr create(int d)
{
	bdptr t=new(bdnode);
	t->cnt=0;
	t->key=new int[d-1];
	t->ptr=new bdptr[d];
    for(int i=0;i<d;i++)
    t->ptr[i]=NULL;
	return t;
}
void insert(bdptr &T,int x,stack<bdptr>s,int d);//PROTOTYPE
void search(stack<bdptr>&s,bdptr t,int x)
{
	if(!t)
	return;
	s.push(t);
	for(int i=0;i<t->cnt;i++)
	{
		if(x<t->key[i])
		return search(s,t->ptr[i],x);
	}
	search(s,t->ptr[t->cnt],x);
}
void push(bdptr t,int x)
{
	int i;
	for(i=0;i<t->cnt;i++)
	{
		if(t->key[i]>x)
		break;
	}
	t->ptr[t->cnt+1]=t->ptr[t->cnt];
	for(int j=t->cnt;j>i;j--)
	{
		t->key[j]=t->key[j-1];
		t->ptr[j]=t->ptr[j-1];
	}
	t->key[i]=x;
	t->ptr[i]=NULL;
	t->cnt++;
}
void split(bdptr &T,stack<bdptr>s,bdptr l,bdptr r,int x,int d)//NOT DEFINED
{
	bdptr t=s.top(),t1=create(d+1);
	s.pop();
	int i,flag=0,j;
	for(i=0;i<=t->cnt;i++)
	{
		if(!flag && (t->key[i]>x||t->key[i]==0))
		{
			t1->key[i]=x;
			j=i;
			i++;
			flag=1;
		}
		if(flag)
		t1->key[i]=t->key[i-1];
		else
		t1->key[i]=t->key[i];
		if(flag)
		t1->ptr[i]=t->ptr[i-1];
		else
		t1->ptr[i]=t->ptr[i];
	}
	t1->ptr[d]=t->ptr[d-1];
	t1->ptr[j]=l;
	t1->ptr[j+1]=r;
	bdptr t2=create(d);
	t->cnt=d/2;t2->cnt=d-1-d/2;
	for(i=0;i<d/2;i++)
	{
		t->key[i]=t1->key[i];
		t->ptr[i]=t1->ptr[i];
	}
	t->ptr[i]=t1->ptr[i];
	for(i=0;i<t2->cnt;i++)
	{
		t2->key[i]=t1->key[i+d/2+1];
		t2->ptr[i]=t1->ptr[i+d/2+1];
	}
	t2->ptr[i]=t1->ptr[i+d/2+1];
	bdptr p=NULL;
	if(s.empty())
	{
		p=create(d);
		p->key[0]=t1->key[d/2];
		p->ptr[0]=t;
		p->ptr[1]=t2;
		p->cnt=1;
		T=p;
		return;
	}
	p=s.top();
	if(p->cnt<d-1)
	{
		push(p,t1->key[d/2]);
		for(i=0;i<p->cnt;i++)
		{
			if(p->key[i]==t1->key[d/2])
			break;
		}
		p->ptr[i]=t;
		p->ptr[i+1]=t2;
		return;
	}
	split(T,s,t,t2,t1->key[d/2],d);
}
void split(bdptr &T,stack<bdptr>s,int x,int d)
{
	bdptr t=s.top();			//t is LEFT t2 is RIGHT
	bdptr t1=create(d+1);
	int i,flag=0;
	for(i=0;i<=t->cnt;i++)
	{
		if(!flag && (t->key[i]>x||t->key[i]==0))
		{
			t1->key[i]=x;
			i++;
			flag=1;
		}
		if(flag)
		t1->key[i]=t->key[i-1];
		else
		t1->key[i]=t->key[i];
	}
	bdptr t2=create(d);
	t->cnt=d/2;t2->cnt=d-1-d/2;
	for(i=0;i<d/2;i++)
	t->key[i]=t1->key[i];
	for(i=0;i<t2->cnt;i++)
	t2->key[i]=t1->key[i+d/2+1];
	s.pop();
	bdptr p=NULL;
	if(s.empty())
	{

		p=create(d);
		p->key[0]=t1->key[d/2];
		p->ptr[0]=t;
		p->ptr[1]=t2;
		p->cnt=1;
		T=p;
		return;
	}
	p=s.top();
	if(p->cnt<d-1)
	{
		push(p,t1->key[d/2]);
		for(i=0;i<p->cnt;i++)
		{
			if(p->key[i]==t1->key[d/2])
			break;
		}
		p->ptr[i]=t;
		p->ptr[i+1]=t2;
		return;
	}
	split(T,s,t,t2,t1->key[d/2],d);
}
void insert(bdptr &T,int x,stack<bdptr>s,int d)
{
	if(!T)
	{
		T=create(d);
		T->cnt=1;
		T->key[0]=x;
		return;
	}
	if(s.empty())
	search(s,T,x);
	bdptr t=s.top();
	if(t->cnt<d-1)
	return push(t,x); 
	split(T,s,x,d);
}
void levelorder(bdptr t,bdptr &dll)
{
	queue<bdptr>q,q1;
	q.push(t);
	while(!q.empty())
	{
        q1=q;
		q.push(NULL);
		while(q.front())
		{
			int i;
			for(i=0;i<q.front()->cnt;i++)
			{
				cout<<q.front()->key[i]<<" ";
				if(q.front()->ptr[i])
					q.push(q.front()->ptr[i]);
			}
			if(q.front()->ptr[i])
				q.push(q.front()->ptr[i]);
			q.pop();
			//cout<<"    ";
		}
		cout<<endl;
		q.pop();
	}
    bdptr p=NULL;
    while(!q1.empty())
    {
        if(dll==NULL)
        dll=q1.front();
        t=q1.front();
        q1.pop();
        if(!q1.empty())
        {
            t->ptr[0]=p;
            t->ptr[t->cnt]=q1.front();
            p=t;
        }
        else 
        {
            t->ptr[0]=p;
            t->ptr[t->cnt]=NULL;
        }
    }
}
void printdll(bdptr t)
{
    bdptr t1;int i;
    while(t)
    {
        for(i=0;i<t->cnt;i++)
        cout<<t->key[i]<<" ";
        t1=t;
        t=t->ptr[t->cnt];
    }
    cout<<endl;
    while(t1)
    {
        for(i=t1->cnt-1;i>=0;i--)
        cout<<t1->key[i]<<" ";
        t1=t1->ptr[0];
    }
    cout<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	bdptr BT=NULL;
	int d=3;
	while(1)
	{
		int x;
		cin>>x;
        if(x==0)
        break;
		stack<bdptr>s;
		insert(BT,x,s,d);
	}
    bdptr dll=NULL;
	levelorder(BT,dll);
	printdll(dll);
	return 0;
}