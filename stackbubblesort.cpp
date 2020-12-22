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
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	stack s1,s2;
	s1.t=-1;s2.t=-1;
	int a[n],i;
	for(i=0;i<n;i++)
		cin>>a[i];
	s1.push(a[0]);
	for(i=1;i<n;i++)
	{
		if(s1.top()>a[i])
		{
			int x=s1.top();
			s1.pop();
			s1.push(a[i]);
			s1.push(x);
		}
		else
		{
			s1.push(a[i]);
		}
	}
	a[n-1]=s1.top();
	s1.pop();
	for(i=n-2;i>=0;i--)
	{
		while(s1.size()!=1)
		{
			s2.push(s1.top());
			s1.pop();
		}
		while(!s2.empty())
		{
			if(s1.top()>s2.top())
			{
				int x=s1.top();
				s1.pop();
				s1.push(s2.top());
				s2.pop();
				s1.push(x);
			}
			else
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		a[i]=s1.top();
		s1.pop();
	}
	cout<<"sorted array\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
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