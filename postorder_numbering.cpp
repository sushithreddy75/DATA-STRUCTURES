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
void trav(int **G,int n)
{
    bool vis[n+1]={0};
    int flag=2,k=1;
    int num[n+1];
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
    for(int i=1;i<=n;i++)
    cout<<i<<" "<<num[i]<<endl;
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
    trav(G,n);
}