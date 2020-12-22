#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
int main()
{
	int m4,n4;
	cout<<"enter sizes\n";
	cin>>m4>>n4;
	int x4[m4],y4[n4],i;
	cout<<"enter values of x";
	for(i=0;i<m4;i++)
		cin>>x4[i];
	cout<<"enter values of y";
	for(i=0;i<n4;i++)
		cin>>y4[i];
	i=0;
	while(i<m4)
	{
		if(x4[i]>y4[0])
			swap(x4+i,y4);
		int j=0;
		while(j<n4-1)
		{
			if(y4[j]>y4[j+1])
				swap(y4+j,y4+j+1);
			j++;
		}
		i++;
	}
	cout<<"x after\n";
	for(i=0;i<m4;i++)
		cout<<x4[i]<<" ";
	cout<<"\ny after\n";
	for(i=0;i<n4;i++)
		cout<<y4[i]<<" ";
	cout<<endl;
}