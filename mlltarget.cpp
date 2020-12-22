#include<iostream>
using namespace std;
struct mlnode
{
	int data;
	int count;
	mlnode **nextll;
};
typedef mlnode* mlptr;
struct stack
{
	int t;
	mlptr* a[100];
	mlptr* top();
	void push(mlptr*);
	void pop();
	bool empty();
};
mlptr create(int x,int n)
{
	mlptr t=new(mlnode);
	t->data=x;
	t->count=n;
	t->nextll=NULL;
	if(n!=0)
	{
		t->nextll=new mlptr[n];
	}
	return t;
}
void construct(mlptr &h)
{
	stack s;
	s.t=-1;
	s.push(&h);
	while(!s.empty())
	{
		int x,y;
		cin>>x;
		if(x==-1)
			break;
		cin>>y;
		mlptr t=create(x,y);
		mlptr *t1=s.top();s.pop();
		*(t1)=t;
		for(int i=y-1;i>=0;i--)
			s.push(&(t->nextll[i]));
	}
}
void stprint(stack s)
{
	if(s.empty())
		return;
	mlptr *t=s.top();
	s.pop();
	stprint(s);
	cout<<(*t)->data<<" ";
}
void print(mlptr h,stack &s,int x,int y)
{
	if(h==NULL)
		return;
	if(!s.empty())
		s.push(&h);
	if(h->data==x && s.empty())
		s.push(&h);
	if(h->data==y)
	{
		stprint(s);
		return;
	}
	for(int i=0;i<h->count;i++)
		print(h->nextll[i],s,x,y);
	s.pop();
}
int main()
{
	mlptr h=NULL;
	construct(h);
	stack s;s.t=-1;
	int x,y;cin>>x>>y;
	print(h,s,x,y);
	cout<<endl;
	cin>>x>>y;
	print(h,s,x,y);
	cout<<endl;
}
mlptr* stack::top()
{
	return a[t];
}
void stack::push(mlptr* x)
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