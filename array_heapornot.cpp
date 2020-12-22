#include<iostream>
using namespace std;
bool check(int a[],int i,int n)
{
	if(i>n-1 || 2*i+1>n-1)
		return true;
	if(a[i]>a[2*i+1])
		return false;
	if(2*i+2<n-1 && a[i]>a[2*i+2])
		return false;
	return (check(a,2*i+1,n)&&check(a,2*i+2,n));
}
int main()
{
	int a[100],i=0;
	while(1)
	{
		cin>>a[i];
		if(a[i]==-1)
			break;
		i++;
	}
	cout<<check(a,0,i)<<endl;
}