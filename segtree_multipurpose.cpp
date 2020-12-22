#include<iostream>
using namespace std;
struct segt
{
	int min;
	int max;
	int sum;
	float avg;
};
segt construct(int A[],segt S[],int l,int r,int i)
{
	if(l==r)
	{
		S[i].sum=S[i].min=S[i].max=A[l];
		S[i].avg=A[l];
		return S[i];
	}
	segt x=construct(A,S,l,(l+r)/2,2*i+1);
	segt y=construct(A,S,(l+r)/2+1,r,2*i+2);
	S[i].sum=x.sum+y.sum;
	S[i].min=min(x.min,y.min);
	S[i].max=max(x.max,y.max);
	S[i].avg=float((x.sum+y.sum))/float(r-l+1);
	return S[i];
}
segt query(segt S[],int x,int y,int l,int r,int i)
{
	if(l>=x && r<=y)
		return S[i];
	segt s;
	s.min=1e9;
	s.max=s.sum=0;
	s.avg=0;
	if((l>y || x>r || l>=r))
		return s;
	{
	segt x1=query(S,x,y,l,(l+r)/2,2*i+1);
	segt y1=query(S,x,y,(l+r)/2+1,r,2*i+2);
	s.min=min(x1.min,y1.min);
	s.max=max(x1.max,y1.max);
	s.sum=x1.sum+y1.sum;
	s.avg=float(s.sum)/float(r-l+1);
	return s;}
}
void update(segt S[],int x,int y,int l,int r,int i)
{
	if(x>r || x<l || l>r)
		return;
	if(x==l && l==r)
	{
		S[i].min=S[i].max=S[i].sum=y;
		S[i].avg=y;
		return;
	}
	update(S,x,y,l,(l+r)/2,2*i+1);
	update(S,x,y,(l+r)/2+1,r,2*i+2);
	segt x1=S[2*i+1],y1=S[2*i+2];
	S[i].min=min(x1.min,y1.min);
	S[i].max=max(x1.max,y1.max);
	S[i].sum=x1.sum+y1.sum;
	S[i].avg=float(S[i].sum)/float(r-l+1);
}
int main()
{
	int n;
	cin>>n;
	int A[n],i;
	for(i=0;i<n;i++)
		cin>>A[i];
	segt S[4*n];
	S[0]=construct(A,S,0,n-1,0);
	int q;
	cin>>q;
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x==0)
			update(S,y,z,0,n-1,0);
		else
		{
			segt out=query(S,y,z,0,n-1,0);
			if(x==1)
				cout<<out.min<<endl;
			if(x==2)
				cout<<out.max<<endl;
			if(x==3)
				cout<<out.sum<<endl;
			if(x==4)
				cout<<out.avg<<endl;
		}
	}
}