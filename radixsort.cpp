#include<iostream>
using namespace std;
int* radix(int*,int,int);
int main()
{
	int n;
	//cout<<"enter n ";
	cin>>n;
	int *a=new int[n],i;
	//cout<<"enter elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	a=radix(a,n,1);
	//cout<<"after radix sort\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int* radix(int *a,int n,int y)
{
	int count[10]={0},count1[10]={0},i;
	for(i=0;i<n;i++)
		count[(a[i]/y)%10]++;
	if(count[0]==n)
		return a;
	int *b=new int[n];
	count1[0]=count[0];
	for(i=1;i<10;i++)
		count1[i]=count1[i-1]+count[i];
	for(i=n-1;i>=0;i--)
	{
		b[count1[(a[i]/y)%10]-1]=a[i];
		count1[(a[i]/y)%10]--;
	}
//	for(i=0;i<n;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	y*=10;
	return radix(b,n,y);
}
