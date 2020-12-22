#include<iostream>
using namespace std;
struct cnode;
struct snode;
struct rnode;
typedef cnode* cptr;
typedef snode* sptr;
typedef rnode* rptr;
struct cnode
{
	char crs;
	rptr reg;
};
struct snode
{
	int rno;
	rptr reg;
};
struct rnode
{
	int rno;
	rptr next,cnxt,snxt;
	char crs;
};
void insert(rptr &r,sptr s,cptr c,int rno,char crs)
{
	if(r==NULL)
	{
		r=new(rnode);
		r->rno=rno;r->crs=crs;
		r->next=r->cnxt=r->snxt=NULL;
		c->reg=s->reg=r;
		return;
	}
	rptr t=r;
	while(t->next!=NULL)
		t=t->next;
	rptr s1=s->reg,c1=c->reg;
	while(s1!=NULL && s1->snxt!=NULL)
		s1=s1->snxt;
	while(c1!=NULL && c1->cnxt!=NULL)
		c1=c1->cnxt;
	/*if(c1!=NULL)
		cout<<c1->rno<<" ";
	if(s1!=NULL)
		cout<<s1->crs<<endl;*/
	rptr t1=new(rnode);
	t1->rno=rno;t1->crs=crs;
	t1->next=t1->cnxt=t1->snxt=NULL;
	t->next=t1;
	if(s->reg==NULL)
		s->reg=t1;
	else
		s1->snxt=t1;
	if(c->reg==NULL)
		c->reg=t1;
	else
		c1->cnxt=t1;
}
void printc(rptr t)
{
	if(t==NULL)
	{
		cout<<endl;
		return;
	}
	cout<<t->crs<<" ";
	printc(t->snxt);
}
void prints(rptr t)
{
	if(t==NULL)
	{
		cout<<endl;
		return;
	}
	cout<<t->rno<<" ";
	prints(t->cnxt);
}
void printreg(rptr t)
{
	if(t==NULL)
		return;
	cout<<t->rno<<" "<<t->crs<<endl;
	printreg(t->next);
}
int main()
{
	rptr r=NULL;
	cptr c[5];sptr s[5];
	for(int i=0;i<5;i++)
	{
		c[i]=new(cnode);
		c[i]->crs=char('A'+i);
		s[i]=new(snode);
		s[i]->rno=i+1;
		c[i]->reg=s[i]->reg=NULL;
	}
	while(1)
	{
		int n;char c1;
		cin>>n>>c1;
		if(n==-1 && c1=='#')
			break;
		insert(r,s[n-1],c[int(c1-'A')],n,c1);
	}
	printreg(r);cout<<endl;
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		cout<<n<<" ";
		printc(s[n-1]->reg);
	}
	cout<<endl;
	while(1)
	{
		char crs;cin>>crs;
		if(crs=='#')
			break;
		cout<<crs<<" ";
		prints(c[int(crs-'A')]->reg);
	}
	cout<<endl;
}