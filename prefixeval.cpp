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
	string s;
	cin>>s;
	int i=s.size();
	stack st;
	st.t=-1;
	while(i>=0)
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
			st.push(x-y);
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
			st.push(x/y);
		}
		else if(s[i]=='%')
		{
			int x=st.top();
			st.pop();
			int y=st.top();
			st.pop();
			st.push(x%y);
		}
		else
			st.push(s[i]-'0');
		i--;
	}
	cout<<"value of infix evaluation: "<<st.top()<<endl;
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