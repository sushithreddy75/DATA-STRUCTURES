#include<iostream>
using namespace std;
struct  bstnode
{
	bstnode *lc;
	int data;
	bstnode *rc;
};
typedef bstnode* bstptr;
void insert(bstptr &t,int x)
{
	t=new(bstnode);
	t->data=x;
	t->lc=t->rc=NULL;
	cin>>x;
	if(x)
		insert(t->lc,x);
	cin>>x;
	if(x)
		insert(t->rc,x);
}
void check(bstptr t,bstptr &prev,bstptr &x,bstptr &y)
{
	if(t==NULL)
		return;
	check(t->lc,prev,x,y);
	if(prev==NULL)
		prev=t;
	else if(t->data<prev->data)
	{
		if(x==NULL)
			x=prev;
		else
			y=t;
	}
	check(t->rc,prev,x,y);
}
void inorder(bstptr t)
{
	if(t==NULL)
		return;
	inorder(t->lc);
	cout<<t->data<<" ";
	inorder(t->rc);
}
void swap(bstptr x,bstptr y)
{
	int t=x->data;
	x->data=y->data;
	y->data=t;
}
int main()
{
	bstptr T=NULL;
	int n;cin>>n;
	insert(T,n);
	bstptr prev=NULL,x=NULL,y=NULL;
	check(T,prev,x,y);
	swap(x,y);
	inorder(T);
	cout<<endl;
	return 0;
}