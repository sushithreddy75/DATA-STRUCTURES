#include<iostream>
using namespace std;
struct btnode
{
	btnode *lc;
	char data;
	btnode *rc;
};
typedef btnode* btptr;
int find(string a,char c,int i,int j)
{
	for(i;i<=j;i++)
	{
		if(a[i]==c)
			return i;
	}
	return i;
}
void construct(string ldr,string lrd,int &k,int i,int j,btptr &t)
{
	if(k<0 || i>j)
		return;
	t=new(btnode);
	t->data=lrd[k];
	k--;
	t->lc=t->rc=NULL;
	if(i==j)
		return;
	construct(ldr,lrd,k,find(ldr,t->data,i,j)+1,j,t->rc);
	construct(ldr,lrd,k,i,find(ldr,t->data,i,j)-1,t->lc);
}
void preorder(btptr t)
{
	cout<<t->data<<" ";
	if(t->lc)
		preorder(t->lc);
	if(t->rc)
		preorder(t->rc);
}
int main()
{
	string ldr,lrd;
	cin>>ldr>>lrd;
	int i=lrd.size()-1;
	btptr T=NULL;
	construct(ldr,lrd,i,0,i,T);
	preorder(T);cout<<endl;
}