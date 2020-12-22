#include<iostream>
using namespace std;
struct node
{
	int data;
	node*next;
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
lptr removeloop(lptr h)
{
	lptr sptr=h,fptr=h;
	while(fptr!=NULL && fptr->next!=NULL)
	{
		sptr=sptr->next;
		fptr=fptr->next->next;
		if(sptr==fptr)
			break;
	}
	if(sptr!=fptr)
		return NULL;
	lptr t=h;
	while(t->next!=sptr->next)
	{
		t=t->next;
		sptr=sptr->next;
	}
	return sptr;
}
void print(lptr t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		print(t->next);
	}
}
int main()
{
	lptr L1=NULL,L2=NULL,t=NULL;
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
	t->next=L1->next->next->next;
	t=removeloop(L1);
	cout<<t->next->data<<endl;
	t->next=NULL;
	print(L1);
	cout<<endl;
}