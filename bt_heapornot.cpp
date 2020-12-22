#include<bits/stdc++.h>
using namespace std;
struct btnode
{
	btnode *lc;
	int data;
	btnode *rc;
};
typedef btnode* btptr;
void construct(btptr &t,int c)
{
	t=new(btnode);
	t->data=c;
	t->lc=t->rc=NULL;
	cin>>c;
	if(c!=0)
		construct(t->lc,c);
	cin>>c;
	if(c!=0)
		construct(t->rc,c);
}
bool check(btptr t)
{
	queue<btptr>q;
	q.push(t);
	int flag=0;
	while(!q.empty())
	{
		btptr t=q.front();
		if(!t->lc)
			flag=1;
		if(flag && (t->lc||t->rc))
			break;
		if(!t->rc)
			flag=1;
		if(flag&&t->rc)
			break;
		if((t->lc && t->lc->data<t->data)||(t->rc && t->rc->data<t->data))
			return false;
		q.pop();
		if(t->lc)
			q.push(t->lc);
		if(t->rc)
			q.push(t->rc);
	}
	if(q.empty())
		return true;
	return false;
}
int main()
{
	int x;
	btptr T=NULL;
	cin>>x;
	construct(T,x);
	cout<<check(T)<<endl;
	return 0;
}