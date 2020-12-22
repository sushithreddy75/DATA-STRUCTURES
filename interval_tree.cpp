#include<iostream>
using namespace std;
struct itnode
{
	itnode *lc;
	int low,high,max;
	itnode *rc;
};
typedef itnode* itptr;
void construct(itptr &t,int low,int high,int max)
{
	if(!t)
	{
		t=new(itnode);
		t->low=low;
		t->high=t->max=high;
		return;
	}
	if(t->low==low && t->high==high)
	{
		t->max=max;
		if(t->lc && t->lc->max>t->max)
			t->max=t->lc->max;
		if(t->rc && t->rc->max>t->max)
			t->max=t->rc->max;
		return;
	}
	if(t->max<max)
			t->max=max;
	if(t->low>low)
		return construct(t->lc,low,high,max);
	construct(t->rc,low,high,max);
}
void search(itptr t,int l,int h,int &flag)
{
	if(!t)
		return;
	if(t->low>l && t->max>=h)
		search(t->lc,l,h,flag);
	else if(t->max>=h)
		search(t->rc,l,h,flag);
	if(flag && t->low<=l && t->high>=h)
	{
		flag=0;
		cout<<t->low<<" "<<t->high<<endl;
		return;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	itptr T=NULL;
	int q=8;
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x==1)
		{
			cin>>x;
			construct(T,y,z,x);
			continue;
		}
		int flag=1;
		search(T,y,z,flag);
	}
	return 0;
}