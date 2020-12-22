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
};
int main()
{
	stack1 s;
	s.t=-1;
	string b;
	cin>>b;
	string a="";
	for(int i=b.size()-1;i>=0;i--)
	{
		if(b[i]=='(')
			a+=')';
		else if(b[i]==')')
			a+='(';
		else
			a+=b[i];
	}
	string c="";
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='(')
			s.push(a[i]);
		else if(a[i]==')')
		{
			while(s.top()!='(')
			{
				c+=s.top();
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
				c+=s.top();
				s.pop();}
			}
			s.push(a[i]);
		}
		else if(a[i]=='*'||a[i]=='/')
		{
			if(!s.empty())
			{
				if(!s.empty() && s.top()!='(')
				{
					{
				c+=s.top();
				s.pop();}
				}
			}
			s.push(a[i]);
		}
		else
			c+=a[i];
	}
	while(!s.empty())
	{
		c+=s.top();
		s.pop();
	}
	for(int i=c.size()-1;i>=0;i--)
		cout<<c[i];
	cout<<endl;
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