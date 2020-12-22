#include<iostream>
using namespace std;
int create(int a[],int S[],int l,int r,int i)
{
	if(l==r)
	{
		S[i]=a[l];
		return S[i];
	}
	int mid=(l+r)/2;
	S[i]=create(a,S,l,mid,2*i+1)+create(a,S,mid+1,r,2*i+2);
	return S[i];
}
int query(int S[],int x,int y,int l,int r,int i)
{
	if(l>=x && r<=y)
		return S[i];
	if(r<x || l>y)
		return 0;
	return (query(S,x,y,l,(l+r)/2,2*i+1)+query(S,x,y,(l+r)/2+1,r,2*i+2));
}
void modify(int S[],int x,int y,int l,int r,int i)
{
	if(x<l || x>r || l>=r)
		return;
	S[i]+=y;
	modify(S,x,y,l,(l+r)/2,2*i+1);
	modify(S,x,y,(l+r)/2+1,r,2*i+2);
}
int main()
{
	int n;
	cin>>n;
	int x=2,y=n;
	while(y)
	{
		y/=2;
		x*=2;
	}
	x--;
	int A[n],S[x]={0},i;
	for(i=0;i<n;i++)
		cin>>A[i];
	S[0]=create(A,S,0,n-1,0);
	cin>>x>>y;
	int sum=query(S,x,y,0,n-1,0);
	cout<<sum<<endl;
	cin>>x>>y;
	y-=A[x];
	A[x]+=y;
	modify(S,x,y,0,n-1,0);
	cin>>x>>y;
	sum=query(S,x,y,0,n-1,0);
	cout<<sum<<endl;
}