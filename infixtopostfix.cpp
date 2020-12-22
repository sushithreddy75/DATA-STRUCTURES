#include<iostream>
using namespace std;
struct stack
{
	int t;
	char a[100];
	char top();
	void push(int);
	void pop();
	bool empty();
};
int main()
{
	string a;
	cin>>a;
	stack s;
	s.t=-1;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='(')
			s.push(a[i]);
		else if(a[i]==')')
		{
			while(s.top()!='(')
			{
				cout<<s.top();
				s.pop();
			}
			s.pop();
			continue;
		}
		else if(a[i]=='+'||a[i]=='-')
		{
			if(!s.empty() && s.top()!='(')
			{
				while(!s.empty()){
				cout<<s.top();
				s.pop();}
			}
			s.push(a[i]);
		}
		else if(a[i]=='*'||a[i]=='/')
		{
			if(!s.empty())
			{
				if(s.top()=='*'||s.top()=='/')
				{
					cout<<s.top();
					s.pop();
				}
			}
			s.push(a[i]);
		}
		else
			cout<<a[i];
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
	cout<<endl;
	return 0;
}
char stack::top()
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