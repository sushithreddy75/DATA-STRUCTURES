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
void leftview(btptr t,int &x,int h)
{
	if(t==NULL)
		return;
	if(h>x)
	{
		x=h;
		cout<<t->data<<" ";
	}
	leftview(t->lc,x,h+1);
	leftview(t->rc,x,h+1);
}
int main()
{
	btptr T=NULL;
	int n;cin>>n;
	construct(T,n);
	int x=-1;
	leftview(T,x,0);
	cout<<endl;
}
