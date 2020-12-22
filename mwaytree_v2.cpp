#include<bits/stdc++.h>
using namespace std;
struct mstnode
{
	int cnt;
	int *key;
	mstnode **cptr;
};
typedef mstnode* mstptr;
mstptr create(int x,int m)
{
	mstptr t=new(mstnode);
	t->cnt=1;
	t->key=new int[m-1];
	t->key[0]=x;
	t->cptr=new mstptr[m];
	return t;
}
void pb(mstptr t,int i,int x)
{
	for(int j=t->cnt;j>i;j--)
	{
		t->key[j]=t->key[j-1];
		t->cptr[j+1]=t->cptr[j];
	}
	t->key[i]=x;
	t->cnt++;
}
void insert(mstptr &t,int x,int m)
{
	if(!t)
	{
		t=create(x,m);
		return;
	}
	for(int i=0;i<t->cnt;i++)
	{
		if(t->key[i]>x)
		{
			if(t->cnt==m-1)
				return insert(t->cptr[i],x,m);
			return pb(t,i,x);
		}
	}
	if(t->cnt==m-1)
		return insert(t->cptr[t->cnt],x,m);
	t->key[t->cnt]=x;
	t->cnt++;
}
void inorder(mstptr t)
{
	if(!t)
		return;
	for(int i=0;i<t->cnt;i++)
	{
		inorder(t->cptr[i]);
		cout<<t->key[i]<<" ";
	}
	inorder(t->cptr[t->cnt]);
}
void levelorder(mstptr t,int k)
{
	queue<mstptr>q;
	q.push(t);
	while(!q.empty())
	{
		q.push(NULL);int x;
		if(k==0)
		 x=-1;
		else
		x=2;
		while(q.front())
		{
			for(int i=0;i<q.front()->cnt;i++)
			{
				cout<<q.front()->key[i]<<" ";
				if(k==0 && x==-1)
				{
				    //cout<<q.front()->key[i]<<" ";
				    x=0;
				}
				x=q.front()->key[i];
				if(q.front()->cptr[i])
				q.push(q.front()->cptr[i]);
			}
			if(q.front()->cptr[q.front()->cnt])
			q.push(q.front()->cptr[q.front()->cnt]);
			q.pop();
			
			//cout<<"	  ";
		}
		q.pop();
		//if(k==1)
		//	cout<<x<<" ";
		//cout<<endl;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	mstptr MT=NULL;
	int m;
	cin>>m;
	while(1)
	{
		int x;
		cin>>x;
		if(x==0)
			break;
		insert(MT,x,m);
	}
	//inorder(MT);
	//cout<<endl;
	levelorder(MT,0);cout<<endl;
	levelorder(MT,1);
}