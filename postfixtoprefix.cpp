#include<iostream>
using namespace std;
struct stackstr
{
	int t;
	string a[100];
	string top();
	void push(string);
	void pop();
	bool empty();
	int size();
};
int main()
{
	string s;
	cin>>s;
	stackstr st;
	st.t=-1;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0' && s[i]<='9')
			st.push(string(1,s[i]));
		else
		{
			string a=st.top();
			st.pop();
			string b=st.top();
			st.pop();
			st.push(s[i]+b+a);
		}
	}
	cout<<st.top()<<endl;
}
string stackstr::top()
{
	return a[t];
}
void stackstr::push(string x)
{
	t++;
	a[t]=x;
}
void stackstr::pop()
{
	t--;
}
bool stackstr::empty()
{
	if(t==-1)
		return true;
	return false;
}
int stackstr::size()
{
	return t+1;
}