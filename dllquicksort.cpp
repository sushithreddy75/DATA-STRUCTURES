#include<iostream>
using namespace std;
struct dlnode
{
    dlnode *left;
    int data;
    dlnode *right;
};
typedef dlnode* dlptr;
dlptr create(int x)
{
	dlptr t=new(dlnode);
	t->data=x;
	t->right=t->left=NULL;
	return t;
}
void insert(dlptr &h,dlptr t,int x)
{
	if(h==NULL)
	{
	    h=create(x);
	    return;
	}
	if(t->right==NULL)
	{
		t->right=create(x);
		t->right->left=t;
		return;
	}
	insert(h,t->right,x);
}
void print(dlptr h)
{
    if(h==NULL)
    return;
    cout<<h->data<<" ";
    print(h->right);
}
void addfront(dlptr &h,int x)
{
    dlptr t=create(x);
    t->right=h;
    h->left=t;
    h=t;
}
void addbefore(dlptr &h,int x,int y)
{
    if(h->data==y)
    return addfront(h,x);
    dlptr t=h;
    while(t->data!=y)
    t=t->right;
    dlptr t1=create(x);
    t1->right=t;
    t1->left=t->left;
    t->left->right=t1;
    t->left=t1;
}
void addafter(dlptr h,int x,int y)
{
    if(h->data==y)
    {
        dlptr t=create(x);
        t->right=h->right;
        t->left=h;
        h->right->left=t;
        h->right=t;
        return;
    }
    addafter(h->right,x,y);
}
void delfront(dlptr &h)
{
    h->right->left=NULL;
    h=h->right;
}
void delend(dlptr h)
{
    if(h->right==NULL)
    {
        h->left->right=NULL;
        return;
    }
    delend(h->right);
}
void del(dlptr &h,int x)
{
    if(h->data==x)
    {
        h->right->left=NULL;
        h=h->right;
        return;
    }
    dlptr t=h;
    while(t->data!=x)
    t=t->right;
    if(t->right==NULL)
    t->left->right=NULL;
    else
    {
        t->right->left=t->left;
        t->left->right=t->right;
    }
}
void addend(dlptr h,int x)
{
    insert(h,h,x);
}

dlptr partition(dlptr &h)
{
	dlptr t=h;
	while(t->right!=NULL)
		t=t->right;
	int x=t->data;
	t=h;
	while(t->data!=x)
	{
		int y=t->data;t=t->right;
        if(y>x){
		del(h,y);
		addend(h,y);}
	}
	return t;
}
void quicksort(dlptr &h)
{
    if(h==NULL || h->right==NULL)
    return;
    dlptr p=partition(h);
    //cout<<p->data<<endl;print(h);cout<<endl;
    if(p->left==NULL)
    {
        dlptr h2=p->right;
        h2->left=NULL;
        quicksort(h2);
        p->right=h2;h2->left=p;
        h=p;
        return;
    }
    if(p->right==NULL)
    {
        p->left->right=NULL;
        dlptr h1=h;
        quicksort(h1);
        dlptr t=h1;
        while(t->right!=NULL)
        t=t->right;
        t->right=p;
        h=h1;
        return;
    }
    dlptr h1=h,h2=p->right;
    h2->left=NULL;p->left->right=NULL;
    quicksort(h1);quicksort(h2);
    h=h1;p->right=h2;
    h2->left=p;
    while(h1->right!=NULL)
    h1=h1->right;
    h1->right=p;p->left=h1;
}
int main()
{
    dlptr head=NULL;
    while(1)
    {
        int n;cin>>n;
        if(n==-1)
        break;
        insert(head,head,n);
    }
    print(head);cout<<endl;
    int k;cin>>k;
    addfront(head,k);
    print(head);cout<<endl;
    cin>>k;
    addend(head,k);
    print(head);cout<<endl;
    int x;cin>>k>>x;
    addbefore(head,k,x);
    print(head);cout<<endl;
    cin>>k>>x;
    addafter(head,k,x);
    print(head);cout<<endl;
    delfront(head);
    print(head);cout<<endl;
    delend(head);
    print(head);cout<<endl;
    cin>>k;
    del(head,k);
    print(head);cout<<endl;
    quicksort(head);
    print(head);cout<<endl;
}