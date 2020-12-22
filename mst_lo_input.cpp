#include<bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;
struct mstnode
{
	mstnode **cptr;
	int *key;
};
typedef mstnode* mstptr;
mstptr create(int m)
{
	mstptr t=new(mstnode);
	t->cptr=new mstptr[m];
	t->key=new int[m-1];
	return t;
}
void construct(mstptr &T,mstptr &t,mstptr t1,int d,int m)
{
	if(!t)
	t=create(m);
	for(int i=0;i<m-1;i++)
	{
		if(t1&&!T&&d)
		{
			t->cptr[0]=t1;
			t1=NULL;
		}
		else if(d)
			construct(T,t->cptr[i],NULL,d-1,m);
		int x;
		cin>>x;
		if(x==-1)
		{
			T=t;
			return;
		}
		t->key[i]=x;
	}
	if(d)
		construct(T,t->cptr[m-1],NULL,d-1,m);
}
void construct(mstptr &T,int m)
{
	queue<pair<mstptr,int>>q;
	mstptr t=create(m);
	for(int i=0;i<m-1;i++)
		cin>>t->key[i];
	q.push(mp(t,1));
	while(!q.empty())
	{
		t=create(m);
		construct(T,t,q.front().F,q.front().S,m);
		if(T)
		{
			T=q.front().F;
			return;
		}
		q.push(mp(t,q.front().S+1));
		q.pop();
	}
}
void levelorder(mstptr t,int m)
{
	queue<mstptr>q;
	q.push(t);
	while(!q.empty())
	{
		q.push(NULL);
		while(q.front())
		{
			for(int i=0;i<m-1;i++)
				cout<<q.front()->key[i]<<" ";
			for(int i=0;i<m;i++)
			{
				if(q.front()->cptr[i])
				q.push(q.front()->cptr[i]);
			}
			q.pop();
		}
		cout<<endl;
		q.pop();
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	mstptr MT=NULL;
	int m;
	cin>>m;
	construct(MT,m);
	levelorder(MT,m);
}