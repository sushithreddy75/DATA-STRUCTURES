#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"ENTER SIZE OF THE ARRAY: ";
	cin>>n;
	int a[n],x,i;
	int *l=a,*r=a+n-1;
	while(l<=r)
	{
		cout<<"ENTER 0 TO ADD AT FRONT 1 TO ADD AT LAST ";
		cin>>x;
		cout<<"ENTER ELEMENT: ";
		if(x==0)
		{
			cin>>*l;
			l++;
		}
		else
		{
			cin>>*r;
			r--;
		}
	}
	cout<<"ELEMENTS OF ARRAY\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}