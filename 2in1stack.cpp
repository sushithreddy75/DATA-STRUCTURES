#include<iostream>
using namespace std;
struct stack
{
	int t,t1;
	int a[100];
	int top();
	void push(int);
	void pop();
	int top1();
	void push1(int);
	void pop1();
};
int main()
{
	stack s;
	s.t=-1;
	s.t1=100;
	int x;
	do
	{
		cout<<"enter stack to perform operation || 0 to stop ";
		cin>>x;
		if(x==1)
		{
			cout<<"enter \n1 for top\n2 for push\n3 to pop\n";
			int y;cin>>y;
			if(y==1)
				cout<<s.top()<<endl;
			else if(y==3)
				s.pop();
			else
			{
				cout<<"enter value to push ";
				cin>>y;
				s.push(y);
			}
		}
		else if(x==2)
		{
			cout<<"enter \n1 for top\n2 for push\n3 to pop\n";
			int y;cin>>y;
			if(y==1)
				cout<<s.top1()<<endl;
			else if(y==3)
				s.pop1();
			else
			{
				cout<<"enter value to push ";
				cin>>y;
				s.push1(y);
			}
		}
	}while(x!=0);
	return 0;
}
int stack::top()
{
	return a[t];
}
void stack::push(int x)
{
	if(t1-t==1)
	{
		cout<<"stack is full\n";
		return;
	}
	t++;
	a[t]=x;
}
void stack::pop()
{
	if(t==0)
		cout<<"stack is empty\n";
	t--;
}
int stack::top1()
{
	return a[t1];
}
void stack::push1(int x)
{
	if(t1-t==1)
	{
		cout<<"stack is full\n";
		return;
	}
	t1--;
	a[t1]=x;
}
void stack::pop1()
{
	if(t1==100)
		cout<<"stack is empty\n";
	else
	t++;
}