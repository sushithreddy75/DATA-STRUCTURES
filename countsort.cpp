#include<iostream>
using namespace std;
int main()
{
	cout<<"enter n ";
	int n,i;cin>>n;
	int a[n],max=0;
	cout<<"enter elements\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
			max=a[i];
	}
	int count[max+1]={0},count1[max+1]={0},b[n];
	for(i=0;i<n;i++)
		count[a[i]]++;
	for(i=1;i<=max;i++)
		count1[i]=count[i]+count1[i-1];
	for(i=0;i<n;i++)
	{
		b[count1[a[i]]-1]=a[i];
		count1[a[i]]--;
	}
	cout<<"count sorted array\n";
	for(i=0;i<n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}