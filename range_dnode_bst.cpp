#include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
typedef bstnode* bstptr;
void insert(bstptr &t,int x)
{
	if(t==NULL)
	{
		t=new(bstnode);
		t->data=x;
		t->lchild=t->rchild=NULL;
		return;
	}
	if(t->data>x)
		return insert(t->lchild,x);
	insert(t->rchild,x);
}
int mini(bstptr t)
{
	if(t==NULL)
		return 0;
	if(t->lchild==NULL)
		return t->data;
	return mini(t->lchild);
}
int maxi(bstptr t)
{
	if(t==NULL)
		return 0;
	if(t->rchild==NULL)
		return t->data;
	return maxi(t->rchild);
}
void range(bstptr t,int min,int max)
{
	if(t==NULL)
		return;
	int mi=maxi(t->lchild);
	int ma=mini(t->rchild);
	if(mi==0)
		mi=min;
	if(ma==0)
		ma=max;
	cout<<t->data<<" "<<mi+1<<" "<<ma-1<<endl;
	if(ma-mi==2)
		cout<<t->data<<" is dead-node\n";
	range(t->lchild,min,t->data);
	range(t->rchild,t->data,max);
}
int main()
{
	bstptr T=NULL;
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		insert(T,n);
	}
	range(T,0,1000);
	return 0;
}