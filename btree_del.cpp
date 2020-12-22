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
bool ldis(stack<pair<bdptr,int>>s,int d)
{
    int i=s.top().S;
    s.pop();
    if(s.empty())
    return false;
    bdptr t=s.top().F;
    i--;
    while(i>=0)
    {
        if(t->ptr[i] && t->ptr[i]->cnt<d-1)
        return true;
        i--;
    }
    return false;
}
bool rdis(stack<pair<bdptr,int>>s,int d)
{
    int i=s.top().S;
    s.pop();
    if(s.empty())
    return false;
    bdptr t=s.top().F;
    while(i<t->cnt)
    {
        i++;
        if(t->ptr[i] && t->ptr[i]->cnt<d-1)
        return true;
    }
    return false;
}
void rdis(bdptr p,bdptr t2,int k,int x,int d,bdptr l,bdptr r)
{
    bdptr t=p->ptr[k];
    if(t->cnt<d-1)
    {
        push(t,p->key[k-1]);
        t->ptr[0]=t2->ptr[t2->cnt];
        p->key[k-1]=t2->key[t2->cnt-1];
        return;
    }
    bdptr t1=create(d+1);
    insertnew(t,t1,l,r,x);
    rdis(p,t1,k+1,p->key[k],d,NULL,NULL);
    for(int i=0;i<d-1;i++)
    {
        t->key[i]=t1->key[i];
        t->ptr[i]=t1->ptr[i];
    }
    if(k>0 && t2)
    p->key[k-1]=t2->key[d-1];
    t->ptr[d-1]=t1->ptr[d-1];
    if(t2)
    t->ptr[0]=t2->ptr[t2->cnt];
    return;
}
void ldis(bdptr p,bdptr t2,int k,int x,int d,bdptr l,bdptr r)
{
    bdptr t=p->ptr[k];
    if(t->cnt<d-1)
    {
        push(t,p->key[k]);
        t->ptr[d-1]=t2->ptr[0];
        p->key[k]=t2->key[0];
        return;
    }
    bdptr t1=create(d+1);
    insertnew(t,t1,l,r,x);
    ldis(p,t1,k-1,p->key[k-1],d,NULL,NULL);
    for(int i=0;i<d-1;i++)
    {
        t->key[i]=t1->key[i+1];
        t->ptr[i+1]=t1->ptr[i+1];
    }
    if(k>=0 && t2)
    p->key[k]=t2->key[0];
    t->ptr[d-1]=t1->ptr[d-1];
    if(t2)
    t->ptr[d-1]=t2->ptr[0];
    return;
}
void del(bdptr &T,int d,int x,stack<pair<bdptr,int>>s);
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
	/*if(ldis(s,d))
    {
        int k=s.top().S;
        s.pop();
        ldis(s.top().F,NULL,k,t1->key[d/2],d,t,t2);
        return;
    }
    if(rdis(s,d))
    {
        int k=s.top().S;
        s.pop();
        rdis(s.top().F,NULL,k,t1->key[d/2],d,t,t2);
        return;
    }*/
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
   /* if(ldis(s,d))
    {
        int k=s.top().S;
        s.pop();
        ldis(s.top().F,NULL,k,x,d,NULL,NULL);
        return;
    }
    if(rdis(s,d))
    {
        int k=s.top().S;
        s.pop();
        rdis(s.top().F,NULL,k,x,d,NULL,NULL);
        return;
    }*/
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
}
bool left(bdptr p,int k,bdptr t1,int &x,int d)
{
    if(k<0)
    return false;
    bdptr t=p->ptr[k];
    if(t->cnt>(d-1)/2)
    {
        x=t->key[t->cnt-1];
        pb(t,x);
        int y=x;
        x=p->key[k];
        p->key[k]=y;
        return true;
    }
    if(left(p,k-1,p->ptr[k],x,d))
    {
        int y=x;
        if(t->cnt)
        x=t->key[t->cnt-1];
        push(t,y);
        y=x;
        x=p->key[k];
        if(t1)
        p->key[k]=y;
        if(t1)
        t->cnt--;
        return true;
    }
    return false;
}
bool left(stack<pair<bdptr,int>>s,int x,int d)
{
    int k=s.top().S;
    s.pop();
    x=0;
    if(s.empty())
    return false;
    return left(s.top().F,k,NULL,x,d);
}
bool right(bdptr p,int k,bdptr t1,int &x,int d)
{
    if(k>p->cnt)
    return false;
    bdptr t=p->ptr[k];
    if(t->cnt>(d-1)/2)
    {
        x=t->key[0];
        pb(t,x);
        int y=x;
        x=p->key[k-1];
        p->key[k-1]=y;
        return true;
    }
    if(right(p,k+1,p->ptr[k],x,d))
    {
        int y=x;
        if(!t1)
        {
            push(t,x);
            return true;
        }
        x=t->key[0];
        pb(t,x);
        t->key[t->cnt]=y;
        t->cnt++;
        y=x;
        x=p->key[k-1];
        if(t1)
        p->key[k-1]=y;
        return true;
    }
    return false;
}
bool right(stack<pair<bdptr,int>>s,int x,int d)
{
    int k=s.top().S;
    s.pop();
    x=0;
    if(s.empty())
    return false;
    return right(s.top().F,k,NULL,x,d);
}
void combine(stack<pair<bdptr,int>>s,int d,bdptr &T)
{
    int k=s.top().S,i;
    s.pop();
    bdptr t,t1,p=NULL;
    if(!s.empty())
    p=s.top().F;
    if(p==NULL)
    {
        T=T->ptr[0];
        return;
    }
    if(k>0)
    {
        t1=p->ptr[k];
        t=p->ptr[k-1];
        t->key[t->cnt]=p->key[k-1];
        t->cnt++;
        for(i=0;i<t1->cnt;i++)
        {
            t->key[i+t->cnt]=t1->key[i];
            t->ptr[i+t->cnt]=t1->ptr[i];
        }
        t->ptr[i+t->cnt]=t1->ptr[i];
        t->cnt+=t1->cnt;
        for(i=k-1;i<p->cnt;i++)
        {
            p->key[i]=p->key[i+1];
            p->ptr[i+1]=p->ptr[i+2];
        }
        //p->ptr[i]=p->ptr[i+1];
        p->cnt--;
    }
    else
    {
        t1=p->ptr[k+1];
        t=p->ptr[k];
        t->key[t->cnt]=p->key[k];
        t->cnt++;
        for(i=0;i<t1->cnt;i++)
        {
            t->key[i+t->cnt]=t1->key[i];
            t->ptr[i+t->cnt]=t1->ptr[i];
        }
        t->cnt+=t1->cnt;
        t->ptr[t->cnt]=t1->ptr[t1->cnt];
        for(i=k;i<p->cnt;i++)
        {
            p->key[i]=p->key[i+1];
            p->ptr[i+1]=p->ptr[i+2];
        }
        //p->ptr[i]=p->ptr[i+1];
        p->cnt--;
    }
    if(p==T && p->cnt==0)
    {
        T=T->ptr[0];
        return;
    }
    if(p->cnt<(d-1)/2)
    combine(s,d,T);
}
void internaldel(stack<pair<bdptr,int>>s,int x,int d,bdptr &T)
{
    bdptr t=s.top().F;
    int k=s.top().S;
    //s.pop();
    bdptr p=NULL;
    if(!s.empty())
    p=s.top().F;
    int i;
    for(i=0;i<t->cnt;i++)
    if(t->key[i]==x)
    break;
    t->key[i]=t->ptr[i+1]->key[0];
    s.push(mp(t->ptr[i+1],i+1));
    del(T,d,t->ptr[i+1]->key[0],s);
}
void del(bdptr &T,int d,int x,stack<pair<bdptr,int>>s)
{
    if(s.empty())
    search(s,T,x,0);
    bdptr t=s.top().F;
    if(leaf(t))
    {
        if(t->cnt>(d-1)/2)
        return pb(t,x);  
        pb(t,x);
        if(left(s,x,d))  
        return;
        if(right(s,x,d)) 
        return;
        combine(s,d,T);    
        return;
    }
    internaldel(s,x,d,T);
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
			cout<<"    ";
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
	}
	levelorder(BT);
	int c=5;
	while(c--)
	{
    cin>>n;
    stack<pair<bdptr,int>>s;
    del(BT,d,n,s);
    cout<<BT->cnt<<endl;
    levelorder(BT);cout<<endl;}
    /*cin>>n;
    del(BT,d,n);
    levelorder(BT);cin>>n;
    del(BT,d,n);
    levelorder(BT);cin>>n;
    del(BT,d,n);
    levelorder(BT);*/
	return 0;
}