#include<iostream>
using namespace std;
struct gtnode
{
	int data;
	gtnode *fc,*ns;
};
typedef gtnode* gtptr;
gtptr create(int c)
{
	gtptr t=new(gtnode);
	t->data=c;
	t->fc=t->ns=NULL;
	return t;
}
void create(gtptr &t,int x)
{
	t=create(x);
	cin>>x;
	if(x)
	create(t->fc,x);
	cin>>x;
	if(x)
	create(t->ns,x);
}
int depth(gtptr t)
{
	if(t->fc==NULL)
		return 0;
	t=t->fc;
	int ret=0;
	while(t)
	{
		ret=max(ret,depth(t));
		t=t->ns;
	}
	return ret+1;
}
bool dfs(gtptr t,int c,int dep)
{
	if(dep<0)
		return false;
	if(t->data==c)
		return true;
	t=t->fc;
	while(t)
	{
		if(dfs(t,c,dep-1))
			return true;
		t=t->ns;
	}
	return false;
}
bool iddfs(gtptr t,int c,int maxd)
{
	for(int i=0;i<=maxd;i++)
	{
		if(dfs(t,c,i))
			return true;
	}
	return false;
}
int main()
{
	freopen("in.txt","r",stdin);
	gtptr GT=NULL;
	int s;
	cin>>s;
	int i=0;
	create(GT,s);
	int maxd=depth(GT);
	int x;
	cin>>x;
	while(x--)
	{
	int c;
	cin>>c;
	cout<<iddfs(GT,c,maxd)<<endl;
}
	return 0;
}