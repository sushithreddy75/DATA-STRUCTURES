#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef node* lptr;
struct mlnode
{
	int data;
	node *down;
	mlnode *next;
};
typedef mlnode* mlptr;
lptr create(int x)
{
	lptr t=new(node);
	t->data=x;
	t->next=NULL;
	return t;
}
void insert(lptr &t,int x)
{
	if(t==NULL)
	{
		t=create(x);
		return;
	}
	t->next=create(x);
	t=t->next;
}
void construct(mlptr &h,mlptr t)
{
	int x;cin>>x;
	if(x==-1)
		return;
	if(x==-2)
	{
		lptr h1=NULL,t1=NULL;
		while(1)
		{
			int n;cin>>n;
			if(n==-1)
				break;
			insert(t1,n);
			if(h1==NULL)
				h1=t1;
		}
		t->down=h1;
		construct(h,t);
		return;
	}
	//cin>>x;
	if(h==NULL)
	{
		h=new(mlnode);
		h->data=x;
		h->next=NULL;h->down=NULL;
		construct(h,h);
		return;
	}
	t->next=new(mlnode);
	t=t->next;
	t->next=NULL;t->down=NULL;
	t->data=x;
	construct(h,t);
}
void flatten(mlptr t,lptr &h,lptr t1)
{
	if(t==NULL)
		return;
	lptr t2=create(t->data);
	if(h==NULL)
		h=t1=t2;
	else
	{
		t1->next=t2;
		t1=t2;
	}
	if(t->down!=NULL)
	{
		t2=t->down;
		while(t2!=NULL)
		{
			t1->next=create(t2->data);
			t2=t2->next;
			t1=t1->next;
		}
	}
	flatten(t->next,h,t1);
}
void print(lptr t)
{
	if(t==NULL)
		return;
	cout<<t->data<<" ";
	print(t->next);
}
int main()
{
	mlptr head=NULL;
	construct(head,head);
	lptr h=NULL;
	flatten(head,h,h);
	print(h);
	cout<<endl;
	return 0;
}