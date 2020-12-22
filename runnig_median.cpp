#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void minconstruct(int a[],int i)
{
    if(i<=0)
        return;
    if(a[i]<a[(i-1)/2])
    {
        swap(a+i,a+(i-1)/2);
        minconstruct(a,(i-1)/2);
    }
}
void minchange(int a[],int i,int n)
{
    if(i>=n)
        return;
    if(2*i+1<n && a[i]>a[2*i+1])
    {
        swap(a+i,a+2*i+1);
        if(2*i+1<n && a[i]>a[2*i+2])
            minchange(a,i,n);
        minchange(a,2*i+1,n);
    }
    else if(2*i+2<n && a[i]>a[2*i+2])
    {
        swap(a+i,a+2*i+2);
        minchange(a,2*i+2,n);
    }
}
void maxconstruct(int a[],int i)
{
    if(i<=0)
        return;
    if(a[i]>a[(i-1)/2])
    {
        swap(a+i,a+(i-1)/2);
        maxconstruct(a,(i-1)/2);
    }
}
void maxchange(int a[],int i,int n)
{
    if(i>=n)
        return;
    if(2*i+1<n && a[i]<a[2*i+1])
    {
        swap(a+i,a+2*i+1);
        if(2*i+1<n && a[i]<a[2*i+2])
            maxchange(a,i,n);
        maxchange(a,2*i+1,n);
    }
    else if(2*i+2<n && a[i]<a[2*i+2])
    {
        swap(a+i,a+2*i+2);
        maxchange(a,2*i+2,n);
    }
}
void insert(int h1[],int h2[],int &n1,int &n2,int x)
{
    if(n2==0)
    {
        h2[0]=x;
        n2++;
        return;
    }
    if(n1==0)
    {
        if(x<h2[0])
            h1[0]=x;
        else
        {
            h1[0]=h2[0];
            h2[0]=x;
        }
        n1++;
        return;
    }
    if(x>(h1[0]+h2[0])/2 && n1>=n2)
    {
        h2[n2]=x;
        n2++;
        minconstruct(h2,n2-1);
        return;
    }
    if(x>(h1[0]+h2[0])/2 && n2>n1)
    {
        if(h2[0]<x)
        {
            h1[n1]=h2[0];
            h2[0]=x;
        }
        else
        {
            h1[n1]=x;
        }
        n1++;
        maxconstruct(h1,n1-1);
        minchange(h2,0,n2);
        return;
    }
    if(n1<=n2)
    {
        h1[n1]=x;
        n1++;
        maxconstruct(h1,n1-1);
        return;
    }
    if(h1[0]>x)
    {
        h2[n2]=h1[0];
        h1[0]=x;
    }
    else
        h2[n2]=x;
    n2++;
    minconstruct(h2,n2-1);
    maxchange(h1,0,n1);
}
int main()
{
	int h1[100],h2[100],n1=0,n2=0;
	while(1)
	{
		int x,i;
		cin>>x;
		if(x==-1)
			break;
		insert(h1,h2,n1,n2,x);
		if(n1==n2)
			cout<<float(h1[0]+h2[0])/2<<endl;
		else if(n1>n2)
			cout<<h1[0]<<endl;
		else
			cout<<h2[0]<<endl;
	}
	return 0;
}