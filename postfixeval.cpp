#include<iostream>
using namespace std;
struct stack
{
	int t;
	int a[100];
	int top();
	void push(int);
	void pop();
};
int main()
{
	string s;
	cin>>s;
	stack st;
	st.t=-1;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='+')
		{
			int x=st.top();
			st.pop();
			int y=st.top();
			st.pop();
			st.push(x+y);
		}
		else if(s[i]=='-')
		{
			int x=st.top();
			st.pop();
			int y=st.top();
			st.pop();
			st.push(y-x);
		}
		else if(s[i]=='*')
		{
			int x=st.top();
			st.pop();
			int y=st.top();
			st.pop();
			st.push(x*y);
		}
		else if(s[i]=='/')
		{
			int x=st.top();
			st.pop();
			int y=st.top();
			st.pop();
			st.push(y/x);
		}
		else
			st.push((s[i]-48));
	}
	cout<<st.top()<<endl;
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