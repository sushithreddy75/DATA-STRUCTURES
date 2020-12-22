#include<bits/stdc++.h>
using namespace std;
void dft(int **G,int x,int n)
{
    stack<int>s,s1;
    s.push(x);s1.push(x);
    int vis[n+1]={0};
    while(!s.empty())
    {
        x=s.top();
        s.pop();
        if(!vis[x])
        cout<<x<<" "<<s1.top()<<endl;
        vis[x]=1;
        s1.pop();
        for(int i=n;i>0;i--)
        {
            if(G[x][i]&&vis[i]==0)
            {
                s.push(i);
                s1.push(x);
            }
        }
    }
}
void bft(int **G,int x,int n)
{
    queue<int>q;
    int vis[n+1]={0};
    cout<<x<<" "<<x<<endl;
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&G[x][i])
            {
                q.push(i);
                vis[i]=1;
                cout<<i<<" "<<x<<endl;
            }
        }
    }
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
        int x,y;
        cin>>x>>y;
        if(x==-1)
        break;
        G[x][y]=G[y][x]=1;
    }
    int x;
    cin>>x;
    dft(G,x,n);
    cout<<endl;
    bft(G,x,n);
}


//INPUT
/*
5
1 2
1 4
1 3
2 3
2 5
3 4
4 5
-1 -1


OUTPUT

2 2
1 2
3 1
4 3
5 4

2 2
1 2
3 2
5 2
4 1
*/