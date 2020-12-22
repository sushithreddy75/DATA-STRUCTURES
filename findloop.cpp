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
bool check(lptr t)
{
	lptr s=t;
	while(t!=NULL)
	{
		s=s->next;
		t=t->next->next;
		if(s==t)
			return true;
	}
	return false;
}
int main()
{
	lptr head=NULL,t=NULL;
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
			break;
		t=insert(t,n);
		if(head==NULL)
			head=t;
	}
	t->next=head;//created loop
	if(check(head))
		cout<<"loop found\n";
	else 
		cout<<"no loop\n";
	return 0;
}