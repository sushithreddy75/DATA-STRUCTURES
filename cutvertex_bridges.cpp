/*You cannot teach a man anything, 
You can only help him find it within himself.
                                         Dale Carnegie*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
struct gnode
{
    int low;
    int num;
    int par,dftc,ap;
};
void dfs(int **G,gnode g[],int n,int i,vector<int>&v,queue<int>&q)
{
    static int t=1;
    g[i].low=g[i].num=t;
    t++;
    for(int j=0;j<n;j++)
    {
        if(!G[i][j])
        continue;
        if(!g[j].num)
        {
            g[i].dftc++;
            g[j].par=i;
            dfs(G,g,n,j,v,q);
            g[i].low=min(g[i].low,g[j].low);
            if((!g[i].par&&g[i].dftc>1)||(g[i].par&&g[i].num<=g[j].low))
            g[i].ap=1;
            if(g[i].num<g[j].low)
            {
                q.push(i);
                q.push(j);
            }
            continue;
        }
        if(g[i].par!=j)
        g[i].low=min(g[i].low,g[j].num);
    }
}
int main()
{
    int n=9,i;
    int **G=new int*[n];
    for(i=0;i<n;i++)
    G[i]=new int[n];
    int i1[]={0,0,1,2,2,3,5,5,6,7},i2[]={1,2,2,3,5,4,6,8,7,8};
    for(i=0;i<10;i++)
    G[i1[i]][i2[i]]=G[i2[i]][i1[i]]=1;
    gnode g[n];
    vector<int>v;
    queue<int>q;
    for(i=0;i<n;i++)
    g[i].low=g[i].num=g[i].par=g[i].dftc=g[i].ap=0;
    dfs(G,g,n,0,v,q);
    for(i=0;i<n;i++)
    if(g[i].ap)
    cout<<i<<" ";
    cout<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
        cout<<q.front()<<endl;
        q.pop();
    }
}