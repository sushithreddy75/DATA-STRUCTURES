#include<iostream>
#include<queue>
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
void create(gtptr &t)
{
	queue<gtptr>q;
	t=create('.');
	q.push(t);
	while(!q.empty())
	{
		int n;char c;
		cin>>c>>n;
		gtptr t1=q.front();
		t1->data=c;
		if(n)
		{
			t1->fc=create('.');
			t1=t1->fc;
			q.push(t1);
		
		while(--n)
		{
			t1->ns=create('.');
			q.push(t1->ns);
			t1=t1->ns;
		}}
		q.pop();
	}
}
void print(gtptr t)
{
	if(!t->fc)
		{cout<<t->data<<".";
	return;}
	cout<<t->data;
	t=t->fc;
	while(t)
	{
		print(t);
		t=t->ns;
	}
	cout<<".";
}
int main()
{
	freopen("in.txt","r",stdin);
	gtptr GT=NULL;
	create(GT);
		print(GT);cout<<".\n";
}