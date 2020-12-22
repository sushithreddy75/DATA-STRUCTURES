#include<bits/stdc++.h>
#define pb push_back
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
int flow(gtptr t)
{
	if(t->fc==NULL)
		return 1;
	vector<int>v;
	int max1=1;
	t=t->fc;
	while(t)
	{
		v.pb(flow(t));
		t=t->ns;
	}
	sort(v.rbegin(),v.rend());
	for(int i=0;i<v.size();i++)
		max1=max(v[i]+i,max1);
	return max1+1;
}
int main()
{
	freopen("in.txt","r",stdin);
	gtptr GT=NULL;
	string s;
	cin>>s;
	int i=0;
	create(GT,s,i);
	cout<<flow(GT)-1<<endl;
	return 0;
}