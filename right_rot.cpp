#include<iostream>
#define trptr bstptr
#define rc rchild
#define lc lchild
using namespace std;
struct bstnode
{
    bstnode *lc;
    int data;
    bstnode *rc;
};
typedef bstnode* bstptr;
void lr(trptr &t1)
{
    bstptr t = t1->rc;
    t1->rc = t->lc;
    t->lc = t1;
    t1 = t;
}
void rr(trptr &t1)
{
    bstptr t=t1->lc;
    t1->lc=t->rc;
    t->rc=t1;
    t1=t;
}
void insert(bstptr &t,int x)
{
	if(t==NULL)
	{
		t=new(bstnode);
		t->data=x;
		t->lchild=t->rchild=NULL;
		return;
	}
	if(t->data>x)
		return insert(t->lchild,x);
	insert(t->rchild,x);
}
void inorder(bstptr t)
{
    if(!t)
    return;
    cout<<t->data<<" ";
    inorder(t->lc);
    inorder(t->rc);
}
void rot(bstptr &t,int x)
{
    if(!t)
    return;
    if(t->data==x)
    return rr(t);
    if(t->data>x)
    rot(t->lc,x);
    else
    rot(t->rc,x);
}
int main()
{
    freopen("in.txt","r",stdin);
    bstptr T=NULL;
    while(1)
    {
        int x;
        cin>>x;
        if(x==-2)
        break;
        if(x==-1)
        {
            cin>>x;
            rot(T,x);
            cin>>x;
            continue;
        }
        insert(T,x);
    }
    inorder(T);
}