#include<bits/stdc++.h>
using namespace std;
struct bstnode
{
	bstnode *lc;
	int data;
	bstnode *rc;
	int hd,vd;
};
typedef bstnode* bstptr;
void insert(bstptr &t,int x,int h,int v)
{
	if(!t)
	{
		t=new(bstnode);
		t->data=x;
		t->hd=h;
		t->vd=v;
		t->lc=t->rc=NULL;
		return;
	}
	if(t->data>x)
		return insert(t->lc,x,h-1,v+1);
	insert(t->rc,x,h+1,v+1);
}
int horizontalsum(bstptr t,int x)
{
	queue<bstptr>q;
	q.push(t);
	int sum=0;
	while(x-- && !q.empty())
	{
		q.push(NULL);
		while(q.front())
		{
			bstptr t=q.front();
			if(t->lc)
				q.push(t->lc);
			if(t->rc)
				q.push(t->rc);
			if(!x)
			sum+=t->data;
			q.pop();
		}
		q.pop();
	}
	return sum;
}
int main()
{
	bstptr T=NULL;
	int x;
	while(1)
	{
		cin>>x;
		if(x==-1)
			break;
		insert(T,x,0,0);
	}
	cin>>x;
	cout<<horizontalsum(T,x+1)<<endl;
}