#include<iostream>
using namespace std;
struct bstnode
{
    bstnode *lc;
    int data;
    bstnode *rc;
};
typedef bstnode* bstptr;
void lr(bstptr &t1)
{
    bstptr t = t1->rc;
    t1->rc = t->lc;
    t->lc = t1;
    t1 = t;
}
void rr(bstptr &t1)
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
		t->lc=t->rc=NULL;
		return;
	}
	if(t->data>x)
		return insert(t->lc,x);
	insert(t->rc,x);
}
void convert(bstptr &t,int x)
{
    if(!t||!(t->lc||t->rc))
    return;
    if(t->data<x)
    {
        convert(t->rc,x);
        lr(t);
        return;
    }
    convert(t->lc,x);
    rr(t);
}
void convert(bstptr &t,bstptr t1)
{
    if(!t||!t1)
    return;
    if(t->data!=t1->data)
    convert(t,t1->data);
    convert(t->lc,t1->lc);
    convert(t->rc,t1->rc);
}
void preorder(bstptr t)
{
    if(!t)
    return;
    cout<<t->data<<" ";
    preorder(t->lc);
    preorder(t->rc);
}
int main()
{
    freopen("in.txt","r",stdin);
    bstptr T1=NULL,T2=NULL;
    while(1)
    {
        int x;
        cin>>x;
        if(x==-1)
        break;
        insert(T1,x);
    }
    while(1)
    {
        int x;
        cin>>x;
        if(x==-1)
        break;
        insert(T2,x);
    }
    convert(T1,T2);
    preorder(T1);
    cout<<endl;
    return 0;
}

//TEST CASE
//6 4 2 1 3 5 8 7 9 -1
//7 5 4 2 1 3 6 8 9 -1
//OUTPUT
//7 5 4 2 1 3 6 8 9