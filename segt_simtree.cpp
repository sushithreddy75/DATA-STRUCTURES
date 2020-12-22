#include<iostream>
using namespace std;
int construct(int A[],int S[],int l,int r,int i)
{
	if(l==r)
	{
		S[i]=A[l];
		return S[i];
	}
	S[i]=min(construct(A,S,l,(l+r)/2,2*i+1),construct(A,S,(l+r)/2+1,r,2*i+2));
	return S[i];
}
int query(int s[],int x,int y,int l,int r,int i)
{
	if(x>r || y<l)
		return 1e9;
	if(x<=l && y>=r)
		return s[i];
	int z=min(query(s,x,y,l,(l+r)/2,2*i+1),query(s,x,y,(l+r)/2+1,r,2*i+2));
	return z;
}
int main()
{
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	int a[n],s[4*n],i;
	for(i=0;i<n;i++)
		cin>>a[i];
	s[0]=construct(a,s,0,n-1,0);
	int b[n],r[4*n];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>b[i];
	r[0]=construct(b,r,0,n-1,0);
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int x=query(s,i,j,0,n-1,0);
			int y=query(r,i,j,0,n-1,0);
			if(x==y)
				cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}