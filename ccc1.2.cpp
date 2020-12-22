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
	lptr t=new(node);
	t->data=x;
	t->next=NULL;
	return t;
}
void insert(int x,lptr &t)
{
	if(t==NULL)
	{
		t=create(x);
		return;
	}
	t->next=create(x);
	t=t->next;
}
void del(lptr &h,lptr p,int c,int t)
{
	if(p==NULL)
		return;
	if(h->data==c && t==-1)
	{
		h=h->next;
		return del(h,h,c+1,-1);
	}
	if(t==-1)
		t=p->data;
	if(c==t-1)
	{
		t=p->next->data;
		p->next=p->next->next;
		del(h,p,c+1,t);
	}
	del(h,p->next,c+1,t);
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
	lptr head=NULL,t=NULL;
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		insert(n,t);
		if(head==NULL)
			head=t;
	}
	del(head,head,1,-1);
	print(head);
	cout<<endl;
}