#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
using namespace std;
struct bdnode
{
	int cnt;
	int *key;
	bdnode **ptr;
    bdnode *l,*r;
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
void search(stack<pair<bdptr,int>>&s,bdptr t,int x,int k)
{
	if(!t)
	return;
	s.push(mp(t,k));
	for(int i=0;i<t->cnt;i++)
	{
		if(x<t->key[i])
		return search(s,t->ptr[i],x,i);
	}
	search(s,t->ptr[t->cnt],x,t->cnt);
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
bool ldis(stack<pair<bdptr,int>>s,int d)
{
    int i=s.top().S;
    s.pop();
    if(!s.empty() && i>0 && s.top().F->ptr[i-1]->cnt<d-1)
    return true;
    return false;
}
bool rdis(stack<pair<bdptr,int>>s,int d)
{
    int i=s.top().S;
    s.pop();
    if(!s.empty() && i<s.top().F->cnt && s.top().F->ptr[i+1] && s.top().F->ptr[i+1]->cnt<d-1)
    return true;
    return false;
}
void ldis(stack<pair<bdptr,int>>s,int x,int d)
{
    int j=s.top().S;
    bdptr t=s.top().F;
    s.pop();
    bdptr t3=s.top().F;
    bdptr t2=t3->ptr[j-1];
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
	for(i=0;i<t->cnt;i++)
    t->key[i]=t1->key[i+1];
    t2->key[t2->cnt]=t3->key[j-1];
    t2->cnt++;
    t3->key[j-1]=t1->key[0];
}
void rdis(stack<pair<bdptr,int>>s,int x,int d)
{
    int j=s.top().S;
    bdptr t=s.top().F;
    s.pop();
    bdptr t3=s.top().F;
    bdptr t2=t3->ptr[j+1];
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
	for(i=0;i<t->cnt;i++)
    t->key[i]=t1->key[i];
    push(t2,t3->key[j]);
    t3->key[j]=t1->key[t->cnt];
}
void split(bdptr &T,stack<pair<bdptr,int>>s,bdptr l,bdptr r,int x,int d)//NOT DEFINED
{
	bdptr t=s.top().F,t1=create(d+1);
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
	p=s.top().F;
	if(p->cnt<d-1)
	{
		push(p,t1->key[d/2]);
		for(i=0;i<p->cnt;i++)
		{
			if(p->key[i]==t1->key[d/2])			break;
		}
		p->ptr[i]=t;
		p->ptr[i+1]=t2;
		return;
	}
	if(ldis(s,d))
    return ldis(s,t1->key[d/2],d);
    if(rdis(s,d))
    return rdis(s,t1->key[d/2],d);
	split(T,s,t,t2,t1->key[d/2],d);
}
void insert(bdptr &T,int x,stack<pair<bdptr,int>>s,int d)
{
	if(!T)
	{
		T=create(d);
		T->cnt=1;
		T->key[0]=x;
		return;
	}
	if(s.empty())
	{search(s,T,x,0);}
	bdptr t=s.top().F;
	if(t->cnt<d-1)
	return push(t,x); 
    if(ldis(s,d))
    return ldis(s,x,d);
    if(rdis(s,d))
    return rdis(s,x,d);
	split(T,s,NULL,NULL,x,d);
}
void levelorder(bdptr t)
{
	queue<bdptr>q;
	q.push(t);
	while(!q.empty())
	{
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
}
int main()
{
	freopen("in.txt","r",stdin);
	bdptr BT=NULL;
	int d,n;
	cin>>d>>n;
	while(n--)
	{
		int x;
		cin>>x;
		stack<pair<bdptr,int>>s;
		insert(BT,x,s,d);
        //levelorder(BT);cout<<endl;
	}
	levelorder(BT);
	return 0;
}