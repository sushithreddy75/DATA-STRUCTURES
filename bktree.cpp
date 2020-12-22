#include<bits/stdc++.h>
using namespace std;
struct bknode
{
    string s;
    int diff;
    bknode *fc,*ns;
};
typedef bknode* bkptr;
int dist(string s,string s1)
{
    int m=s.size(),n=s1.size(),i,j;
    int a[m+1][n+1]={0};
    for(i=0;i<=n;i++)
    a[0][i]=i;
    for(i=0;i<=m;i++)
    a[i][0]=i;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(s[i-1]==s1[j-1])
            a[i][j]=a[i-1][j-1];
            else 
            {
                int mi=min(a[i][j-1],a[i-1][j]);
                mi=min(mi,a[i-1][j-1]);
                a[i][j]=mi+1;
            }
        }
    }
    return a[m][n];
}
void insert(bkptr &h,bkptr t)
{
    if(!h)
    {
        h=t;
        return;
    }
    if(h->diff>t->diff)
    {
        t->ns=h;
        h=t;
        return;
    }
    bkptr t1=h;
    while(t1->ns && t1->ns->diff<t->diff)
    t1=t1->ns;
    t->ns=t1->ns;
    t1->ns=t;
}
void construct(bkptr &t,string s)
{
    if(!t)
    {
        t=new(bknode);
        t->s=s;
        t->fc=t->ns=NULL;
        return;
    }
    int size=dist(s,t->s);
    bkptr t1=t->fc;
    while(t1)
    {
        if(t1->diff==size)
        break;
        t1=t1->ns;
    }
    if(t1)
    return construct(t1,s);
    t1=new(bknode);
    t1->diff=size;
    t1->fc=NULL;
    t1->s=s;
    insert(t->fc,t1);
}
void search(bkptr t,int k,string s)
{
    queue<bkptr>q;
    int l,r,x;
    q.push(t);
    while(!q.empty())
    {
        bkptr t=q.front();
        x=dist(s,t->s);
        if(x<=k)
                cout<<t->s<<" "<<x<<endl;
        l=x-k;r=x+k;
        t=t->fc;
        while(t)
        {
            if(t->diff>=l&&t->diff<=r)
            q.push(t);
            else 
            break;
            t=t->ns;
        }
        q.pop();
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    bkptr T=NULL;
    while(1)
    {
        string s;
        cin>>s;
        if(s=="#")
        break;
        construct(T,s);
    }
    int x;string s;
    cin>>s>>x;
    search(T,x,s);
}