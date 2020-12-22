#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef node* lptr;
lptr create(int x)
{
	lptr t=new (node);
	t->data=x;
	t->next=NULL;
	return t;
}
lptr insert(lptr t,int x)
{
	if(t==NULL)
		return create(x);
	lptr t1=create(x);
	t->next=t1;
	return t1;
}
void partition(lptr &h,lptr p,lptr t)
{
	if(t==NULL || t->next==NULL)
		return;
	if(t->next->data<p->data)
	{
		lptr t1=t->next;
		t->next=t->next->next;
		t1->next=h;
		h=t1;
	}
	else
		t=t->next;
	partition(h,p,t);
}
void quicksort(lptr &h)
{
	if(h==NULL || h->next==NULL)
		return;
	lptr p=h;
	partition(h,p,h);
	lptr h1=NULL,h2=NULL;
	h2=p->next;
	if(h!=p)
	{
		h1=h;
		while(h1->next!=p)
			h1=h1->next;
		h1->next=NULL;
		h1=h;
		quicksort(h1);
	}
	quicksort(h2);
	if(h1!=NULL)
	{
	    h=h1;
		while(h1->next!=NULL)
			h1=h1->next;
		h1->next=p;
	}
	p->next=h2;
}
void print(lptr t)
{
	if(t==NULL)
	{
		cout<<endl;
		return;
	}
	cout<<t->data<<" ";
	print(t->next);
}
int main()
{
	lptr L1=NULL,t=NULL,L2;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	quicksort(L1);
	print(L1);
}