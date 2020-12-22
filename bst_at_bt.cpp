#include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lc;
	int data;
	bstnode *rc;
	int at,dt;
};
typedef bstnode* bstptr;
void insert(bstptr &t,int x)
{
	if(!t)
	{
		t=new(bstnode);
		t->data=x;
		t->lc=t->rc=NULL;
		return;
	}
	if(t->data>x)
		return insert(t->lc,x);
	insert(t->rc,x);
}
void settime(bstptr t,int &i)
{
	if(!t)
		return;
	t->at=i;
	i++;
	settime(t->lc,i);
	settime(t->rc,i);
	t->dt=i;
	i++;
}
void inorder(bstptr t)
{
	if(!t)
		return;
	inorder(t->lc);
	cout<<t->data<<" "<<t->at<<" "<<t->dt<<endl;
	inorder(t->rc);
}
int main()
{
	bstptr T=NULL;
	int x;
	while(1)
	{
		cin>>x;
		if(x==-1)
			break;
		insert(T,x);
	}
	x=0;
	settime(T,x);
	inorder(T);
}