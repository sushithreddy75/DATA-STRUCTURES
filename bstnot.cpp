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
void satisfied(bstptr t,int min,int max)
{
	if(t==NULL)
		return;
	int mi=maxi(t->lchild);
	int ma=mini(t->rchild);
	if(mi==0)
		mi=min;
	if(ma==0)
		ma=max;
	if(t->data<mi || t->data>ma)
		cout<<"not satisfied at "<<t->data<<endl;
	satisfied(t->lchild,min,t->data);
	satisfied(t->rchild,t->data,max);
}
void corrupt(bstptr t,int x)
{
	if(t==NULL)
		return;
	if(t->data==x)
	{
		t->data=x+10;
		return;
	}
	if(x>t->data)
		return corrupt(t->rchild,x);
	return corrupt(t->lchild,x);
}
int main()
{
	bstptr T=NULL;
	insert(T,18);
	insert(T,9);
	insert(T,5);
	insert(T,15);
	insert(T,12);
	insert(T,17);
	insert(T,36);
	insert(T,27);
	insert(T,72);
	insert(T,63);
	corrupt(T,9);
	satisfied(T,0,1000);	
}