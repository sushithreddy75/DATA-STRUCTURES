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
	insert(x,t->next);
}
void swap(lptr *x,lptr *y)
{
    lptr t=*x;
    *x=*y;
    *y=t;
}
void change(lptr h[],int i,int n)
{
	if(i>=n)
		return;
	if(2*i+1<n && h[i]->data>h[2*i+1]->data)
	{
		swap(h+i,h+2*i+1);
		if(2*i+2<n && h[i]->data>h[2*i+2]->data)
			change(h,i,n);
		change(h,2*i+1,n);
	}
	else if(2*i+2<n && h[i]->data>h[2*i+2]->data)
	{
		swap(h+i,h+2*i+2);
		change(h,2*i+2,n);
	}
}
void convert(lptr h[],int i)
{
	if(i<=0)
		return;
	if(h[i]->data<h[(i-1)/2]->data)
	{
		swap(h+i,h+(i-1)/2);
		convert(h,(i-1)/2);
	}
}
void add(lptr &h,lptr t)
{
	if(h==NULL)
	{
		h=t;
		return;
	}
	add(h->next,t);
}
void merge(lptr &l,lptr h[],int n)
{
    if(n==0)
    return;
	lptr t=h[0];
	h[0]=h[0]->next;
	t->next=NULL;
	add(l,t);
	if(!h[0])
	{
		h[0]=h[n-1];
		n--;
	}
	change(h,0,n);
	merge(l,h,n);
}
void print(lptr t)
{
	if(!t)
	{
		cout<<endl;
		return;
	}
	cout<<t->data<<" ";
	print(t->next);
}
int main()
{
	lptr H[50];
	int n;
	cin>>n;
	int i=0;
	while(1)
	{
		int x;
		cin>>x;
		if(x==-1)
			break;
		lptr h=NULL;
		while(1)
		{
			insert(x,h);
			cin>>x;
			if(x==-1)
				break;
		}
		H[i]=h;
		convert(H,i);
		i++;
	}
	lptr l=NULL;
	merge(l,H,i);
	print(l);
}