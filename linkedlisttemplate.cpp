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
void insertfront(lptr &t,int x)
{
	if(t==NULL)
	{
		t=create(x);
		return;
	}
	lptr temp=create(x);
	temp->next=t;
	t=temp;
}
void print(lptr t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		print(t->next);
	}
}
void reverseprint(lptr t)
{
	if(t!=NULL)
	{
		reverseprint(t->next);
		cout<<t->data<<" ";
	}
}
void insertbefore(lptr &t,int x,int y)
{
	lptr temp=t;
	if(t->data==y)
	{
		temp=create(x);
		temp->next=t;
		t=temp;
		return;
	}
	while(temp->next->data!=y)
		temp=temp->next;
	lptr temp1=create(x);
	temp1->next=temp->next;
	temp->next=temp1;
}
void insertafter(lptr t,int x,int y)
{
	if(t->data==y)
	{
		lptr temp=create(x);
		temp->next=t->next;
		t->next=temp;
		return;
	}
	insertafter(t->next,x,y);
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
	print(head);cout<<endl;
	reverseprint(head);cout<<endl;
	int x,y;
	cin>>x>>y;
	insertafter(head,x,y);
	print(head);
	cout<<endl;
	reverseprint(head);cout<<endl;
	insertbefore(head,x,y);
	print(head);cout<<endl;
	reverseprint(head);cout<<endl;
	insertfront(head,x);
	print(head);cout<<endl;
	reverseprint(head);cout<<endl;
	return 0;
}