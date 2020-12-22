#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void del(int a[],int i,int n)
{
	if(i>=n-1)
		return;
	if(2*i+1<n-1)
	{
		int j;
		if(a[i]>a[2*i+1])
		{
			swap(a+i,a+2*i+1);
			j=2*i+1;
		}
		else if(2*i+2<n-1 && a[i]>a[2*i+2])
		{
			swap(a+i,a+2*i+2);
			j=2*i+2;
		}
		else
			return;
		if(j==2*i+1 && j+1<n-1 && a[j+1]<a[i])
			del(a,i,n);
		return del(a,j,n);
	}
}
void heapsort(int a[],int n)
{
	if(n<=0)
		return;
	cout<<a[0]<<" ";
	a[0]=a[n-1];
	del(a,0,n);
	heapsort(a,n-1);
}
void convert(int a[],int i)
{
	if(i<=0)
		return;
	if(a[i]<a[(i-1)/2])
	{
		swap(a+i,a+(i-1)/2);
		return convert(a,(i-1)/2);
	}
}
int main()
{
	int a[100],i=0;
	while(1)
	{
		cin>>a[i];
		if(a[i]==-1)
			break;
		convert(a,i);
		i++;
	}
	heapsort(a,i);
	cout<<endl;
}