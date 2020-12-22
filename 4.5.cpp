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
	int n5,m5;
	cout<<"enter size's\n";
	cin>>n5>>m5;
	cout<<"enter elements of 1st array\n";
	int x5[n5],y5[n5],i;
	for(i=0;i<n5;i++)
		cin>>x5[i];
	int j=0;
	cout<<"enter elements of 2nd array\n";
	int x51[n5];
	for(i=0;i<m5;i++)
		cin>>y5[i];
	for(i=0;i<m5;i++)
	{
		for(j=0;j<n5;j++)
		{
			if(x5[j]==0)
			{
				{
					if(x5[j-1]>x5[j])
					{
						//cout<<"entered\n";
						int k=j-1;
						while(x5[k]>y5[i])
						{
							x5[k+1]=x5[k];
							k--;
						}
						x5[k+1]=y5[i];
						break;
					}
					int k=j;
					while(k<n5 && x5[k]==0)
						k++;
					if(x5[k]>y5[i])
						{x5[j]=y5[i];break;}
					else
					{
						x5[j]=x5[k];
						x5[k]=0;
					}
				}
			}
		}
	}
	for(i=0;i<n5;i++)
		cout<<x5[i]<<" ";
	cout<<endl;
}