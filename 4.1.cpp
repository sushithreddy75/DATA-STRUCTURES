#include<iostream>
using namespace std;
int main()
{
	int n1,count[100]={0},max=0;
	cout<<"enter size ";
	cin>>n1;
	int a1[n1],i;
	for(i=0;i<n1;i++)
	{
		cin>>a1[i];
		count[a1[i]]++;
		if(a1[i]>max)
			max=a1[i];
	}
	int j=0;
	for(i=1;i<=max;i++)
	{
		while(count[i]--)
			a1[j++]=i;
	}
	cout<<"sorted array\n";
	for(i=0;i<n1;i++)
		cout<<a1[i]<<" ";
	cout<<endl;
}