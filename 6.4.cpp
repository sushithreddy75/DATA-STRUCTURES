#include<iostream>
using namespace std;
int main()
{
	int n,b;
	cin>>n>>b;
	int a[n],c[n-b+1],i,m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>m && i<b)
			m=a[i];
	}
	c[0]=m;
	for(int j=1;j<n-b+1;j++)
	{
		m=0;
		for(i=j;i<j+b;i++)
		{
			if(a[i]>m)
				m=a[i];
		}
		c[j]=m;
	}
	for(i=0;i<n-b+1;i++)
		cout<<c[i]<<" ";
	cout<<endl;
}