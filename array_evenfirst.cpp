#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"ENTER SIZE OF ARRAY: ";
	cin>>n;
	int a[n],i;
	cout<<"ENTER ELEMENTS OF THE ARRAY\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	int *f=a,*l=a+n-1;
	while(f<l)
	{
		if(*f%2==1 && *l%2==0)
		{
			int t=*f;
			*f=*l;
			*l=t;
			f++;
			l--;
		}
		else if(*f%2==1 && *l%2==1)
			l--;
		else if(*f%2==0 && *l%2==0)
			f++;
		else
		{
			l--;
			f++;
		}
	}
	cout<<"ARRAY AFTER ARRANGING\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}