#include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lc;
	int data;
	bstnode *rc;
};
typedef bstnode* bstptr;
void insert(bstptr &t,int x)
{
	if(!t)
	{
		t=new(bstnode);
		t->data=x;
		t->lc=t->rc=NULL;
		return;
	}
	if(t->data>x)
		return insert(t->lc,x);
	insert(t->rc,x);
}
void convert(bstptr t,bstptr &prev)
{
	if(!t)
		return;
	convert(t->lc,prev);
	t->lc=prev;
	if(prev)
		prev->rc=t;
	prev=t;
	convert(t->rc,prev);
}
void check(bstptr h,int s)
{
	bstptr t=h,l,r,t1;
	t1=h;
	while(t1->rc)
		t1=t1->rc;
	while(t)
	{
		int x=s-t->data;
		l=t->rc;r=t1;
		while(l && r && l->data<r->data && l!=r)
		{
			if(l->data+r->data>x)
				r=r->lc;
			else if(l->data+r->data<x)
				l=l->rc;
			else
			{
				cout<<t->data<<" "<<l->data<<" "<<r->data<<endl;
				l=l->rc;
				r=r->lc;
			}
		}
		t=t->rc;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	bstptr T=NULL;
	while(1)
	{
		int x;
		cin>>x;
		if(x==-1)
			break;
		insert(T,x);
	}
	bstptr p=NULL,t=T;
	while(t->lc)
		t=t->lc;
	convert(T,p);
	int s;cin>>s;
	check(t,s);
	return 0;
}