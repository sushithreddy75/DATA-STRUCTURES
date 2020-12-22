#include<iostream>
using namespace std;
struct btnode
{
	btnode *lc;
	int data;
	btnode *rc;
};
typedef btnode* btptr;
void construct(btptr &t,int x)
{
	t=new(btnode);
	t->data=x;
	t->lc=t->rc=NULL;
	cin>>x;
	if(x)
		construct(t->lc,x);
	cin>>x;
	if(x)
		construct(t->rc,x);
}
void inorder(btptr t)
{
	if(t==NULL)
		return;
	inorder(t->lc);
	cout<<t->data<<" ";
	inorder(t->rc);
}
void swap(btptr t,btptr t1)
{
	int x=t->data;
	t->data=t1->data;
	t1->data=x;
}
btptr leftcheck(btptr t,int x)
{
	if(!t)
		return NULL;
	if(t->data>x)
		return t;
	btptr t1=leftcheck(t->lc,x);
	btptr t2=leftcheck(t->rc,x);
	if(t1)
		return t1;
	return t2;
}
btptr rightcheck(btptr t,int x)
{
	if(!t)
		return NULL;
	if(t->data<x)
		return t;
	btptr t1=rightcheck(t->lc,x);
	btptr t2=rightcheck(t->rc,x);
	if(t1)
		return t1;
	return t2;
}
void convert(btptr t)
{
	if(!t||(!t->lc && !t->rc))
		return;
	if(t->lc)
	{
		btptr t1=leftcheck(t->lc,t->data);
		if(t1)
		{
			swap(t,t1);
			convert(t1);
			convert(t);
		}
	}
	if(t->rc)
	{
		btptr t1=rightcheck(t->rc,t->data);
		if(t1)
		{
			swap(t,t1);
			convert(t1);
			convert(t);
		}
	}
}
void bttobst(btptr t)
{
	if(!t)
		return;
	bttobst(t->lc);
	bttobst(t->rc);
	convert(t);
}
int main()
{
	btptr T=NULL;
	int x;cin>>x;
	construct(T,x);
	bttobst(T);
	inorder(T);cout<<endl;
}