#include<iostream>
using namespace std;
struct mlnode
{
	int tag;
	union
	{
		int x;
		mlnode *down;
	}data;
	mlnode *next;
};
struct node
{
	int data;
	node *next;
};
typedef node* lptr;
typedef mlnode* mlptr;
lptr createl(int x)
{
	lptr t=new(node);
	t->data=x;
	t->next=NULL;
	return t;
}
void create(mlptr &h,mlptr t)
{
	int x;
	cin>>x;
	if(x==-1)
		return;
	if(x==-2)
	{
		if(h==NULL)
		{
			h=new(mlnode);
			h->next=NULL;
			t=h;
		}
		else
		{
			t->next=new(mlnode);
			t=t->next;
			t->next=NULL;
		}
		t->tag=1;
		mlptr h1=NULL;
		create(h1,h1);
		t->data.down=h1;
		return create(h,t);
	}
	if(h==NULL)
	{
		h=new(mlnode);
		h->next=NULL;
		t=h;
	}
	else
	{
		t->next=new(mlnode);
		t=t->next;
		t->next=NULL;
	}
	t->tag=0;
	t->data.x=x;
	create(h,t);
}
void print1(mlptr t)
{
	if(t==NULL)
		return;
	if(t->tag==0)
	{
		cout<<t->data.x<<" ";
		print1(t->next);
		return;
	}
	print1(t->data.down);
	print1(t->next);
}
void flatten(mlptr t,lptr &h,lptr t1)
{
	if(t==NULL)
		return;
	if(t->tag==0)
	{
		lptr t2=createl(t->data.x);
		if(h==NULL)
		{
			h=t2;
			t1=t2;
		}
		else
		{
			t1->next=t2;
			t1=t2;
		}
		//cout<<"1\n";
		//lptr h2=NULL;
		flatten(t->next,h,t1);
		return;
	}
	//cout<<"2\n";
	lptr h2=NULL;
	flatten(t->data.down,h2,h2);
	t1->next=h2;
	while(t1->next!=NULL)
		t1=t1->next;
	//cout<<"3\n";
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
	create(head,head);
	lptr h=NULL;
	//print1(head);
	flatten(head,h,h);
	print(h);
	cout<<endl;
	return 0;
}