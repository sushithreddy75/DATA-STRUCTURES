#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
using namespace std;
struct gtnode
{
	char data;
	gtnode *fc,*ns;
};
typedef gtnode* gtptr;
gtptr create(char c)
{
	gtptr t=new(gtnode);
	t->data=c;
	t->fc=t->ns=NULL;
	return t;
}
void create(gtptr &t,string c,int &i)
{
	if(c[i]=='\0')
	return;
if(c[i]=='.')
{
	i++;
	return;
}
if(c[i]!='.')
	t=create(c[i]);
i++;
	create(t->fc,c,i);
	create(t->ns,c,i);
}
bool check(gtptr t,gtptr t1)
{
	if(!t&&!t1)
		return true;
	if(!t||!t1)
		return false;
	deque<gtptr>q;
	t=t->fc;t1=t1->fc;
	if(!t&&!t1)
		return true;
	if(!t||!t1)
		return false;
	int n=0;
	while(t)
	{
		q.pb(t);
		t=t->ns;
		n++;
	}
	while(t1 && n--)
	{
		q.pb(t1);
		t1=t1->ns;
	}
	if(t1||n)
		return false;
	bool 	val=true;
	while(!q.empty())
	{
		t=q.front();
		t1=q.back();
		val=val&&check(t,t1);
		q.popb();q.popf();
	}
	return val;
}
bool check(gtptr t)
{
	if(t==NULL)
		return true;
	deque<gtptr>q;
	t=t->fc;
	while(t)
	{
		q.pb(t);
		t=t->ns;
	}
	bool val=true;
	while(!q.empty() && val)
	{
		gtptr t=q.front();
		gtptr t1=q.back();
		if(t==t1)
			return val&&check(t);
		val=val&&check(t,t1);
		q.popb();q.popf();
	}
	return val;
}
int main()
{
	freopen("in.txt","r",stdin);
	int x=2;
	while(x--){
	string s;
	cin>>s;
	gtptr GT=NULL;
	int i=0;
	create(GT,s,i);
	cout<<check(GT)<<endl;}
	return 0;
}