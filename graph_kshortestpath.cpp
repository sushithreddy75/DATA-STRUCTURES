#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
void path(int a[][3],queue<int>&q,int y)
{
    if(a[y][1]==0)
    {
        q.push(y);
        return;
    }
    path(a,q,a[y][2]);
    cout<<y<<endl;
    q.push(y);
}
void djikstra(int **G,int n,queue<int>&q,int x,int y,int &sum)
{
    int a[n+1][3],vis[n+1]={0};
    int i;
    for(i=0;i<=n;i++)
    {
        a[i][0]=0;
        a[i][1]=1e9;
    }
    a[x][1]=0;
    a[x][0]=1;
    while(x!=y)
    {
        for(i=1;i<=n;i++)
        {
            if(G[x][i]&&!vis[i]&&a[i][1]>(a[x][1]+G[x][i]))
            {
                a[i][1]=a[x][1]+G[x][i];
                a[i][2]=x;
            }
        }
        int min=1e9,ind;
        for(i=1;i<=n;i++)
        {
            if(!a[i][0]&&a[i][1]<min)
            {
                min=a[i][1];
                ind=i;
            }
        }
        x=ind;
        //ut<<x<<" "<<y<<endl;
        a[x][0]=1;
    }
    cout<<endl;
    path(a,q,y);
    sum=a[y][1];
}
int len(int **G,queue<int>q)
{
    int x=q.front();
    q.pop();
    if(q.empty())
    return 0;
    cout<<x<<" "<<q.front()<<endl;
    return G[x][q.front()]+len(G,q);
}
void kpath(int **G,vector<pair<int,queue<int>>>&v,int x,int y,int n,int k)
{
    queue<int>q=v[0].second;
    while(v.size()!=k)
    {
        queue<int>q1,q2,q3;
        q1=q;q2=v[v.size()-1].second;
        int x1,y1;
        while(1)
        {
            x1=q1.front();y1=q2.front();
            q1.pop();q2.pop();
            if(x1==y1&&q1.front()==q2.front())
            break;
            q3.push(q2.front());
        }
        y1=q2.front();
        int temp=G[x1][y1];G[x1][y1]=1e9;int s1=0;
        djikstra(G,n,q3,x1,y,s1);
        G[x1][y1]=temp;
        v.pb(mp(len(G,q3),q3));
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,i,c,k;
    cin>>n>>c>>k;
    int **G=new int*[n+1];
    for(i=0;i<=n;i++)
    G[i]=new int[n];
    while(c--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x][y]=z;
    }
    int x,y,sum=0;
    cin>>x>>y;
    queue<int>q;
    djikstra(G,n,q,x,y,sum);
    vector<pair<int,queue<int>>>v;
    v.pb(mp(sum,q));
    kpath(G,v,x,y,n,k);
}