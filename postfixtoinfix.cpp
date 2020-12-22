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
		if(s[i]>='0'&&s[i]<='9')
		{
			string a(1,s[i]);
			st.push(a);
			//cout<<s[i]<<" "<<s[i]+""<<endl;
		}
		else
		{
			string a=st.top();
			st.pop();
			//cout<<a<<endl;
			string b=st.top();
			st.pop();
			//cout<<b<<endl;
			st.push('('+b+s[i]+a+')');
		}
	}
	cout<<st.top()<<endl;
	return 0;
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