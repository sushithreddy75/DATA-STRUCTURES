#include<bits/stdc++.h>
using namespace std;
void print(int **G,int x,int n,bool vis[],int &t,int a[],int b[])
{
    vis[x]=1;
    a[x]=t;
    t++;
    for(int i=0;i<n;i++)
    {
        if(vis[i]!=1&&G[x][i])
        print(G,i,n,vis,t,a,b);
    }
    b[x]=t;
    t++;
}
void print(int **G,int n)
{
    bool vis[n]={0};
    int t=0;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        print(G,i,n,vis,t,a,b);
    }
    for(int i=0;i<n;i++)
    cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,i;
    cin>>n;
    int **G=new int*[n+1];
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    while(1)
    {
        int x,y,z;
        cin>>x>>y;
        if(x==-1)
        break;
        G[x][y]=1;
    }
    print(G,n);
}