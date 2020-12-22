#include<iostream>
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
	int n;char c;
	cin>>c>>n;
	t=create(c);
	for(int i=0;i<n;i++)
	{
		if(!i)
			create(t->fc);
		else
		{
			gtptr t1=NULL;
			create(t1);
			gtptr t2=t->fc;
			while(t2->ns)
				t2=t2->ns;
			t2->ns=t1;
		}
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