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
void construct(string ldr,string dlr,int &k,int i,int j,btptr &t)
{
	if(i>j || dlr[k]=='\0')
		return;
	t=new(btnode);
	t->data=dlr[k];
	k++;
	t->lc=t->rc=NULL;
	construct(ldr,dlr,k,i,find(ldr,t->data,i,j)-1,t->lc);
	construct(ldr,dlr,k,find(ldr,t->data,i,j)+1,j,t->rc);
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
	string ldr,dlr;
	cin>>ldr>>dlr;
	int i=0;
	btptr T=NULL;
	construct(ldr,dlr,i,0,dlr.size()-1,T);
	preorder(T);cout<<endl;
}