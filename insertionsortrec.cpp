#include<iostream>
using namespace std;
int find(int j,int i,int a[])
{
    if(a[j]>a[i])
    return j;
    return find(j+1,i,a);
}
void insert(int k,int j,int a[])
{
    if(k==j)
    return;
    a[k]=a[k-1];
    insert(k-1,j,a);
}
void insertionsort(int i,int n,int a[])
{
    if(i==n)
    return;
    if(a[i]<a[i-1])
    {
        int x,j=find(0,i,a);
        x=a[i];
        insert(i,j,a);
        a[j]=x;
    }
    insertionsort(i+1,n,a);
}
int main()
{
    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
    cin>>a[i];
    insertionsort(0,n,a);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
}