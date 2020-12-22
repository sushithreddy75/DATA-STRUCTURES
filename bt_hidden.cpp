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
void hidden(btptr t,int lh,int rh)
{
    if(t==NULL)
    return;
    if(lh==0 && rh==0 && (t->lc || t->rc))
    cout<<t->data<<" ";
    hidden(t->lc,lh,0);
    hidden(t->rc,0,rh);
}
int main()
{
    btptr T=NULL;
    int x;cin>>x;
    construct(T,x);
    hidden(T,1,1);
}