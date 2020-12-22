#include<bits/stdc++.h>
using namespace std;
struct bstnode
{
	bstnode *lc;
	int data;
	bstnode *rc;
	int hd,vd;
};
typedef bstnode* bstptr;
void insert(bstptr &t,int x,int h,int v)
{
	if(!t)
	{
		t=new(bstnode);
		t->data=x;
		t->hd=h;
		t->vd=v;
		t->lc=t->rc=NULL;
		return;
	}
	if(t->data>x)
		return insert(t->lc,x,h-1,v+1);
	insert(t->rc,x,h+1,v+1);
}
void verticalsum(bstptr t,int x,int &sum)
{
	if(!t)
		return;
	if(t->hd==x)
		sum+=t->data;
	verticalsum(t->lc,x,sum);
	verticalsum(t->rc,x,sum);
}
int main()
{
	int x;
	bstptr T=NULL;
	while(1)
	{
		cin>>x;
		if(x==-1)
			break;
		insert(T,x,0,0);
	}
	cin>>x;
	int sum=0;
	verticalsum(T,x,sum);
	cout<<sum<<endl;
	return 0;
}