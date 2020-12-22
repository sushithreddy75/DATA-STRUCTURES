#include<iostream>
using namespace std;
struct bstnode
{
    bstnode* lchild;
    int data;
    bstnode *rchild;
};
struct stack
{
	int t;
	int a[100];
	int top();
	void push(int);
	void pop();
	bool empty();
	int size();
};
typedef bstnode* bstptr;
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
int stack::top()
{
	return a[t];
}
void stack::push(int x)
{
	t++;
	a[t]=x;
}
void stack::pop()
{
	t--;
}
bool stack::empty()
{
	if(t==-1)
		return true;
	return false;
}
int stack::size()
{
	return t+1;
}
void printstack(stack s)
{
	if(s.empty())
		return;
	int t=s.top();s.pop();
	printstack(s);
	cout<<t<<" ";
}
void printpath(bstptr t,stack s)
{
	if(t->lchild==NULL && t->rchild==NULL)
	{
		s.push(t->data);
		printstack(s);cout<<endl;
		return;
	}
	s.push(t->data);
	if(t->lchild)
	printpath(t->lchild,s);
	if(t->rchild)
	printpath(t->rchild,s);
}
void printleft(bstptr t)
{
	if(t==NULL)
		return;
	cout<<t->data<<" ";
	if(t->lchild)
		return printleft(t->lchild);
	printleft(t->rchild);
}
void printright(bstptr t)
{
	if(t==NULL)
		return;
	cout<<t->data<<" ";
	if(t->rchild)
		return printright(t->rchild);
	printright(t->lchild);
}
void maxsum(bstptr t,stack s,stack &s1,int sum,int &sum1)
{
	if(t->lchild==NULL && t->rchild==NULL)
	{
		s.push(t->data);sum+=t->data;
		if(sum>sum1)
		{
			s1=s;
			sum1=sum;
		}
		return;
	}
	s.push(t->data);sum+=t->data;
	if(t->lchild)
	maxsum(t->lchild,s,s1,sum,sum1);
	if(t->rchild)
	maxsum(t->rchild,s,s1,sum,sum1);
}
void minsum(bstptr t,stack s,stack &s1,int sum,int &sum1)
{
	if(t->lchild==NULL && t->rchild==NULL)
	{
		s.push(t->data);sum+=t->data;
		if(sum<sum1)
		{
			s1=s;
			sum1=sum;
		}
		return;
	}
	s.push(t->data);sum+=t->data;
	if(t->lchild)
	minsum(t->lchild,s,s1,sum,sum1);
	if(t->rchild)
	minsum(t->rchild,s,s1,sum,sum1);
}
void sumpath(int x,int sum,bstptr t,stack s)
{
	if(t->lchild==NULL && t->rchild==NULL)
	{
		x+=t->data;s.push(t->data);
		if(x==sum)
		{
			printstack(s);
			cout<<endl;
		}
		return;
	}
	x+=t->data;s.push(t->data);
	if(t->lchild)
		sumpath(x,sum,t->lchild,s);
	if(t->rchild)
		sumpath(x,sum,t->rchild,s);
}
void maxeven(bstptr t,int x,int &c,stack s,stack &s1)
{
	if(t->lchild==NULL && t->rchild==NULL)
	{
		s.push(t->data);if(t->data%2==0)x++;
		if(x>c)
		{
			s1=s;
			c=x;
		}
		return;
	}
	s.push(t->data);if(t->data%2==0)x++;
	if(t->lchild)
	maxeven(t->lchild,x,c,s,s1);
	if(t->rchild)
	maxeven(t->rchild,x,c,s,s1);
}
void maxodd(bstptr t,int x,int &c,stack s,stack &s1)
{
	if(t->lchild==NULL && t->rchild==NULL)
	{
		s.push(t->data);if(t->data%2)x++;
		if(x>c)
		{
			s1=s;
			c=x;
		}
		return;
	}
	s.push(t->data);if(t->data%2)x++;
	if(t->lchild)
	maxodd(t->lchild,x,c,s,s1);
	if(t->rchild)
	maxodd(t->rchild,x,c,s,s1);
}
int main()
{
	bstptr T=NULL;
	while(1)
	{
		int n;cin>>n;
		if(n==-1)break;
		insert(T,n);
	}
	stack s;s.t=-1;
	printpath(T,s);
	printleft(T);cout<<endl;
	printright(T);cout<<endl;
	int sum=0,sum1=0;
	stack s1;s1.t=-1;
	sum=0;sum1=0;
	maxsum(T,s,s1,sum,sum1);
	printstack(s1);cout<<endl;
	s1.t=-1;
	minsum(T,s,s1,sum,sum1);
	printstack(s1);cout<<endl;
	sumpath(0,22,T,s);
	int x=0,c=0;s1.t=-1;
	maxeven(T,x,c,s,s1);
	printstack(s1);cout<<endl;
	x=0;c=0;s1.t=-1;
	maxodd(T,x,c,s,s1);
	printstack(s1);cout<<endl;
}