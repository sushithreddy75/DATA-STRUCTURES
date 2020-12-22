#include<iostream>
#include<stack>
using namespace std;
struct node
{
	int data;
	node*next;
};
typedef node* lptr;
void insert(lptr &h,int x,lptr &t1)
{
	if(h==NULL)
	{
		h=new(node);
		h->data=x;
		h->next=NULL;
		return;
	}
	lptr t=h;
	while(t->next)
		t=t->next;
	t->next=new(node);
	t->next->data=x;
	t->next->next=NULL;
	t1=t;
}
void join(lptr t,lptr a,lptr b,lptr c)
{
	if(!t)
		return;
	if(t->data==a->next->data)
		a->next=t;
	if(t->data==b->next->data)
		b->next=t;
	if(t->data==c->next->data)
		c->next=t;
	join(t->next,a,b,c);
}
void stackit(lptr t,stack<lptr>&s)
{
	while(t)
	{
		s.push(t);
		t=t->next;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	lptr l1,l2,l3,l4,a,b,c;
	l1=l2=l3=l4=a=b=c=NULL;
	int x;
	while(1)
	{
		cin>>x;
		if(x==-1)
			break;
		insert(l1,x,a);
	}
	while(1)
	{
		cin>>x;
		if(x==-1)
			break;
		insert(l2,x,a);
	}
	while(1)
	{
		cin>>x;
		if(x==-1)
			break;
		insert(l3,x,b);
	}
	while(1)
	{
		cin>>x;
		if(x==-1)
			break;
		insert(l4,x,c);
	}
	join(l1,a,b,c);
	stack<lptr>s1,s2,s3,s4;
	stackit(l1,s1);
	stackit(l2,s2);
	stackit(l3,s3);
	stackit(l4,s4);
	lptr t;
	while(s1.top()==s2.top() && s2.top()==s3.top() && s3.top()==s4.top())
	{
		t=s1.top();
		s1.pop();s2.pop();s3.pop();s4.pop();
	}
	if(s2.top()!=s3.top() && s3.top()==s4.top())
		cout<<"2 1 3 4 "<<t->data<<endl;
	else if(s2.top()!=s3.top() && s3.top()!=s4.top())
		cout<<"3 1 2 4 "<<t->data<<endl;
	else
		cout<<"4 1 2 3 "<<t->data<<endl;
	if(s1.top()!=s2.top())
	{
		while(s1.top()==s3.top() && s3.top()==s4.top())
		{
			t=s1.top();
			s1.pop();s3.pop();s4.pop();
		}
		if(s1.top()!=s4.top())
			cout<<"4 1 3 "<<t->data<<endl;
		else
			cout<<"3 1 4 "<<t->data<<endl;
	}
	else if(s1.top()!=s3.top())
	{
		while(s1.top()==s2.top() && s2.top()==s4.top())
		{
			t=s1.top();
			s1.pop();s2.pop();s4.pop();
		}
		if(s1.top()!=s2.top())
			cout<<"2 1 4 "<<t->data<<endl;
		else
			cout<<"4 1 2 "<<t->data<<endl;
	}
	else
	{
		while(s1.top()==s2.top() && s2.top()==s3.top())
		{
			t=s1.top();
			s1.pop();s2.pop();s3.pop();
		}
		if(s1.top()!=s2.top())
			cout<<"2 1 3 "<<t->data<<endl;
		else
			cout<<"3 1 2 "<<t->data<<endl;
	}
	if(s1.top()==s2.top())
	{
		while(s1.top()==s2.top())
		{
			t=s1.top();
			s1.pop();s2.pop();
		}
		cout<<"2 1 "<<t->data<<endl;
	}
	else if(s1.top()==s3.top())
	{
		while(s1.top()==s3.top())
		{
			t=s1.top();
			s1.pop();s3.pop();
		}
		cout<<"3 1 "<<t->data<<endl;
	}
	else
	{
		while(s1.top()==s4.top())
		{
			t=s1.top();
			s1.pop();s4.pop();
		}
		cout<<"4 1 "<<t->data<<endl;
	}
	return 0;
}