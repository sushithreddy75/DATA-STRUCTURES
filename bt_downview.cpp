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
void downview(btptr t)
{
	if(t==NULL)
		return;
	downview(t->lc);
	if(t->lc==NULL && t->rc==NULL)
	cout<<t->data<<" ";
	downview(t->rc);
}
int main()
{
	btptr T=NULL;
	int n;cin>>n;
	construct(T,n);
	downview(T);
	cout<<endl;
}
