#include<bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;
struct mstnode
{
	int cnt;
	int *key;
	mstnode **cptr;
	int min,max;
};
typedef mstnode* mstptr;
mstptr create(int m)
{
	mstptr t=new(mstnode);
	t->cnt=0;
	t->key=new int[m-1];
	//t->key[0]=x;
	t->cptr=new mstptr[m];
	for(int i=0;i<m;i++)
		t->cptr[i]=NULL;
	return t;
}
void create(mstptr &t,int m)
{
	queue<mstptr*>q;
	queue<pair<int,int>>q1;
	q.push(&t);
	q1.push(mp(-1e9,1e9));
	int flag=0,x;
	while(!q.empty())
	{
		mstptr t1=create(m);
		while(1)
		{
			if(t1->cnt==m-1)
				break;
			if(!flag)
				cin>>x;
			if(x==-1)
			{
				*q.front()=t1;
				return;
			}
			flag=1;
			if(x<q1.front().F||x>q1.front().S)
				break;
			t1->key[t1->cnt]=x;
			t1->cnt++;
			flag=0;
		}
		if(t1->cnt)
		*q.front()=t1;
		q.pop();
		for(int i=0;t1->cnt && i<=t1->cnt;i++)
		{
			q.push(&(t1->cptr[i]));
			if(i==0)
				q1.push(mp(q1.front().F,t1->key[0]));
			else if(i==t->cnt)
				q1.push(mp(t1->key[i-1],q1.front().S));
			else
				q1.push(mp(t1->key[i-1],t1->key[i]));
		}
		q1.pop();
	}
}
void levelorder(mstptr t)
{
	queue<mstptr>q;
	q.push(t);
	while(!q.empty())
	{
		q.push(NULL);
		while(q.front())
		{
			for(int i=0;q.front()->cnt &&i<q.front()->cnt;i++)
			{
				cout<<q.front()->key[i]<<" ";
				if(q.front()->cptr[i])
				q.push(q.front()->cptr[i]);
			}
			if(q.front()->cptr[q.front()->cnt])
			q.push(q.front()->cptr[q.front()->cnt]);
			q.pop();
			//cout<<"	  ";
		}
		q.pop();
		if(!q.empty())
		cout<<endl;
	}
}
mstptr findmax(mstptr t)
{
	//cout<<t->cnt<<endl;
	//cout<<t->cptr[0]->cnt<<endl;
	while( t->cptr[0]!=NULL )
		t=t->cptr[0];
	//cout<<t->key[0]<<endl;
	return t;
}
void push(mstptr t,int i)
{
	for(i;i<t->cnt-1;i++)
	{
		t->key[i]=t->key[i+1];
		t->cptr[i+1]=t->cptr[i+2];
	}
	t->cptr[t->cnt-1]=t->cptr[t->cnt];
	t->cnt--;
}
void del(mstptr &t,int x)
{
	if(!t)
		return;
	for(int i=0;i<t->cnt;i++)
	{
		if(t->key[i]>x)
			return del(t->cptr[i],x);
		if(t->key[i]==x)
		{
			if(t->cnt==1)
			{
				t=NULL;
				return;
			}
			if(t->cptr[i+1])
			{
				mstptr t1=findmax(t->cptr[i+1]);
				t->key[i]=t1->key[0];
				del(t1,t1->key[0]);
				return;
			}
			push(t,i);
			return;
		}
	}
	del(t->cptr[t->cnt],x);
}
int main()
{
	freopen("in.txt","r",stdin);
	mstptr GT=NULL;
	int m;cin>>m;
	create(GT,m);
	//cout<<GT->cptr[m];
	levelorder(GT);
	cout<<endl;
	int m1,n;
	cin>>m1>>n;
	del(GT,m1);
	//levelorder(GT);
	del(GT,n);
	cin>>n;
	del(GT,n);
	levelorder(GT);
	cout<<endl;
	//
}