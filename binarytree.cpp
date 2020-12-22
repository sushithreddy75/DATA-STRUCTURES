#include<iostream>
using namespace std;
struct btnode
{
	btnode *lc;
	char data;
	btnode *rc;
};
typedef btnode* btptr;
void construct(btptr &t,char c)
{
	t=new(btnode);
	t->data=c;
	t->lc=t->rc=NULL;
	cout<<"lc of "<<t->data;
	cin>>c;
	if(c!='.')
		construct(t->lc,c);
	cout<<"rc of "<<t->data;
	cin>>c;
	if(c!='.')
		construct(t->rc,c);
}
struct node
{
	btptr data;
	node*next;
};
typedef node* lptr;
void push(lptr &h,btptr x)
{
	if(h==NULL)
	{
		h=new(node);
		h->data=x;
		h->next=NULL;
		return;
	}
	lptr t=new(node);
	t->data=x;
	t->next=h;
	h=t;
}
void preorder(btptr t)
{
	cout<<t->data<<" ";
	if(t->lc)
		preorder(t->lc);
	if(t->rc)
		preorder(t->rc);
}
void iterativepreorder(btptr t)
{
	lptr s=NULL;
	push(s,t);
	while(s!=NULL)
	{
		cout<<s->data->data<<" ";
		lptr t1=s;
		s=s->next;
		if(t1->data->rc)
			push(s,t1->data->rc);
		if(t1->data->lc)
			push(s,t1->data->lc);
	}
	cout<<endl;
}
void iterativeinorder(btptr t)
{
	lptr s=NULL;
	push(s,t);
	while(s->data->lc)
		push(s,s->data->lc);
	while(s!=NULL)
	{
		cout<<s->data->data<<" ";
		lptr t1=s;
		s=s->next;
		if(t1->data->rc)
		{
			push(s,t1->data->rc);
			while(s->data->lc)
				push(s,s->data->lc);
		}
	}
	cout<<endl;
}
/*void iterativepostorder(btptr t)
{
	lptr s=NULL;
	push(s,t);
	while(s->data->lc)
		push(s,s->data->lc);
	while(s!=NULL)
	{
		cout<<s->data->data<<" ";
		lptr t1=s;
		s=s->next;
	}
	cout<<endl;
}*/
int main()
{
	char c;
	btptr T=NULL;
	cin>>c;
	construct(T,c);
	preorder(T);cout<<endl;
	iterativepreorder(T);
	iterativeinorder(T);
	//iterativepostorder(T);
}