#include<iostream>
using namespace std;
void merge(int a[],int lm[],int rm[],int n,int l,int r)
{
	int i=0,j=0,k=0;
	for(i=0;i<n && j<l && k<r;i++)
	{
		if(lm[j]>rm[k])
		{
			a[i]=rm[k];
			k++;
		}
		else
		{
			a[i]=lm[j];
			j++;
		}
	}
	for(i;i<n && j<l;i++)
	{
		a[i]=lm[j];
		j++;
	}
	for(i;i<n && k<r;i++)
	{
		a[i]=rm[k];
		k++;
	}
}
void mergesort(int a[],int n)
{
	if(n<2)
		return;
	int lm[n/2],rm[n-n/2],i;
	for(i=0;i<n;i++)
	{
		if(i<n/2)
			lm[i]=a[i];
		else
			rm[i-(n/2)]=a[i];
	}
	mergesort(lm,n/2);
	mergesort(rm,n-(n/2));
	merge(a,lm,rm,n,n/2,n-(n/2));
}
int main()
{
	int n3;
	cout<<"enter size: ";
	cin>>n3;
	int a3[n3],b3[n3],i;
	for(i=0;i<n3;i++)
	{
		cin>>a3[i];
		b3[i]=a3[i];
	}
	mergesort(b3,n3);
	int j=n3-1;
	for(i=0;i<n3;i++)
	{
		if(a3[i]!=b3[i])
			break;
	}
	for(j;i!=n3 && j>=0;j--)
	{
		if(a3[j]!=b3[j])
			break;
	}
	if(i!=n3)
		cout<<"Sort the array from index "<<i<<" to "<<j<<endl;
	else
		cout<<"array is sorted\n";
	return 0;
}