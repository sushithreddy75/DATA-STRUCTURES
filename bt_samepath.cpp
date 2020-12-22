#include<iostream>
using namespace std;
struct btnode
{
	btnode *lc;
	int data;
	btnode *rc;
	int at,dt;
};
typedef btnode* btptr;
void construct(btptr &t,int x,int &i)
{
	t=new(btnode);
	t->data=x;
	t->lc=t->rc=NULL;
	t->at=i;
	i++;
	cin>>x;
	if(x)
		construct(t->lc,x,i);
	cin>>x;
	if(x)
		construct(t->rc,x,i);
	t->dt=i;
	i++;
}
bool search(btptr t,btptr &a,btptr &b,int x,int y)
{
	if(!t)
		return false;
	if(t->data==x||t->data==y)
	{
		b=a;
		a=t;
		if(a&&b)
		{
			if((a->at-b->at)*(a->dt-b->dt)<0)
				return true;
			return false;
		}
	}
	return (search(t->lc,a,b,x,y)||search(t->rc,a,b,x,y));
}
int main()
{
	freopen("in.txt","r",stdin);
	btptr T=NULL;
	int x,i=1;
	cin>>x;
	construct(T,x,i);
	int y;
	cin>>x>>y;
	btptr a=NULL,b=NULL;
	cout<<search(T,a,b,x,y)<<endl;
}