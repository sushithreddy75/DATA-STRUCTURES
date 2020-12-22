/*
Life is an endless journey
Love Inspire Forgive Evolve  enduringly 
                                     - KR
*/
#include<bits/stdc++.h>
using namespace std;
struct gnode
{
    int low,num;
    int par,stref;
};
void print(stack<int>&s,int x,gnode g[])
{
    while(s.top()!=x)
    {
        cout<<s.top()<<" ";
        g[s.top()].stref=0;
        s.pop();
    }
    cout<<s.top()<<endl;
    g[s.top()].stref=0;
    s.pop();
}
void dfs(int **G,gnode g[],stack<int>&s,stack<int>&s1,int n,int &k,int i)
{
    g[i].num=g[i].low=k++;
    int j;
    s.push(i);s1.push(i);
    g[i].stref=1;
    for(j=1;j<=n;j++)
    {
        if(!G[i][j])
        continue;
        if(!g[j].num)
        {
            g[j].par=i;
            dfs(G,g,s,s1,n,k,j);
            g[i].low=min(g[i].low,g[j].low);
            continue;
        }
        if(g[i].par!=j&&g[j].stref)
        g[i].low=min(g[i].low,g[j].num);
    }
    if(g[i].low==g[i].num)
    print(s1,s.top(),g);
    s.pop();
    //g[i].stref=0;
}
void dfs(int **G,gnode g[],int n)
{
    int flag=1,k=1;
    while(flag<=n)
    {
        stack<int>s,s1;
        dfs(G,g,s,s1,n,k,flag);
        for(flag=1;flag<=n;flag++)
        if(!g[flag].num)
        break;
    }
}
int main()
{
    int n=10,i;
    int **G=new int *[n+1];
    for(i=1;i<=n;i++)
    G[i]=new int[n+1];
    int i1[]={1,1,2,2,3,3,3,4,6,7,7,8,9,8,10};
    int i2[]={2,4,3,6,1,4,5,5,3,6,8,6,8,10,9};
    for(i=0;i<15;i++)
    G[i1[i]][i2[i]]=1;
    gnode g[n+1];
    for(i=0;i<=n;i++)
    g[i].low=g[i].num=g[i].par=g[i].stref=0;
    dfs(G,g,n);
}
