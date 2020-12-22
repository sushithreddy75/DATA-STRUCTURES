#include<bits/stdc++.h>
#define pb  push_back
using namespace std;
struct node
{
    int x,y,z;
};
bool exist(vector<node>v,node x)
{
    for(int i=0;i<v.size();i++)
    if(v[i].x==x.x&&v[i].y==x.y&&v[i].z==x.z)
    return true;
    return false;
}
void bfs(vector<vector<int>>&v,vector<node>&v1)
{
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        node x,x1;
        int i=q.front();
        q.pop();
        x=v1[i];
        if(x.x==4||x.y==4)
        return;
        if(x.x>0)
        {
            x1.x=0;x1.y=x.x+x.y;x1.z=x.z;
            if(x1.y>5)
            {
                x1.x=x1.y-5;
                x1.y=5;
            }
            if(!exist(v1,x1))
            {
                v1.pb(x1);
                v[i].pb(v.size());
                q.push(v.size());
                vector<int>v2;v2.pb(i);
                v.pb(v2);
            }
            x1.x=0;x1.y=x.y;x1.z=x.z+x.x;
            if(x1.z>3)
            {
                x1.x=x1.z-3;
                x1.z=3;
            }
            if(!exist(v1,x1))
            {
                v1.pb(x1);
                v[i].pb(v.size());
                q.push(v.size());
                vector<int>v2;v2.pb(i);
                v.pb(v2);
            }
        }
        if(x.y>0)
        {
            x1.y=0;x1.x=x.x+x.y;x1.z=x.z;
            if(x1.x>8)
            {
                x1.y=x1.x-8;
                x1.x=8;
            }
            if(!exist(v1,x1))
            {
                v1.pb(x1);
                v[i].pb(v.size());
                q.push(v.size());
                vector<int>v2;v2.pb(i);
                v.pb(v2);
            }
            x1.y=0;x1.x=x.x;x1.z=x.z+x.y;
            if(x1.z>3)
            {
                x1.y=x1.z-3;
                x1.z=3;
            }
            if(!exist(v1,x1))
            {
                v1.pb(x1);
                v[i].pb(v.size());
                q.push(v.size());
                vector<int>v2;v2.pb(i);
                v.pb(v2);
            }
        }
        if(x.z)
        {
            x1.z=0;x1.x=x.x+x.z;x1.y=x.y;
            if(x1.x>8)
            {
                x1.z=x1.x-8;
                x1.x=8;
            }
            if(!exist(v1,x1))
            {
                v1.pb(x1);
                v[i].pb(v.size());
                q.push(v.size());
                vector<int>v2;v2.pb(i);
                v.pb(v2);
            }
            x1.z=0;x1.x=x.x;x1.y=x.z+x.y;
            if(x1.y>5)
            {
                x1.z=x1.y-5;
                x1.y=5;
            }
            if(!exist(v1,x1))
            {
                v1.pb(x1);
                v[i].pb(v.size());
                q.push(v.size());
                vector<int>v2;v2.pb(i);
                v.pb(v2);
            }
        }
    }
}
bool dfs(vector<vector<int>>v,stack<int>&s,vector<node>v1,int i,bool vis[])
{
    s.push(i);
    vis[i]=1;
    for(int j=0;j<v[i].size();j++)
    {
        if(v1[v[i][j]].x==4||v1[v[i][j]].y==4)
        {
            s.push(v[i][j]);
            return true;
        }
        if(!vis[v[i][j]]&&dfs(v,s,v1,v[i][j],vis))
        return true;
    }
    s.pop();
    return false;
}
void print(stack<int>s,vector<node>v)
{
    if(s.empty())
    return;
    int i=s.top();
    s.pop();
    print(s,v);
    cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<endl;
}
int main()
{
    vector<vector<int>>v;
    vector<node>v1;
    vector<int>v2;
    v.pb(v2);
    node x;
    x.x=8;x.y=x.z=0;
    v1.pb(x);
    bfs(v,v1);
    stack<int>s;
    bool vis[v.size()]={0};
    bool b1=dfs(v,s,v1,0,vis);
    print(s,v1);
}