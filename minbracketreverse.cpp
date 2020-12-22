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
int main()
{
	string s;
	cin>>s;
	int i;
	stack1 st;
	st.t=-1;
	int c=0,n=s.size(),b=0;
	if(n%2==1)
		{cout<<"not possible\n";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(st.empty())
		{
			if(s[i]==')')
			{
				s[i]='(';
				c++;
				//b++;
			}
			b++;
			st.push(s[i]);
		}
		else if(s[i]=='(' && b==n/2)
		{
			c++;
			st.pop();
			s[i]=')';
		}
		else if(s[i]==')')
			st.pop();
		else if(s[i]=='(')
		{
			st.push('(');
			b++;
		}
	}
	cout<<c<<endl;
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