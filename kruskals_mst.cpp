#include<iostream>
using namespace std;
void swap(int **x,int i,int j)
{
    int a=x[i][0],b=x[i][1],c=x[i][2];
    x[i][0]=x[j][0];x[i][1]=x[j][1];x[i][2]=x[j][2];
    x[j][0]=a;x[j][1]=b;x[j][2]=c;
}
void heapify(int **heap,int i)
{
    if(i<=0)
    return;
    if(heap[i][0]<heap[(i-1)/2][0])                             
    {
        swap(heap,i,(i-1)/2);
        heapify(heap,(i-1)/2);
    }
    else if(heap[i][0]==heap[(i-1)/2][0]&&heap[i][1]<heap[(i-1)/2][1])
    {
        swap(heap,i,(i-1)/2);
        heapify(heap,(i-1)/2);
    }
}
void del(int **heap,int i,int n)
{
    if(2*i+1>=n)
    return;
    if(heap[i][0]>heap[2*i+1][0])
    {
        swap(heap,i,2*i+1);
        del(heap,i,n);
        return del(heap,2*i+1,n);
    }
    if(heap[i][0]==heap[2*i+1][0]&&heap[i][1]>heap[2*i+1][1])
    {
        swap(heap,i,2*i+1);
        del(heap,i,n);
        return del(heap,2*i+1,n);
    }
    if(2*i+2<n&&heap[i][0]>heap[2*i+2][0])
    {
        swap(heap,i,2*i+2);
        del(heap,2*i+2,n);
    }
    if(2*i+2<n&&heap[i][0]==heap[2*i+2][0]&&heap[i][1]>heap[2*i+2][1])
    {
        swap(heap,i,2*i+2);
        del(heap,2*i+2,n);
    }
}
bool check(int vis[],int n)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        return true;
    }
    return false;
}
int find(int S[],int x)
{
    if(S[x]==-1)
    return x;
    return find(S,S[x]);
}
void union1(int S[],int x,int y)
{
    if(S[y]==-1)
    S[y]=x;
    else if(S[x]==-1)
    S[x]=y;
    else 
    S[find(S,y)]=find(S,x);
}
void kruskals(int vis[],int S[],int &hc,int **heap,int n,int &s)
{
    while(check(vis,n))
    {
        int x=heap[0][0],y=heap[0][1],z=heap[0][2];
        if(find(S,y)!=find(S,z))
        {
            vis[y]=vis[z]=1;
            union1(S,y,z);
            cout<<y<<" "<<z<<endl;
            s+=x;
        }
        hc--;
        if(hc<0)
        break;
        heap[0][0]=heap[hc][0];
        heap[0][1]=heap[hc][1];
        heap[0][2]=heap[hc][2];
        del(heap,0,hc);
    }
}
int main()
{
    int n=7,i;
    int **G=new int*[n+1];
    int i1[]={1,1,1,2,2,3,3,4,4,4,5,6};
    int i2[]={2,3,4,4,5,4,6,5,6,7,7,7};
    int i3[]={2,4,1,3,10,2,5,7,8,4,6,1};
    int **heap=new int*[12];
    for(i=0;i<12;i++)
    heap[i]=new int[3];
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    int hc=0;
    for(i=0;i<12;i++)
    {
        G[i1[i]][i2[i]]=G[i2[i]][i1[i]]=i3[i];
        heap[hc][0]=i3[i];heap[hc][1]=i1[i];heap[hc][2]=i2[i];
        heapify(heap,hc);
        hc++;
    }
    int S[n+1];
    for(i=0;i<=n;i++)
    S[i]=-1;
    int vis[n+1]={0},s=0;
    kruskals(vis,S,hc,heap,n,s);      
    cout<<s<<endl;
    for(i=1;i<=n;i++)
    cout<<S[i]<<" ";
    cout<<endl;
}  