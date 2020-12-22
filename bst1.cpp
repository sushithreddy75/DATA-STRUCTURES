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
void levelorder(bstptr t)
{
	if(t==NULL)
		return;
	levelorder(t->lchild);
	cout<<t->data<<" ";
	levelorder(t->rchild);
}
void minmax(bstptr t,int &min,int &max)
{
	if(t==NULL)
		return;
	if(t->lchild==NULL && min==-1)
		min=t->data;
	minmax(t->lchild,min,max);
	if(t->rchild==NULL)
	{
		if(t->data>max)
			max=t->data;
	}
	minmax(t->rchild,min,max);
}
bstptr find(bstptr t,int x)
{
	if(t==NULL)
		return t;
	if(t->data==x)
		return t;
	if(x>t->data)
		return find(t->rchild,x);
	return find(t->lchild,x);
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
	int min=-1,max=-1;
	minmax(T,min,max);
	cout<<min<<" "<<max<<endl;
	levelorder(T);cout<<endl;
	int x;cin>>x;
	bstptr t=find(T,x);
	if(t)
		cout<<"found\n";
	else
		cout<<x<<" is not present\n";
}