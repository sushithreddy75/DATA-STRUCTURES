#include<iostream>
using namespace std;
struct stack1
{
	int t;
	char a[100];
	char top();
	void push(char);
	void pop();
	bool empty();
	int size();
};
void push1(stack1 *s,char x);
void rev(stack1 *s);
//stack s;
int main()
{
	stack1 *s=new(stack1);
	s->t=-1;
	int i,n;
	cout<<"enter no of elements to push: ";
	cin>>n;
	cout<<"enter elements\n";
	for(i=0;i<n;i++)
	{
		char x;
		cin>>x;
		s->push(x);
	}
	rev(s);
	cout<<"after reversing\n";
	while(!s->empty())
	{
		cout<<s->top()<<" ";
		s->pop();
	}
	cout<<endl;
}
void rev(stack1 *s)
{
	if(!s->empty())
	{
		char c=s->top();
		s->pop();
		rev(s);
		push1(s,c);
	}
}
void push1(stack1 *s,char x)
{
	if(!s->empty())
	{
		char c=s->top();
		s->pop();
		push1(s,x);
		s->push(c);
	}
	else
		s->push(x);
}
char stack1::top()
{
	return a[t];
}
void stack1::push(char x)
{
	t++;
	a[t]=x;
}
void stack1::pop()
{
	t--;
}
bool stack1::empty()
{
	if(t==-1)
		return true;
	return false;
}
int stack1::size()
{
	return t+1;
}