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
struct node
{
	btptr data;
	node *next;
};
typedef node* lptr;
void push(lptr &h,btptr t)
{
	if(h==NULL)
	{
		h=new(node);
		h->data=t;
		h->next=NULL;
		return;
	}
	lptr t1=new(node);
	t1->data=t;
	t1->next=h;
	h=t1;
}
void find(int x,lptr &h,btptr t)
{
	if(h->data->data==x)
		return;
	if(h->data->lc)
	{
		push(h,h->data->lc);
		find(h,x);
		if(h->data->data==x)
			return;
		h=h->next;
	}
	if(h->data->rc)
	{
		push(h,h->data->rc);
		find(h,x);
		if(h->data->data==x)
			return;
		h=h->next;
	}
}
void max(lptr &l1,lptr &l2)
{
	l1=l1->next;
	l2=l2->next;
	rev(l1,l1,NULL);
	rev(l2,l2,NULL);
	while(l1->data==l2->data)
	{
		l1=l1->next;
		l2=l2->next;
	}
	int max1=0;
	while(l1!=NULL)
	{
		if(l1->data>max1)
			max1=l1->data;
		l1=l1->next;
	}
	while(l2!=NULL)
	{
		if(l2->data>max1)
			max1=l2->data;
		l2=l2->next;
	}
	cout<<max1<<" ";
}
int main()
{
	btptr T=NULL;
	int x;cin>>x;
	construct(T,x);
	int y;
	for(int i=0;i<3;i++)
	{
		cin>>x>>y;
		lptr l1=NULL,l2=NULL;
		find(x,l1,T);find(y,l2,T);
		max(l1,l2);
	}
	return 0;
}