#include<bits/stdc++.h>
using namespace std;
void print(queue<int>s)
{
    while(!s.empty())
    {
        cout<<s.front()<<" ";
        s.pop();
    }
}
void loop(int **G,int n,int x,queue<int>s,bool vis[],int k,bool vis1[],int &c)
{
    s.push(x);
    if(vis[x])
    {
        print(s);cout<<endl;
        c++;
        return;
    }
    vis[x]=1;//vis1[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(G[x][i]&&!vis1[i])
        {
            loop(G,n,i,s,vis,k,vis1,c);
        }
    }
    vis[x]=0;
}
void loop(int **G,int n,int &c)
{
    queue<int>s;
     bool vis[n+1]={0},vis1[n+1]={0};
    for(int i=1;i<=n;i++)
    {
       
        if(!vis1[i])
        loop(G,n,i,s,vis,i,vis1,c);
        //cout<<endl;
        vis1[i]=1;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,i;
    cin>>n;
    int c;cin>>c;
    int **G=new int*[n+1];
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    while(c--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==-1)
        break;
        G[x][y]=1;
    }
    c=0;
    loop(G,n,c);
    cout<<c<<endl;
}