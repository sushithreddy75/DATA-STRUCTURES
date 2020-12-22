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
void inorder(bstptr t)
{
    if(!t)
    return;
    inorder(t->lc);
    cout<<t->data<<" ";
    inorder(t->rc);
}
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void minconstruct(int a[],int i)
{
    if(i<=0)
        return;
    if(a[i]<a[(i-1)/2])
    {
        swap(a+i,a+(i-1)/2);
        minconstruct(a,(i-1)/2);
    }
}
void minchange(int a[],int i,int n)
{
    if(i>=n)
        return;
    if(2*i+1<n && a[i]>a[2*i+1])
    {
        swap(a+i,a+2*i+1);
        if(2*i+1<n && a[i]>a[2*i+2])
            minchange(a,i,n);
        minchange(a,2*i+1,n);
    }
    else if(2*i+2<n && a[i]>a[2*i+2])
    {
        swap(a+i,a+2*i+2);
        minchange(a,2*i+2,n);
    }
}
void maxconstruct(int a[],int i)
{
    if(i<=0)
        return;
    if(a[i]>a[(i-1)/2])
    {
        swap(a+i,a+(i-1)/2);
        maxconstruct(a,(i-1)/2);
    }
}
void maxchange(int a[],int i,int n)
{
    if(i>=n)
        return;
    if(2*i+1<n && a[i]<a[2*i+1])
    {
        swap(a+i,a+2*i+1);
        if(2*i+1<n && a[i]<a[2*i+2])
            maxchange(a,i,n);
        maxchange(a,2*i+1,n);
    }
    else if(2*i+2<n && a[i]<a[2*i+2])
    {
        swap(a+i,a+2*i+2);
        maxchange(a,2*i+2,n);
    }
}
void insert(int h1[],int h2[],int &n1,int &n2,int x)
{
    if(n2==0)
    {
        h2[0]=x;
        n2++;
        return;
    }
    if(n1==0)
    {
        if(x<h2[0])
            h1[0]=x;
        else
        {
            h1[0]=h2[0];
            h2[0]=x;
        }
        n1++;
        return;
    }
    if(x>(h1[0]+h2[0])/2 && n1>=n2)
    {
        h2[n2]=x;
        n2++;
        minconstruct(h2,n2-1);
        return;
    }
    if(x>(h1[0]+h2[0])/2 && n2>n1)
    {
        if(h2[0]<x)
        {
            h1[n1]=h2[0];
            h2[0]=x;
        }
        else
        {
            h1[n1]=x;
        }
        n1++;
        maxconstruct(h1,n1-1);
        minchange(h2,0,n2);
        return;
    }
    if(n1<=n2)
    {
        h1[n1]=x;
        n1++;
        maxconstruct(h1,n1-1);
        return;
    }
    if(h1[0]>x)
    {
        h2[n2]=h1[0];
        h1[0]=x;
    }
    else
        h2[n2]=x;
    n2++;
    minconstruct(h2,n2-1);
    maxchange(h1,0,n1);
}
void addtoheap(bstptr t,int h1[],int h2[],int &n1,int &n2)
{
    if(!t)
        return;
    insert(h1,h2,n1,n2,t->data);
    addtoheap(t->lc,h1,h2,n1,n2);
    addtoheap(t->rc,h1,h2,n1,n2);
}
void merge(bstptr &t,int h1[],int h2[],int n1,int n2)
{
    if(n1<=0 && n2<=0)
        return;
    t=new(bstnode);
    t->lc=t->rc=NULL;
    if(n1>n2||n2<=0)
    {
        t->data=h1[0];
        h1[0]=h1[n1-1];
        n1--;
    }
    else
    {
        t->data=h2[0];
        h2[0]=h2[n2-1];
        n2--;
    }
    int x1[100],x2[100],n11=0,n22=0,i;
    for(i=0;i<n1;i++)
    insert(x1,x2,n11,n22,h1[i]);
    merge(t->lc,x1,x2,n11,n22);
    n11=0;n22=0;
    for(i=0;i<n2;i++)
    insert(x1,x2,n11,n22,h2[i]);
    merge(t->rc,x1,x2,n11,n22);
}

int main()
{
    int n,i;cin>>n;
    bstptr T[n]={NULL};
    for(i=0;i<n;i++)
    {
        T[i]=NULL;
        while(1)
        {
            int x;cin>>x;
            if(x==-1)
            break;
            insert(T[i],x);
        }
    }
    int h1[100],h2[100],n1=0,n2=0;
    for(i=0;i<n;i++)
    addtoheap(T[i],h1,h2,n1,n2);
    bstptr root=NULL;
    merge(root,h1,h2,n1,n2);
    inorder(root);
    cout<<endl;
    return 0;
}