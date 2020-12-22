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
	S[i]=max(create(a,S,l,mid,2*i+1),create(a,S,mid+1,r,2*i+2));
	return S[i];
}
int query(int S[],int x,int y,int l,int r,int i)
{
	if(l>=x && r<=y)
		return S[i];
	if(r<x || l>y)
		return 0;
	return max(query(S,x,y,l,(l+r)/2,2*i+1),query(S,x,y,(l+r)/2+1,r,2*i+2));
}
void modify(int S[],int x,int y,int l,int r,int i)
{
	if(x<l || x>r || l>r)
		return;
	if(l==r && l==x)
		S[i]=y;
	if(l==r)
		return;
	modify(S,x,y,l,(l+r)/2,2*i+1);
	modify(S,x,y,(l+r)/2+1,r,2*i+2);
	if(l!=r)
		S[i]=max(S[2*i+1],S[2*i+2]);
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
	int max=query(S,x,y,0,n-1,0);
	cout<<max<<endl;
	cin>>x>>y;
	A[x]=y;
	modify(S,x,y,0,n-1,0);
	cin>>x>>y;
	max=query(S,x,y,0,n-1,0);
	cout<<max<<endl;
}