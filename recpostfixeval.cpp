#include<iostream>
using namespace std;
void eval(int a[],string s,int i,int j)
{
	if(i==s.size())
	{
		cout<<a[0]<<endl;
		return;
	}
	if(s[i]>='0'&&s[i]<='9')
	{
		a[j]=s[i]-'0';
		eval(a,s,i+1,j+1);
	}
	else
	{
		if(s[i]=='*')
			a[j-2]=a[j-2]*a[j-1];
		if(s[i]=='/')
			a[i-2]=a[j-1]/a[j-2];
		if(s[i]=='+')
			a[j-2]=a[j-2]+a[j-1];
		if(s[i]=='-')
			a[j-2]=a[j-1]-a[j-2];
		eval(a,s,i+1,j-1);
	}
}
int main()
{
	string s;
	cin>>s;
	int a[100];
	eval(a,s,0,0);
	return 0;
}