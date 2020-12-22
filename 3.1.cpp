#include<iostream>
#include<string>
using namespace std;
int fib(int a[],int x)
{
	if(a[x]!=0)
		return a[x];
	a[x]=fib(a,x-1)+fib(a,x-2);
	return a[x];
}
int calfib(string s,int a[])
{
	int n=s.size(),x=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
			x+=fib(a,n-i);
	}
	return x;
}
void findfeb(int n,char out[],int a[])
{
	if(n==0)
		return;
	int min=n,ind;
	for(int i=10;i>0;i--)
	{
		if(min>(n-fib(a,i)) && n>=fib(a,i) && out[i-1]=='0')
		{
			min=n-fib(a,i);
			ind=i;
		}
	}
	out[ind-1]='1';
	findfeb(min,out,a);
}
int main()
{
	string s,s1;
	cin>>s;
	//cout<<"x";
	s1=s;
	int a[100]={0};
	a[1]=1;a[2]=1;
	//cout<<"x";
	int n=calfib(s,a);
	char out[]="0000000000";
	findfeb(n+1,out,a);
	cout<<n+1<<"=";
	int i=9;
	while(out[i]!='1')
		i--;
	for(i;i>=0;i--)
		cout<<out[i];
	cout<<endl;
	char out1[]="0000000000";
	findfeb(n-1,out1,a);
	cout<<n-1<<"=";
	i=9;
	while(out1[i]!='1')
		i--;
	for(i;i>=0;i--)
		cout<<out1[i];
	cout<<endl;
	return 0;
}