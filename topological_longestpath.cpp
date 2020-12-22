#include<bits/stdc++.h>
using namespace std;
void print(int **G,int *prev)
{
    int n=8,i;
    float val[n];
    for(i=0;i<n;i++)
    val[i]=1e9;
    vector<int>v;
    v.push_back(7);
    int ind=0;
    val[7]=0;
    while(v.size())
    {
        int x=v[ind];
        for(i=0;i<n;i++)
        {
            if(G[x][i])
            {prev[i]--;
            if(!prev[i])
            v.push_back(i);
            val[i]=min(val[x]+G[x][i],val[i]);
            }
        }
        v.erase(v.begin()+ind);
        ind=0;
        for(i=0;i<v.size();i++)
        {
            if(v[i]<v[ind])
            ind=i;
        }
    }
    //sum=val[8];
    for(i=0;i<n-1;i++)
    cout<<val[i]<<" ";
    cout<<endl;
}
int main()
{
    int **G=new int*[8],i,n=8;
    for(i=0;i<n;i++)
    G[i]=new int[n];
    G[0][6]=2;
    G[1][2]=-4;
    G[1][4]=1;
    G[1][6]=8;
    G[3][0]=3;
    G[3][4]=5;
    G[5][1]=2;
    G[7][0]=6;
    G[7][1]=-1;
    G[7][3]=4;
    G[7][5]=-4;
    int vis[n]={0},prev[n]={0};
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(G[i][j])
            {//a[i][j]=dist[i];
            prev[j]++;}
        }
    }
    float sum=0;
    print(G,prev);
    //cout<<sum<<endl;
}