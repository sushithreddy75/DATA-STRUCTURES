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
	cout<<"enter expression\n";
	stack1 st;
	st.t=-1;
	int flag=1,i;
	string s;
	cin>>s;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%')
		{
			if(i==0)
			{
				flag=0;
				break;
			}
			else if(s[i-1]=='('||s[i+1]=='\0'||s[i+1]==')'||s[i-1]=='['||s[i+1]==']'||s[i+1]=='}'||s[i-1]=='{')
			{
				flag=0;
				break;
			}
			else if(s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='%')
			{
				flag=0;
				break;
			}
		}
		else if(s[i]=='('||s[i]=='['||s[i]=='{')
			st.push(s[i]);
		else if((s[i]==')'||s[i]==']'||s[i]=='}') && st.empty())
		{
			flag=0;
			break;
		}
		else if(s[i]==')')
		{
			if(st.top()!='(')
			{
				flag=0;
				break;
			}
			st.pop();
		}
		else if(s[i]=='}')
		{
			if(st.top()!='{')
			{
				flag=0;
				break;
			}
			st.pop();
		}
		else if(s[i]==']')
		{
			if(st.top()!='[')
			{
				flag=0;
				break;
			}
			st.pop();
		}
		else
		{
			if((s[i+1]>='0'&&s[i+1]<='9')||s[i+1]=='('||s[i-1]==')'||s[i-1]=='['||s[i+1]==']'||s[i+1]=='}'||s[i-1]=='{')
			{
				flag=0;
				break;
			}
		}
	}
	if(!st.empty())
	flag=0;
	if(flag)
		cout<<"balanced\n";
	else
		cout<<"not-balanced\n";
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