#include<iostream>
using namespace std;
union u
{
	int x;
	char c;
};
int main()
{
	int n,i,j=0;
	cout<<"ENTER SIZE OF ARRAY: ";
	cin>>n;
	union u a[n];
	union u *l=a,*r=a+n-1;
	while(l<=r)
	{
		cout<<"ENTER 0 TO ENTER INTEGER 1 FOR CHARACTER ";
		cin>>i;
		if(i==1)
		{
			cout<<"ENTER CHARACTER: ";
			cin>>r->c;
			r--;
		}
		else
		{
			cout<<"ENTER INTEGER: ";
			cin>>l->x;
			l++;
			j++;
		}
	}
	cout<<"DATA IN ARRAY\n";
	for(i=0;i<j;i++)
		cout<<a[i].x<<" ";
	for(j;j<n;j++)
		cout<<a[j].c<<" ";
	cout<<endl;
	return 0;
}