#include<iostream>
using namespace std;
void conv(string s,string a[],int i,int j);
int main()
{
	string s,a[100];
	cout<<"enter prefix expression: ";
	cin>>s;
	conv(s,a,s.size()-1,0);
	return 0;
}
void conv(string s,string a[],int i,int j)
{
	if(i==-1)
	{
		cout<<a[0]<<endl;
		return;
	}
	if(s[i]>='0' && s[i]<='9')
	{
		a[j]=s[i];
		conv(s,a,i-1,j+1);
	}
	else
	{
		a[j-2]=a[j-1]+a[j-2]+s[i];
		conv(s,a,i-1,j-1);
	}
}