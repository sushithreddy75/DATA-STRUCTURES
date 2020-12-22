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
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='*')
		{
			if(s[i+1]!='(')
			{
				int x=st.top();
				st.pop();
				x*=s[i+1]-'0';
				st.push(x);
				i++;
			}
		}
		else if(s[i]=='/')
		{
			if(s[i+1]!='(')
			{
				int x=st.top();
				st.pop();
				x/=(s[i+1]-'0');
				st.push(x);
				i++;
			}
		}
		else if(s[i]==')')
		{
			int j=i-1,b=0;
			while(1)
			{
				if(s[j]=='(' && b==0)
				{
					if(j>0&&(s[j-1]=='*'||s[j-1]=='/'))
					{
						int x=st.top();
					    st.pop();
					    int y=st.top();
					    st.pop();
					    if(s[j-1]=='*')
					    	st.push(y*x);
					    else
					    	st.push(y/x);
					}
					break;
				}
				if(s[j]=='+' && b==0)
				{
					int x=st.top();
					st.pop();
					int y=st.top();
					st.pop();
					st.push(y+x);
				}
				else if(s[j]=='-' && b==0)
				{
					int x=st.top();
					st.pop();
					int y=st.top();
					st.pop();
					st.push(y-x);
				}
				else if(s[j]==')')
					b++;
				else if(s[j]=='(')
					b--;
				j--;
			}
		}
		else if(s[i]>='0'&&s[i]<='9')
			st.push(s[i]-'0');
	}
	for(i=s.size()-1;i>=0;i--)
	{
		if(s[i]==')')
		{
			//cout<<"x";
			int b=1;
			while(1)
			{
				if(s[i]=='('&&b==0)
					break;
				if(s[i]==')')
					b--;
				if(s[i]=='(')
					b++;
				i--;
			}
		}
		/*else if(s[i]=='*' && s[i+1]=='(')
		{
			int x=st.top();st.pop();
			int y=st.top();st.pop();
			st.push(y*x);
		}
		else if(s[i]=='/' && s[i+1]=='(')
		{
			int x=st.top();st.pop();
			int y=st.top();st.pop();
			st.push(y/x);
		}*/
		else if(s[i]=='+')
		{
			int x=st.top();st.pop();
			int y=st.top();st.pop();
			st.push(y+x);
		}
		else if(s[i]=='-')
		{
			int x=st.top();st.pop();
			int y=st.top();st.pop();
			st.push(y-x);
		}
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