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
void insert(mstptr &t,int x,int m)
{
	if(!t)
	{
		t=create(x,m);
		return;
	}
	int i;
	for(i=0;i<t->cnt;i++)
	{
		if(x<t->key[i])
			return insert(t->cptr[i],x,m);
	}
	if(t->cnt==m-1)
		return insert(t->cptr[m-1],x,m);
	t->key[t->cnt]=x;
	t->cnt++;
}
void inorder(mstptr t)
{
	if(!t)
		return;
	int i=0;
	for(i=0;i<t->cnt;i++)
	{
		inorder(t->cptr[i]);
		cout<<t->key[i]<<" ";
	}
	inorder(t->cptr[t->cnt]);
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
			for(int i=0;i<q.front()->cnt;i++)
			{
				cout<<q.front()->key[i]<<" ";
				if(q.front()->cptr[i])
				q.push(q.front()->cptr[i]);
			}
			if(q.front()->cptr[q.front()->cnt])
			q.push(q.front()->cptr[q.front()->cnt]);
			q.pop();
			cout<<"\t";
		}
		q.pop();
		cout<<endl;
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
		if(x==-1)
			break;
		insert(MT,x,m);
	}
	inorder(MT);
	cout<<endl;
	levelorder(MT);
}