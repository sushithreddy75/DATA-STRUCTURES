#include<iostream>
using namespace std;
int main()
{
	int n7;
	cout<<"enter size: ";
	cin>>n7;
	int a7[n7],i,j=-1,k,t;
	cout<<"enter elements\n";
	for(i=0;i<n7;i++)
		cin>>a7[i];
	for(i=1;i<n7;i++)
	{
		if(a7[i]<a7[i-1])
		{j=i-1;break;}
	}
	if(j!=-1)
	{
		for(i=n7-1;i>0;i--)
		{
			if(a7[i]<a7[i-1])
			{
				k=i;
				break;
			}
		}
	}
	if(j!=-1)
	{
		t=a7[j];
		a7[j]=a7[k];
		a7[k]=t;
	}
	cout<<"sorted array\n";
	for(i=0;i<n7;i++)
		cout<<a7[i]<<" ";
	cout<<endl;
	return 0;
}