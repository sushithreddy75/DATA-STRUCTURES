#include<iostream>
using namespace std;
struct dnode
{
    int data;
    dnode *right,*left;
};
typedef dnode* dptr;
dptr create(int x)
{
    dptr t=new(dnode);
    t->data=x;
    t->right=t->left=NULL;
    return t;
}
void insert(dptr &h,int x)
{
    if(h==NULL)
    {
        h=create(x);
        h->left=h->right=h;
        return;
    }
    dptr t=h->left;
    t->right=create(x);
    t->right->left=t;
    t->right->right=h;
    h->left=t->right;
}
void print(dptr h,dptr t)
{
    cout<<t->data<<" ";
    t=t->right;
    if(t->data==h->data)
    cout<<t->data<<endl;
    if(t==h)
    return;
    print(h,t);
}
bool prev(dptr h,dptr t)
{
    if(h==t)
    return true;
    if(h->data==t->data)
    return false;
    return prev(h->right,t);
}
void callprint(dptr h,dptr t,dptr p)
{
    if(t->right==h)
    return;
    if(p==h)
    return callprint(h,t->right,t->right->right);
    if(p->data==t->data)
    {
        if(prev(h,t))
        print(t,t);
        return callprint(h,t->right,t->right->right);
    }
    callprint(h,t,p->right);
}
int main()
{
    dptr head=NULL;
    while(1)
    {
        int n;cin>>n;
        if(n==-1)
        break;
        insert(head,n);
    }
    callprint(head,head,head->right);
}
