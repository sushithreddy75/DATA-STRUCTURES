#include<iostream>
using namespace std;
union u
{
	int x;
	char c;
};
int main()
{
	int n,i;
	cout<<"ENTER NO OF ELEMENTS IN THE ARRAY: ";
	cin>>n;
	union u a[n];
	int tag[10];
	for(i=0;i<n;i++)
	{
		cout<<"ENTER 1 TO ENTER INTEGER 0 FOR CHARACTER: ";
		cin>>tag[i];
		if(tag[i]==1)
		{
			cout<<"ENTER INTEGER: ";
			cin>>a[i].x;
		}
		else
		{
			cout<<"ENTER CHARACTER: ";
			cin>>a[i].c;
		}
	}
	cout<<"ELEMENTS OF UNION ARRAY\n";
	for(i=0;i<n;i++)
	{
		if(tag[i]==1)
			cout<<a[i].x<<" ";
		else
			cout<<a[i].c<<" ";
	}
	cout<<endl;
	return 0;
}