#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
typedef node* lptr;
struct kdnode
{
	kdnode *lc;
	lptr data;
	kdnode *rc;
};
typedef kdnode* kdptr;
void insert(lptr &h,int x)
{
	if(h==NULL)
	{
		h=new(node);
		h->data=x;
		h->next=NULL;
		return;
	}
	lptr t=h;
	while(t->next)
		t=t->next;
	t->next=new(node);
	t->next->data=x;
	t->next->next=NULL;
}
void construct(kdptr &t,lptr h,int n,int i,lptr t1)
{
	if(!t)
	{
		t=new(kdnode);
		t->data=h;
		t->lc=t->rc=NULL;
		return;
	}
	if(i==0)
		t1=h;
	lptr t2=t->data;
	int x=i;
	while(x--)
		t2=t2->next;
	if(t2->data>t1->data)
		return construct(t->lc,h,n,(i+1)%n,t1->next);
	construct(t->rc,h,n,(i+1)%n,t1->next);
}
void print(lptr t)
{
	while(t)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<endl;
}
void traverse(kdptr t)
{
	if(!t)
		return;
	traverse(t->lc);
	print(t->data);
	traverse(t->rc);
}
int main()
{
	freopen("in.txt","r",stdin);
	kdptr T=NULL;
	int n;
	cin>>n;
	while(1)
	{
		int x;
		cin>>x;
		if(x==-1)
			break;
		lptr t=NULL;
		int i=n;
		insert(t,x);
		while(--i)
		{
			cin>>x;
			insert(t,x);
		}
		construct(T,t,n,0,t);
	}
	traverse(T);
}