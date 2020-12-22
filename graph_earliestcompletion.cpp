#include<bits/stdc++.h>
using namespace std;
void print(int **G,float **a,int *prev,float &sum)
{
    int n=9,i;
    float val[n];
    for(i=0;i<n;i++)
    val[i]=0;
    vector<int>v;
    v.push_back(0);
    int ind=0;
    val[0]=0;
    while(v.size())
    {
        int x=v[ind];
        for(i=1;i<n;i++)
        {
            if(G[x][i])
            {prev[i]--;
            if(!prev[i])
            v.push_back(i);
            val[i]=max(val[x]+a[x][i],val[i]);
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
    sum=val[8];
}
int main()
{
    int **G=new int*[9],i,n=9;
    for(i=0;i<9;i++)
    G[i]=new int[9];
    G[0][1]=G[0][2]=1;
    G[1][3]=G[1][5]=1;
    G[2][5]=1;
    G[3][4]=G[3][6]=1;
    G[4][7]=1;
    G[5][6]=G[6][7]=G[7][8]=1;
    float dist[9]={0,3.1,2.0,4.6,1.8,0.3,4,3.7,0};
    float **a=new float*[9];
    for(i=0;i<9;i++)
    a[i]=new float[9];
    int vis[n]={0},prev[n]={0};
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(G[i][j])
            {a[i][j]=dist[i];
            prev[j]++;}
        }
    }
    float sum=0;
    print(G,a,prev,sum);
    cout<<sum<<endl;
}