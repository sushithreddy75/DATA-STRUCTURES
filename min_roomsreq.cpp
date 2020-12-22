#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void heapify(int heap[],int i)
{
    if(i<=0)
    return;
    if(heap[i]<heap[(i-1)/2])
    {
        swap(heap+i,heap+(i-1)/2);
        heapify(heap,(i-1)/2);
    }
}
void del(int heap[],int i,int n)
{
    if(i>=n)
    return;
    if(2*i+1<n&&heap[i]>heap[2*i+1])
    {
        swap(heap+i,heap+2*i+1);
        del(heap,i,n);
        return del(heap,2*i+1,n);
    }
    if(2*i+2<n)
    {
        swap(heap+i,heap+2*i+2);
        del(heap,2*i+2,n);
    }
}
void find(int **a,int n,int &m)
{
    int heap[n],c=0;
    for(int i=0;i<n;i++)
    {
        while(c&&heap[0]<a[i][0])
        {
            c--;
            heap[0]=heap[c];
            del(heap,0,c);
        }
        heap[c]=a[i][1];
        heapify(heap,c);
        c++;
        m=max(c,m);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,i;
    cin>>n;
    int **a=new int*[n];
    for(i=0;i<n;i++)
    a[i]=new int[2];
    int m=0;
    for(i=0;i<n;i++)
    cin>>a[i][0]>>a[i][1];
    find(a,n,m);
    cout<<m<<endl;
}