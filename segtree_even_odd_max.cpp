#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
ll oddconstruct(ll a[],ll o[],ll l,ll r,ll i)
{
    if(l==r)
    {
        if(a[l]%2)
        o[i]=a[l];
        else
        o[i]=0;
        return o[i];
    }
    o[i]=max(oddconstruct(a,o,l,(l+r)/2,2*i+1),oddconstruct(a,o,((l+r)/2)+1,r,2*i+2));
    return o[i];
}
ll evenconstruct(ll a[],ll e[],ll l,ll r,ll i)
{
    if(l==r)
    {
        if(a[l]%2)
        e[i]=0;
        else
        e[i]=a[l];
        return e[i];
    }
    e[i]=max(evenconstruct(a,e,l,(l+r)/2,2*i+1),evenconstruct(a,e,((l+r)/2)+1,r,2*i+2));
    return e[i];
}
void update(ll o[],ll e[],ll x,ll y,ll l,ll r,ll i)
{
    if(l>r || x<l || y>r)
    return;
    if(l==x && l==r)
    {
        o[x]=e[x]=0;
        if(y%2)
        o[x]=y;
        else
        e[x]=y;
    }
    if(l==r)
    return;
    update(o,e,x,y,l,(l+r)/2,2*i+1);
    update(o,e,x,y,((l+r)/2)+1,r,2*i+2);
    o[i]=max(o[2*i+1],o[2*i+2]);
    e[i]=max(e[2*i+1],e[2*i+2]);
}
ll maxi(ll a[],ll x,ll y,ll l,ll r,ll i)
{
    if(l>=x && r<=y)
return a[i];
if(r<x || l>y)
return 0;
return max(maxi(a,x,y,l,(l+r)/2,2*i+1),maxi(a,x,y,((l+r)/2)+1,r,2*i+2));
}
int main()
{
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll n,q;
    cin>>n>>q;
    ll a[n],i;
    for(i=0;i<n;i++)
    cin>>a[i];
    ll x=2,y=n;
while(y)
{
y/=2;
x*=2;
}
    ll o[x]={0},e[x]={0};
    o[0]=oddconstruct(a,o,0,n-1,0);
    e[0]=evenconstruct(a,e,0,n-1,0);
    while(q--)
    {
        ll x,y,z,out;
        cin>>x>>y>>z;
        if(x==1)
        update(o,e,y,z,0,n-1,0);
        else if(x==2)
        out=maxi(e,y-1,z-1,0,n-1,0);
        else
        out=maxi(o,y-1,z-1,0,n-1,0);
        if(x!=1)
        {
            if(out==0)
            cout<<"DNE\n";
            else
            cout<<out<<endl;
        }
    }
    return 0;
}