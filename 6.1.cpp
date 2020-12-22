#include<iostream>
using namespace std;
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
int main()
{
	stack s1,s2;
	s1.t=-1,s2.t=-1;
	int n;
	cout<<"enter n: ";
	cin>>n;
	int i,a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	s1.push(a[0]);
	for(i=1;i<n;i++)
	{
		int x=s1.top();
		if(x<a[i])
		{
			s1.pop();
			s1.push(a[i]);
			s1.push(x);
		}
		else
			s1.push(a[i]);
	}
	a[0]=s1.top();
	s1.pop();
	i=1;
	while(i<n)
	{
		s2.push(s1.top());
		s1.pop();
		while(!s1.empty())
		{
			int x=s2.top();
			if(x<s1.top())
			{
				s2.pop();
				s2.push(s1.top());
				s2.push(x);
				s1.pop();
			}
			else
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		a[i]=s2.top();
		s2.pop();
		i++;
		if(i<n)
		{
			s1.push(s2.top());
		s2.pop();
		while(!s2.empty())
		{
			int x=s1.top();
			if(x<s2.top())
			{
				s1.pop();
				s1.push(s2.top());
				s1.push(x);
				s2.pop();
			}
			else
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		a[i]=s1.top();
		s1.pop();
		i++;
		}
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
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