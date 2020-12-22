#include<iostream>
using namespace std;
void mergesort(int l,int r,int a[],int b[])
{
	if(l==r)
		return;
	int i=l;
	/*for(i=0;i<(r-l+1)/2;i++)
		b[l+i]=a[l+2*i];
	for(i=0;i<(r-l+1)/2;i++)
		b[(r-l+1)/2+i]=a[l+2*i+1];*/
	int k=l;
	for(i;i<=r;i+=2,k++)
		b[k]=a[i];
	for(i=l+1;i<=r;i+=2,k++)
		b[k]=a[i];
	for(i=l;i<=r;i++)
	{	a[i]=b[i];cout<<a[i]<<" ";}
cout<<endl;
	
	mergesort(l,(r+l-1)/2,a,b);
	mergesort((r+l+1)/2,r,a,b);
	i=l;int j=(l+r+1)/2;k=l;
	while(i<(l+r+1)/2 && j<=r)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<(l+r+1)/2)
	{
		b[k]=a[i];
		i++;k++;
	}
	while(j<=r)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=l;i<=r;i++)
		a[i]=b[i];
}
int main()
{
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	int a[n],b[n],i;
	cout<<"enter elements of array\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	mergesort(0,n-1,a,b);
	cout<<"after sorting\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}