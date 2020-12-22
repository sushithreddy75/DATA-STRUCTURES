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
void boundary(btptr t,int l,int r)
{
	if(t==NULL)
		return;
	if((t->lc==NULL && t->rc==NULL)||l==1)
		cout<<t->data<<" ";
	boundary(t->lc,l,0);
	boundary(t->rc,0,r);
	if((t->lc || t->rc) && r==1)
		cout<<t->data<<" ";
}
int main()
{
	btptr T=NULL;
	int c;cin>>c;
	construct(T,c);
	boundary(T,1,1);
	cout<<endl;
}