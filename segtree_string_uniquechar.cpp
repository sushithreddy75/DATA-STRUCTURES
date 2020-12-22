#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first 
#define S second
using namespace std;
string construct(string a[],string s,ll l,ll r,ll i)
{
    if(l==r)
    {
        a[i]=s[l];
        return a[i];
    }
    string x=construct(a,s,l,(l+r)/2,2*i+1);
    string y=construct(a,s,(l+r)/2+1,r,2*i+2);
    ll count[26]={0},j;
    //string z=x+y;
    a[i]="";
    for(j=0;x[j]!='\0';j++)
    {
        count[x[j]-'a']++;
        if(count[x[j]-'a']==1)
        a[i]+=x[j];
    }
    for(j=0;y[j]!='\0';j++)
    {
        count[y[j]-'a']++;
        if(count[y[j]-'a']==1)
        a[i]+=y[j];
    }
    return a[i];
}
void update(string a[],ll x,char y,ll l,ll r,ll i)
{
    if(l>r || x<l || x>r)
    return;
    if(l==r && l==x)
    a[i]=y;
    if(l==r)
    return;
    update(a,x,y,l,(l+r)/2,2*i+1);update(a,x,y,(l+r)/2+1,r,2*i+2);
    //string z=a[2*i+1]+a[2*i+2];
    ll count[26]={0};
    a[i]="";
    for(ll j=0;a[2*i+1][j]!='\0';j++)
    {
        count[a[2*i+1][j]-'a']++;
        if(count[a[2*i+1][j]-'a']==1)
        a[i]+=a[2*i+1][j];
    }
    for(ll j=0;a[2*i+2][j]!='\0';j++)
    {
        count[a[2*i+2][j]-'a']++;
        if(count[a[2*i+2][j]-'a']==1)
        a[i]+=a[2*i+2][j];
    }
}
string query(string a[],ll x,ll y,ll l,ll r,ll i)
{
    if(x<=l && y>=r)
    return a[i];
    if(y<l || x>r)
    return "";
    string x1=query(a,x,y,l,(l+r)/2,2*i+1);
    string x2=query(a,x,y,(l+r)/2+1,r,2*i+2);
    string z=x1+x2;
    string out="";
    ll count[26]={0};
    for(ll j=0;x1[j]!='\0';j++)
    {
        count[x1[j]-'a']++;
        if(count[x1[j]-'a']==1)
        out+=x1[j];
    }
    for(ll j=0;x2[j]!='\0';j++)
    {
        count[x2[j]-'a']++;
        if(count[x2[j]-'a']==1)
        out+=x2[j];
    }
    return out;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ll n=0;
	while(s[n]!='\0')
	n++;
	ll x=2,y=n;
	while(y)
	{
	    x*=2;
	    y/=2;
	}
	x--;
	string a[x];
	a[0]=construct(a,s,0,n-1,0);
	ll q;
	cin>>q;
	while(q--)
	{
	    ll x,y;
	    cin>>x>>y;
	    if(x==1)
	    {
	        char z;cin>>z;
	    update(a,y-1,z,0,n-1,0);
	    }
	    else
	    {
	        ll z;cin>>z;
	    string out=query(a,y-1,z-1,0,n-1,0);
	    //cout<<out<<endl;
	        cout<<out.size()<<endl;
	    }
	}
    return 0;
}