#include<bits/stdc++.h>
using namespace std;
void trav(int **G,bool vis[],int n,int x,int &k,int num[])
{
    vis[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(G[x][i]&&!vis[i])
        trav(G,vis,n,i,k,num);
    }
    //cout<<x<<" "<<k<<endl;
    num[x]=k;
    k++;
}
void trav(int **G,int n,int num[])
{
    bool vis[n+1]={0};
    int flag=2,k=1;
    //int num[n+1];
    while(flag)
    {
        trav(G,vis,n,flag,k,num);
        flag=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                flag=i;
                break;
            }
        }
    }
    
}
void trav2(int **G,int vis[],int n,int x)
{
    vis[x]=1;
    cout<<x<<" ";
    for(int i=1;i<=n;i++)
    {
        if(G[x][i]&&!vis[i])
        trav2(G,vis,n,i);
    }
    //cout<<x<<" "<<k<<endl;

}
void trav2(int **G,int n,int num[])
{
    int vis[n+1]={0},flag=1;
    while(flag)
    {
        
        int max=0;flag=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&num[i]>max)
            {
                flag=i;
                max=num[i];
                //break;
            }
        }
        if(flag)
        trav2(G,vis,n,flag);
        cout<<endl;
    }
}
int main()
{
    int **G=new int*[10],i,n=10;
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    G[1][2]=G[1][4]=1;
    G[2][3]=G[2][6]=1;
    G[3][1]=G[3][4]=G[3][5]=1;
    G[4][5]=1;
    G[6][3]=1;
    G[7][6]=G[7][8]=1;
    G[8][10]=G[9][8]=G[10][9]=G[8][6]=1;
    int num[n+1];
    trav(G,n,num);
    int **G1=new int*[10];
    for(i=0;i<=n;i++)
    G1[i]=new int[n+1];
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(G[i][j]==1)
            {
                G[i][j]=0;
                G[j][i]=2;
            }
        }
    }
    trav2(G,n,num);
}