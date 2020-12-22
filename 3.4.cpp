#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void twopivotsort(int low,int high,int a[])
{
	if(low>=high)
		return;
	if(a[low]>a[high])
		swap(a+low,a+high);
	int l=low+1,l1=low+1,h=high-1,p1=a[low],p2=a[high];
	while(l<=h)
	{
		if(a[l]<p1)
		{
			swap(a+l,a+l1);
			l1++;l++;
			continue;
		}
		//if(a[l]>p1 && a[l]<p2)
		if(a[l]>=p2)
		{
			while(a[h]>p2 && h>l)
				h--;
			//if(h<=l)
			//	h=l;
			//swap(a+h+1,a+l);
			swap(a+h,a+l);
			if(a[l]<p1)
			{
				swap(a+l,a+l1);
				l1++;
			}
			h--;
	    }
	    l++;
	}
	//h--;
	l1--;
	swap(a+low,a+l1);
	h++;
	swap(a+high,a+h);
	twopivotsort(low,l1-1,a);
	twopivotsort(l1+1,h-1,a);
	twopivotsort(h+1,high,a);
}
int main()
{
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	int a[n],i;
	cout<<"enter elements of array\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	twopivotsort(0,n-1,a);
	cout<<"after sorting\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}