#include<iostream>
using namespace std;
struct btnode
{
	btnode *lc;
	char data;
	int space;
	btnode *rc;
};
typedef btnode* btptr;
struct qnode
{
	btptr data;
	qnode* next;
};
typedef qnode* qptr;
void enqueue(qptr &h,qptr t,btptr x)
{
	if(h==NULL)
	{
		h=new(qnode);
		h->data=x;
		h->next=NULL;
		return;
	}
	while(t->next!=NULL)
		t=t->next;
	t->next=new(qnode);
	t=t->next;
	t->data=x;
	t->next=NULL;
}
void construct(btptr &t,char c)
{
	t=new(btnode);
	t->data=c;
	t->lc=t->rc=NULL;
	cin>>c;
	if(c!='#')
		construct(t->lc,c);
	cin>>c;
	if(c!='#')
		construct(t->rc,c);
}
void addspace(btptr t,int &i)
{
	if(t==NULL)
		return;
	addspace(t->lc,i);
	t->space=i;
	i++;
	addspace(t->rc,i);
}
void print(btptr t)
{
	qptr q=NULL;
	enqueue(q,q,t);
	while(q!=NULL)
	{
		int p=0;
		enqueue(q,q,NULL);
		while(q->data!=NULL)
		{
			int s=q->data->space-p;
			p=q->data->space;
			if(s)
			while(--s)
				cout<<" ";
			cout<<q->data->data;
			if(q->data->lc)
				enqueue(q,q,q->data->lc);
			if(q->data->rc)
				enqueue(q,q,q->data->rc);
			q=q->next;
		}
		q=q->next;
		cout<<endl;
	}
}
int main()
{
	btptr T=NULL;
	char c;cin>>c;
	construct(T,c);
	int i=1;
	addspace(T,i);
	print(T);
}