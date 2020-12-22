#include<iostream>
using namespace std;
void merge(int a[],int lm[],int rm[],int n,int l,int r)
{
    int i=0,j=0,k=0;
    for(i=0;i<n && j<l && k<r;i++)
    {
        if(lm[j]>rm[k])
        {
            a[i]=rm[k];
            k++;
        }
        else
        {
            a[i]=lm[j];
            j++;
        }
    }
    for(i;i<n && j<l;i++)
    {
        a[i]=lm[j];
        j++;
    }
    for(i;i<n && k<r;i++)
    {
        a[i]=rm[k];
        k++;
    }
}
void mergesort(int a[],int n)
{
    if(n<2)
        return;
    int lm[n/2],rm[n-n/2],i;
    for(i=0;i<n;i++)
    {
        if(i<n/2)
            lm[i]=a[i];
        else
            rm[i-(n/2)]=a[i];
    }
    mergesort(lm,n/2);
    mergesort(rm,n-(n/2));
    merge(a,lm,rm,n,n/2,n-(n/2));
}
int main()
{
    cout<<"enter size: ";
    int n;
    cin>>n;
    int a[n],i;
    cout<<"enter values\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,n);
    int max=0;
    for(i=0;i<n;i++)
    {
        int x=a[i]*(n-i);
        if(x>max)
            max=x;
    }
    cout<<"max area: "<<max<<endl;
}
