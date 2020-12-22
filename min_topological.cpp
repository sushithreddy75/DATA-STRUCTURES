#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
void path(int **G,int i,vector<int>&v,int n)
{
    while(i<=n)
    {
        v.pb(i);int j;
        for(j=1;j<=n;j++)
        if(G[i][j])
        break;
        i=j;
    }
}
void divide(vector<pair<int,vector<int>>>&v,vector<int>v1,int c)
{
    if(!v1.size())
    return;
    if(v1.size()<=1)
    {
        return;
        if(v1[0])
        v[v1[0]].S.erase(v[v1[0]].S.begin()+v[v1[0]].S.size()-1);
        return;
    }
    vector<int>v2=v[v1[0]].S;
    int x=v2[v2.size()-1-c];
    vector<int>q1,q2;
    q1.pb(v1[0]);
    for(int i=1;i<v1.size();i++)
    {
        v2=v[v1[i]].S;
        if(v[v1[i]].S[v2.size()-1]==x)
        {
            q1.pb(v1[i]);
            v[v1[i]].S.erase(v[v1[i]].S.begin()+v2.size()-1);
        }
        else 
        q2.pb(v1[i]);
    }
    divide(v,q1,c+1);
    divide(v,q2,0);
}
void print(vector<int>v,char val[])
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==-1)
        continue;
        while(v[i]!=-1)
        {
            cout<<val[v[i]]<<" ";
            i++;
        }
        cout<<endl;
    }
    cout<<endl;
}
void permute(vector<pair<int,vector<int>>>v,vector<int>out,vector<int>skip,int i,vector<int>v1,char val[]);
bool check(vector<int>skip)
{
    for(int i=0;i<skip.size();i++)
    if(skip[i])
    return false;
    return true;
}
void print(vector<pair<int,vector<int>>>v,vector<int>out,vector<int>skip,vector<int>v1,char val[])
{
    out.pb(-1);
    if(v1[0]==v[0].S.size())
    {
        if(check(skip))
        print(out,val);
        return;
    }
    permute(v,out,skip,0,v1,val);
}
void permute(vector<pair<int,vector<int>>>v,vector<int>out,vector<int>skip,int i,vector<int>v1,char val[])
{
    if(i==v.size())
    return print(v,out,skip,v1,val);
    vector<int>out1=out;
    if(v1[i]<v[i].S.size())
    {
        out.pb(v[i].S[v1[i]]);
        v1[i]++;
        permute(v,out,skip,i+1,v1,val);
        v1[i]--;
    }
    else 
    permute(v,out,skip,i+1,v1,val);
    if(skip[i]>0&&v1[i]<v[i].S.size())
    {
        skip[i]--;
        permute(v,out1,skip,i+1,v1,val);
    }
}
void path(int **G,int pre[],int n,char val[])
{
    vector<pair<int,vector<int>>>v;
    int i;
    for(i=1;i<=n;i++)
    {
        if(!pre[i])
        {
            vector<int>v1;
            path(G,i,v1,n);
            v.pb(mp(v1.size(),v1));
        }
    }
    sort(v.rbegin(),v.rend());
    vector<int>skip,fre,v3,out;
    for(i=0;i<v.size();i++)
    {
        skip.pb(v[0].F-v[i].F);
        fre.pb(i);
        v3.pb(0);
    }
    divide(v,fre,0);
    permute(v,out,skip,0,v3,val);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,k,i;
    cin>>n>>k;
    char val[n+1];
    for(i=1;i<=n;i++)
    cin>>val[i];
    int **G=new int *[n];
    for(i=1;i<=n;i++)
    G[i]=new int[n];
    int pre[n+1]={0};
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        G[x][y]=1;
        pre[y]++;
    }
    path(G,pre,n,val);
}