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
void insert(lptr &h,lptr t,int x)
{
	if(h==NULL)
	{
		h=create(x);
		return;
	}
	if(t->next==NULL)
	{
		t->next=create(x);
		return;
	}
	insert(h,t,x);
}
bool find(lptr t,int x)
{
	if(t==NULL)
		return false;
	if(t->data==x)
		return true;
	return find(t->next,x);
}
int len(lptr t)
{
	if(t==NULL)
		return 0;
	return 1+len(t->next);
}
int main()
{
	lptr map[10]={NULL};
	//inserting
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		insert(map[n%10],map[n%10],n);
	}
	//for checking
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		cout<<find(map[n%10],n)<<endl;
	}
	//for length
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		cout<<len(map[n%10])<<endl;
	}
}