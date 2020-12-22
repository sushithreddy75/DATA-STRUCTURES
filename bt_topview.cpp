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
void topview(btptr t,int l,int r)
{
	if(t==NULL)
		return;
	topview(t->lc,l,0);
	if(l||r)
		cout<<t->data<<" ";
	topview(t->rc,0,r);
}
int main()
{
	btptr T=NULL;
	int n;cin>>n;
	construct(T,n);
	topview(T,1,1);
	cout<<endl;
}
