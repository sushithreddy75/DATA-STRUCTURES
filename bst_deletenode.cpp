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
bstptr max(bstptr t)
{
	while(t->rc)
		t=t->rc;
	return t;
}
void del(bstptr &t,int x)
{
	if(!t)
		return;
	if(t->data>x)
		return del(t->lc,x);
	if(t->data<x)
		return del(t->rc,x);
	if(!t->lc && !t->rc)
	{
		t=NULL;
		return;
	}
	if(!t->lc)
	{
		t=t->rc;
		return;
	}
	if(!t->rc)
	{
		t=t->lc;
		return;
	}
	bstptr t1=max(t->lc);
	t->data=t1->data;
	del(t->lc,t1->data);
}
void inorder(bstptr t)
{
	if(!t)
		return;
	inorder(t->lc);
	cout<<t->data<<" ";
	inorder(t->rc);
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
		insert(T,x);
	}
	inorder(T);
	cout<<endl;
	cin>>x;
	del(T,x);
	inorder(T);
	cout<<endl;
}