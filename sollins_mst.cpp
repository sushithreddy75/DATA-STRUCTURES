#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int find(int S[],int x)
{
    if(S[x]==-1)
    return x;
    return find(S,S[x]);
}
void union1(int S[],int x,int y)
{
    if(S[y]==-1)
    S[y]=x;
    else if(S[x]==-1)
    S[x]=y;
    else 
    S[find(S,y)]=find(S,x);
}
void find(int **G,int i,vector<vector<int>>v,int &x,int &y,int S[],int n,int vis[])
{
    int min=1e9;
    vector<int>v1=v[i];
    for(i=0;i<v1.size();i++)
    {
        int x1=v1[i];
        for(int j=1;j<=n;j++)
        {
            if(G[x1][j]&&G[x1][j]<min&&find(S,x1)!=find(S,j)&&(!vis[find(S,j)-1]||!vis[find(S,x1)-1]))
            {
                x=x1;
                y=j;
                min=G[x1][j];
            }
        }
    }
}
void merge(vector<vector<int>>&v,int x,int y)
{
    vector<int>v1=v[y];
    for(int i=0;i<v1.size();i++)
    v[x].pb(v1[i]);
}
void del(vector<vector<int>>&v,int i,int j)
{
    v.erase(v.begin()+j-i);
}
void sollins(int **G,int n,int S[])
{
    vector<vector<int>>v;
    int i,x,y,sum=0;
    for(i=1;i<=n;i++)
    {
        vector<int>v1={i};
        v.pb(v1);
    }
    while(v.size()>1)
    {
        int vis[v.size()]={0};
        vector<int>v1;
        vector<pair<int,int>>mer;
        int ch[v.size()]={0};
        for(i=0;i<v.size();i++)
        {
            if(1)
            {
                x=y=-1;
                find(G,i,v,x,y,S,n,vis);
                if(x!=-1&&y!=-1)
                {
                    vis[i]=vis[find(S,y)-1]=1;
                    cout<<x<<" "<<y<<" "<<G[x][y]<<endl;
                    sum+=G[x][y];
                    if((find(S,x)>find(S,y)))
                    {
                        int temp=x;
                        x=y;
                        y=temp;
                    }
                    //merge(v,i,find(S,y)-1);
                    mer.pb(mp(find(S,x)-1,find(S,y)-1));
                    if(!ch[find(S,y)-1])
                    v1.pb(find(S,y)-1);
                    ch[find(S,y)-1]=1;
                    union1(S,x,y);
                }
            }
        }
        sort(mer.rbegin(),mer.rend());
        for(i=0;i<mer.size();i++)
        merge(v,mer[i].first,mer[i].second);
        sort(v1.begin(),v1.end());
        for(i=0;i<v1.size();i++)
        del(v,i,v1[i]);
    }
    cout<<sum<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,c,i;
    cin>>n>>c;
    int **G= new int *[n+1];
    for(i=1;i<=n;i++)
    G[i]=new int[n+1];
    while(c--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x][y]=G[y][x]=z;
    }
    int S[n+1];
    for(i=0;i<=n;i++)
    S[i]=-1;
    sollins(G,n,S);
}