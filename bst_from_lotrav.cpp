#include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lc;
	int data;
	bstnode *rc;
};
typedef bstnode* bstptr;
struct qnode
{
	bstptr data;
	int min,max;
	qnode* next;
};
typedef qnode* qptr;
void enqueue(qptr &h,qptr t,int min,int max,bstptr x)
{
	if(h==NULL)
	{
		h=new(qnode);
		h->data=x;
		h->min=min;
		h->max=max;
		h->next=NULL;
		return;
	}
	while(t->next!=NULL)
		t=t->next;
	t->next=new(qnode);
	t=t->next;
	t->data=x;
	t->min=min;
	t->max=max;
	t->next=NULL;
}
void construct(bstptr &t,int a[],int n)
{
	t=new(bstnode);
	t->data=a[0];
	t->lc=t->rc=NULL;
	qptr q=NULL;
	enqueue(q,q,0,1000,t);
	int i=1;
	while(i<n)
	{
	    int j=i;
		if(a[i]>q->min && a[i]<q->data->data)
		{
			bstptr t=new(bstnode);
			t->data=a[i];
			t->lc=t->rc=NULL;
			enqueue(q,q,q->min,q->data->data,t);
			q->data->lc=t;
			i++;
		}
		if(i<n && a[i]>q->data->data && a[i]<q->max)
		{
			bstptr t=new(bstnode);
			t->data=a[i];
			t->lc=t->rc=NULL;
			enqueue(q,q,q->data->data,q->max,t);
			q->data->rc=t;
			i++;
		}
		q=q->next;
	}
}
void inorder(bstptr t)
{
	if(t==NULL)
		return;
	inorder(t->lc);
	cout<<t->data<<" ";
	inorder(t->rc);
}
int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for(i=0;i<n;i++)
		cin>>a[i];
	bstptr T=NULL;
	construct(T,a,n);
	inorder(T);
	cout<<endl;
}