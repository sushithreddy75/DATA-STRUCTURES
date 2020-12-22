#include<iostream>
using namespace std;
int main()
{
	int n,flag=0;
	cout<<"enter size: ";
	cin>>n;
	int a[n],i,j,k;
	cout<<"enter elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;flag!=1 && i<n-2;i++)
	{
		for(j=i+1;flag!=1 && j<n-1;j++)
		{
			for(k=j+1;flag!=1 && a[j]>a[i] && k<n;k++)
			{
				if(a[k]>a[j])
			{		cout<<"("<<a[i]<<","<<a[j]<<","<<a[k]<<")\n";
			flag=1;
			}
			}
		}
	}
	return 0;
}