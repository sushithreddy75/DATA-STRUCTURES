#include <iostream>
using namespace std;
void merge(int a[],int l,int m,int h)
{
	int x=(m-l+1),y=(h-m),b[h-l+1];
	for(int i=l;i<=m;i++)
	b[i-l]=a[i];
	for(int i=(m+1);i<=h;i++)
	b[i-l]=a[i];
	int i=0,j=m+1-l,k=l;
	while(i<x && j<(h-l+1))
	{
		if (b[i] <= b[j]) { 
            a[k] = b[i]; 
            i++; 
        } 
        else { 
            a[k] = b[j]; 
            j++; 
        } 
        k++; 
	}
	while(i<x)
	{
		a[k]=b[i];
		i++;
		k++;
	}
	while(j<(h-l+1))
	{
		a[k]=b[j];
		j++;
		k++;
	}
	for(int i=l;i<(h+1);i++)
	cout<<a[i]<<" ";
	cout<<endl;
}
void mergesort(int a[],int l,int h)
{
	if(l<h)
	{
		int b[h-l+1],k=0;
		for(int i=l;i<(h+1);i++)
		{
			if(i%2==0)
			{
				b[k]=a[i];
				k++;
			}
		}
		for(int i=l;i<(h+1);i++)
		{
			if(i%2!=0)
			{
				b[k]=a[i];
				k++;
			}
		}
		for(int i=l;i<(h+1);i++)
		{
			a[i]=b[i-l];
		}
		int m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
		
	}
}
int main()
{
	int n3;
	cin>>n3;
	int a[n3];
	for(int i=0;i<n3;i++)
	cin>>a[i];
	mergesort(a,0,n3-1);
	for(int i=0;i<n3;i++)
	cout<<a[i]<<" ";
}