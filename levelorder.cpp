#include<iostream>
using namespace std;
struct bstnode
{
    bstnode* lchild;
    int data;
    bstnode *rchild;
};
typedef bstnode* bstptr;
struct queue
{
	bstptr data;
	queue *next;
};
typedef queue* qptr;
struct stack
{
	bstptr data;
	stack *next;
};
typedef stack* sptr;
void enqueue(qptr &q,qptr t,bstptr x)
{
	if(q==NULL)
	{
		q=new(queue);
		q->data=x;
		q->next=NULL;
		return;
	}
	if(t->next==NULL)
	{
		t->next=new(queue);
		t=t->next;
		t->data=x;
		t->next=NULL;
		return;
	}
	enqueue(q,t->next,x);
}
void push(sptr &s,bstptr x)
{
	if(s)
	{
		sptr t=new(stack);
		t->next=s;
		t->data=x;
		s=t;
		return;
	}
	s=new(stack);
	s->data=x;
	s->next=NULL;
}
void insert(bstptr &t,int x)
{
	if(t==NULL)
	{
		t=new(bstnode);
		t->data=x;
		t->lchild=t->rchild=NULL;
		return;
	}
	if(x>t->data)
		return insert(t->rchild,x);
	insert(t->lchild,x);
}
void printstack(sptr &s)
{
	if(s==NULL)
	{
		cout<<endl;
		return;
	}
	cout<<s->data->data<<" ";
	s=s->next;
	printstack(s);
}
void qprint(qptr &q)
{
	if(q==NULL)
		return;
	cout<<q->data->data<<" ";
	q=q->next;
	qprint(q);
}
void levelorder(qptr &q)
{
	if(q==NULL)
	{
		cout<<endl;
		return;
	}
	cout<<q->data->data<<" ";
	if(q->data->lchild)
	enqueue(q,q,q->data->lchild);
	if(q->data->rchild)
	enqueue(q,q,q->data->rchild);
	q=q->next;
	levelorder(q);
}
void revlevelorder(qptr &q,sptr &s)
{
	if(q==NULL)
		return;
	push(s,q->data);
	if(q->data->lchild)
	enqueue(q,q,q->data->lchild);
	if(q->data->rchild)
	enqueue(q,q,q->data->rchild);
	q=q->next;
	revlevelorder(q,s);
}
void levelrev(qptr &q)
{
	if(q==NULL)
	return;
	qptr q1=NULL;
	enqueue(q,q,NULL);
	while(q->data)
	{
		enqueue(q1,q1,q->data);
		if(q->data->lchild)
	    enqueue(q,q,q->data->lchild);
	    if(q->data->rchild)
	    enqueue(q,q,q->data->rchild);
	    q=q->next;
	}
	q=q->next;
	levelrev(q);
	qprint(q1);
}
void sqleft(sptr&);
void sqright(sptr&);
void sqleft(sptr &s)
{
	if(s==NULL)
		return;
	sptr s1=NULL;
	while(s)
	{
		cout<<s->data->data<<" ";
		if(s->data->lchild)
			push(s1,s->data->lchild);
		if(s->data->rchild)
		push(s1,s->data->rchild);
		s=s->next;
	}
	sqright(s1);
}
void sqright(sptr &s)
{
	if(s==NULL)
		return;
	sptr s1=NULL;
	while(s)
	{
		cout<<s->data->data<<" ";
		if(s->data->rchild)
		push(s1,s->data->rchild);
		if(s->data->lchild)
			push(s1,s->data->lchild);
		s=s->next;
	}
	sqleft(s1);
}
int main()
{
	int n;
	bstptr T=NULL;
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		insert(T,n);
	}
	qptr q1=NULL,q2=NULL;
	sptr s=NULL;
	enqueue(q1,q1,T);
	levelorder(q1);
	enqueue(q1,q1,T);
	revlevelorder(q1,s);
	printstack(s);
	q1=NULL;
	enqueue(q1,q1,T);
	levelrev(q1);cout<<endl;
	push(s,T);
	sqleft(s);cout<<endl;
	push(s,T);
	sqright(s);cout<<endl;
	push(s,T);
	sqleft(s);cout<<endl;
	push(s,T);
	sqright(s);cout<<endl;
	return 0;
}