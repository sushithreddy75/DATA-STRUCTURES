#include<iostream>
#include<queue>
using namespace std;
struct btnode
{
	btnode *lc;
	int data;
	btnode *rc;
};
typedef btnode* btptr;
void construct(btptr &t,int x)
{
	t=new(btnode);
	t->data=x;
	t->lc=t->rc=NULL;
	cin>>x;
	if(x)
		construct(t->lc,x);
	cin>>x;
	if(x)
		construct(t->rc,x);
}
void print(btptr t)
{
	queue<btptr>q;
	q.push(t);
	while(!q.empty())
	{
		int flag=1,prev=-1,f=0,fp=0;
		q.push(NULL);
		queue<int>q1;
		while(q.front())
		{
			if(q.front()->lc)
				q.push(q.front()->lc);
			if(q.front()->rc)
				q.push(q.front()->rc);
			q1.push(q.front()->data);
			if(prev==-1)
			{
				prev=q.front()->data;
				q.pop();
				continue;
			}
			if(fp==0)
			{
				if(q.front()->data>prev)
					f=1;
				else
					f=0;
				fp=1;
				if(q.front()->data==prev)
					flag=0;
				prev=q.front()->data;
				q.pop();
				continue;
			}
			if((q.front()->data>prev && f==1)||(q.front()->data<prev && f==0)||q.front()->data==prev)
				flag=0;
			if(q.front()->data>prev)
				f=1;
			else
				f=0;
			prev=q.front()->data;
			q.pop();
		}
		q.pop();
		if(flag && fp)
		{
			while(!q1.empty())
			{
				cout<<q1.front()<<" ";
				q1.pop();
			}
			cout<<endl;
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	int x;cin>>x;
	btptr T=NULL;
	construct(T,x);
	print(T);
}