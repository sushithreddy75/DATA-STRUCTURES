#include<iostream>
using namespace std;
struct rnode;
struct snode
{
	int rno;
	rnode *r;
};
struct cnode
{
	char c;
	rnode *r;
};
struct rnode
{
	int t1,t2;
	union 
	{
		rnode *r;
		cnode *c;
	}cnext;
	union
	{
		rnode *r;
		snode *s;
	}snext;
};
typedef snode* sptr;
typedef cnode* cptr;
typedef rnode* rptr;
void insert(cptr c,sptr s)
{
	rptr t=new(rnode);
	t->t1=t->t2=1;
	t->cnext.c=c;
	t->snext.s=s;
	if(c->r==NULL)
		c->r=t;
	else
	{
		rptr t1=c->r;
		while(t1->t1==0)
			t1=t1->cnext.r;
		t1->t1=0;
		t1->cnext.r=t;
		
	}
	if(s->r==NULL)
		s->r=t;
	else
	{
		rptr t1=s->r;
		while(t1->t2==0)
			t1=t1->snext.r;
		t1->t2=0;
		t1->snext.r=t;
		t->snext.s=s;
	}
}
char find(rptr t)
{
	while(t->t1==0)
		t=t->cnext.r;
	return t->cnext.c->c;
}
void printc(rptr t)
{
	while(t->t2==0)
	{
		cout<<char(find(t))<<" ";
		t=t->snext.r;
	}
	cout<<char(find(t))<<" ";
}
int findc(rptr t)
{
	while(t->t2==0)
		t=t->snext.r;
	return t->snext.s->rno;
}
void print(rptr t)
{
	while(t->t1==0)
	{
		cout<<findc(t)<<" ";
		t=t->cnext.r;
	}
	cout<<findc(t);
}
int main()
{
	sptr s[26];cptr c[26];
	for(int i=0;i<26;i++)
	{
		s[i]=new(snode);
		s[i]->rno=i+1;
		s[i]->r=NULL;
		c[i]=new(cnode);
		c[i]->c=char('A'+i);
		c[i]->r=NULL;
	}
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		char x;cin>>x;
		insert(c[x-'A'],s[n-1]);
	}
	int i;
	//cout<<"hfh";	
	cin>>i;
	printc(s[i-1]->r);cout<<endl;
	cin>>i;
	printc(s[i-1]->r);cout<<endl;
	char c1;
	cin>>c1;
	print(c[c1-'A']->r);cout<<endl;
	cin>>c1;
	print(c[c1-'A']->r);cout<<endl;
}