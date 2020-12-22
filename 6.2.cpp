#include<iostream>
#include<cmath>
using namespace std;
int count(string,int);
int main()
{
	cout<<"enter string: ";
	string s;
	cin>>s;
	cout<<count(s,0)<<endl;
}
int count(string s,int i)
{
	int c=0,x=0;
	for(i;s[i]!='0';i++)
	{
		if(s[i]=='(' && s[i+1]=='(')
			return 2*count(s,i+1);
		if(s[i]==')' && s[i-1]=='(')
		{
			c++;
			if(s[i+1]==')')
				return c;
			if(s[i+1]=='(')
				return c+count(s,i+1);
			else if(s[i+1]=='\0')
				return c;
		}
	}
	//return pow(2,x)*(c+count(s,i));
}