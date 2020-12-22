#include<bits/stdc++.h>
#define pb push_back
using namespace std;
void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void topological(int **G,vector<int>pre,vector<int>vis,int n,queue<int>q,int x)
{
    q.push(x);
    vis[x]=1;
    int i;
    vector<int>v;
    for(i=1;i<=n;i++)
    {
        if(G[x][i])
        pre[i]--;
    }
    for(i=1;i<=n;i++)
    {
        if(!pre[i]&&!vis[i])
        v.pb(i);
    }
    if(v.size()==0)
    {
        print(q);
        return;
    }
    for(i=0;i<v.size();i++)
    topological(G,pre,vis,n,q,v[i]);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,i;
    cin>>n;
    int **G=new int *[n+1];
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    int c;
    vector<int>pre(n+1);
    for(i=0;i<=n;i++)
    pre[i]=0;
    cin>>c;
    while(c--)
    {
        int x,y;
        cin>>x>>y;
        G[x][y]=1;
        pre[y]++;
    }
    vector<int>vis(n+1);
    for(i=0;i<=n;i++)
    vis[i]=0;
    queue<int>q;
    vector<int>v;
    for(i=1;i<=n;i++)
    {
        if(pre[i]==0)
        v.pb(i);
    }
    for(i=0;i<v.size();i++)
    topological(G,pre,vis,n,q,v[i]);
}

//TEST CASE
//INPUT
/*
8
9
1 7
2 3
2 5 
2 7
4 1
4 5
6 2
8 1
8 2
*/