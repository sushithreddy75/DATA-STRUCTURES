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
        if(x==t->key[i])
        {
            //s.push(mp(t->ptr[i],i));
            return;
        }
		if(x<t->key[i])
		return search(s,t->ptr[i],x,i);
	}
	search(s,t->ptr[t->cnt],x,t->cnt);
}
void insertnew(bdptr t,bdptr t1,bdptr l,bdptr r,int x)
{
    int i,j,flag=0;
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
	t1->cnt=t->cnt+1;
	t1->ptr[t1->cnt]=t->ptr[t->cnt];
    if(l)
	t1->ptr[j]=l;
    if(r)
	t1->ptr[j+1]=r;
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
void split(bdptr &T,stack<pair<bdptr,int>>s,bdptr l,bdptr r,int x,int d)
{
	bdptr t=s.top().F,t1=create(d+1);
	s.pop();
	int i,j;
	insertnew(t,t1,l,r,x);
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
			if(p->key[i]==t1->key[d/2])
            break;
		p->ptr[i]=t;
		p->ptr[i+1]=t2;
		return;
	}
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
	split(T,s,NULL,NULL,x,d);
}
bool leaf(bdptr t)
{
    for(int i=0;i<=t->cnt;i++)
    {
        if(t->ptr[i])
        return false;
    }
    return true;
}
void pb(bdptr t,int x)
{
    int i;
    for(i=0;i<t->cnt;i++)
    if(t->key[i]==x)
    break;
    t->cnt--;
    for(i;i<t->cnt;i++)
    t->key[i]=t->key[i+1];
    for(i=0;i<=t->cnt;i++)
    t->ptr[i]=t->ptr[i+1];
}
bool left(bdptr p,int k,int d,bdptr t2,int &x)
{
    if(k<0)
    return false;
    bdptr t=p->ptr[k];
    if(t->cnt>(d-1)/2)
    {
        x=t->key[t->cnt-1];
        t->cnt--;
        int y=p->key[k];
        p->key[k]=x;
        x=y;
        return true;
    }
    if(left(p,k-1,d,t,x))
    {
        if(t2==NULL)
        {
            push(t,x);
            return true;
        }
        int y=x;
        push(t,x);
        t->cnt--;
        x=t->key[t->cnt];
        y=x;
        x=p->key[k];
        p->key[k]=y;
        return true;
    }
    return false;
}
bool left(stack<pair<bdptr,int>>s,int d)
{
    bdptr t=s.top().F;
    int k=s.top().S;
    s.pop();
    bdptr t1=NULL;int x1=0;
    if(s.empty())
    return false;
    return left(s.top().F,k,d,t1,x1);
}
bool right(bdptr p,int k,int d,bdptr t2,int &x,bdptr &t1,int &c)
{
    //cout<<"je\n";
    if(c==2||k>p->cnt)
    return false;
    bdptr t=p->ptr[k];
    if(t->cnt>(d-1)/2)
    {
        x=t->key[0];
        t1=t->ptr[0];
        pb(t,x);
        int y=p->key[k-1];
        p->key[k-1]=x;
        x=y;
        return true;
    }
    c++;
    if(right(p,k+1,d,t,x,t1,c))
    {
        if(t2==NULL)
        {
            t->key[t->cnt]=x;
            t->cnt++;
            t->ptr[t->cnt]=t1;
            return true;
        }
        int y=x;
        x=t->key[0];
        bdptr t3=t1;
        t1=t->ptr[0];
        pb(t,x);
        t->key[t->cnt]=y;
        t->cnt++;
        t->ptr[t->cnt]=t3;
        y=p->key[k-1];
        p->key[k-1]=x;
        x=y;
        return true;
    }
    return false;
}
bool right(stack<pair<bdptr,int>>s,int d)
{
    bdptr t=s.top().F;
    int k=s.top().S;
    s.pop();int c=0;
    bdptr t1=NULL;int x1=0;
    if(s.empty())
    return false;
    return right(s.top().F,k,d,t1,x1,t1,c);
}
void combine(bdptr &T,stack<pair<bdptr,int>>s,int d)
{
    if(left(s,d))
        return;
        if(right(s,d))
        return;
    bdptr t=s.top().F;
    int k=s.top().S,i;
    s.pop();
    if(s.empty())
    {
        T=T->ptr[0];
        return;
    }
    bdptr p=s.top().F,t1;
    if(k>0)
    {
        t=p->ptr[k-1];
        t1=p->ptr[k];
        t->key[t->cnt]=p->key[k-1];
        for(i=0;i<t1->cnt;i++)
        {
            t->key[t->cnt+1+i]=t1->key[i];
            t->ptr[t->cnt+1+i]=t1->ptr[i];
        }
        t->ptr[t->cnt+1+i]=t1->ptr[i];
        t->cnt+=t1->cnt+1;
        for(i=k-1;i<p->cnt;i++)
        {
            p->key[i]=p->key[i+1];
            p->ptr[i+1]=p->ptr[i+2];
        }
    }
    else 
    {
        t1=p->ptr[k+1];
        t->key[t->cnt]=p->key[k];
        for(i=0;i<t1->cnt;i++)
        {
            t->key[t->cnt+1+i]=t1->key[i];
            t->ptr[t->cnt+1+i]=t1->ptr[i];
        }
        t->ptr[t->cnt+1+i]=t1->ptr[i];
        t->cnt+=t1->cnt+1;
        for(i=k;i<p->cnt;i++)
        {
            p->key[i]=p->key[i+1];
            p->ptr[i+1]=p->ptr[i+2];
        }
    }
    p->cnt--;
    if(p->cnt<(d-1)/2)
    combine(T,s,d);
}
void del(bdptr &T,int x,stack<pair<bdptr,int>>s,int d);
void delinternal(bdptr &T,int x,stack<pair<bdptr,int>>s,int d)
{
    int k=s.top().S;
    bdptr t=s.top().F;
    int i;
    for(i=0;i<t->cnt;i++)
    if(t->key[i]==x)
    break;
    if(t->ptr[i+1])
    {
        t->key[i]=t->ptr[i]->key[0];
        s.push(mp(t->ptr[i],i));
     del(T,t->ptr[i]->key[0],s,d);
    }
}
void del(bdptr &T,int x,stack<pair<bdptr,int>>s,int d)
{
    if(s.empty())
    search(s,T,x,0);
    bdptr t=s.top().F;
    if(leaf(t))
    {
        pb(t,x);
        if(t->cnt>=(d-1)/2)
        return;
        if(left(s,d))
        return;
        if(right(s,d))
        return;
        combine(T,s,d);
        return;
    }
    delinternal(T,x,s,d);
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
	int d=5,n;
	//cin>>d>>n;
	while(1)
	{
		int x;
		cin>>x;
        if(!x)
        break;
		stack<pair<bdptr,int>>s;
		insert(BT,x,s,d);
		//levelorder(BT);cout<<endl;
	}
	levelorder(BT);
	int c=5;
	while(c--)
	{
    cin>>n;
    stack<pair<bdptr,int>>s;
    del(BT,n,s,d);}
    levelorder(BT);
	return 0;
}