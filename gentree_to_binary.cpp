#include<iostream>
using namespace std;
struct gtnode
{
	char data;
	gtnode *fc,*ns,*x;
};
typedef gtnode* gtptr;
gtptr create(char c)
{
	gtptr t=new(gtnode);
	t->data=c;
	t->fc=t->ns=t->x=NULL;
	return t;
}
void create(gtptr &t,string s,int &i)
{
	if(s[i]=='.')
	{
		i++;
		return;
	}
	t=create(s[i]);
	i++;
	create(t->fc,s,i);
	t->x=t->fc;
	create(t->ns,s,i);
}
void split(gtptr t,int &q,int ref)
{
	if(!t)
	{
		q=1;
		cout<<".";
		return;
	}
	if(t->x==NULL)
	{
		q=1;
		cout<<t->data<<"..";
		return;
	}
	gtptr t1=t->x;
	gtptr t2=t->x->ns;
	cout<<t->data;
	int q1=0,q2=0;
	split(t1,q1,1);
	split(t2,q2,1);
	if(q1 && q2)
	{
		t->x=t->x->ns;
		if(t->x)
			t->x=t->x->ns;
		if(!t->x)
			q=1;
		//cout<<".";
	}
	else if(q1)
		t->x=t->x->ns;
	else if(q2)
	{
		if(t->x->ns)
			t->x->ns=t->x->ns->ns;
	}
	if(ref==0)
	{
		cout<<endl;
		if(t->x)
			split(t,q,ref);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	string s;
	cin>>s;
	gtptr GT=NULL;
	int i=0;
	create(GT,s,i);
	split(GT,i,0);
}