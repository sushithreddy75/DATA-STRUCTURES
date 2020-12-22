#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef node* lptr;
struct mlnode
{
	int data;
	node *down;
	mlnode *next;
};
typedef mlnode* mlptr;
lptr create(int x)
{
	lptr t=new(node);
	t->data=x;
	t->next=NULL;
	return t;
}
mlptr mlcreate(int x)
{
	mlptr t=new(mlnode);
	t->data=x;
	t->next=NULL;
	t->down=NULL;
	return t;
}
void insert(lptr &t,int x)
{
	if(t==NULL)
	{
		t=create(x);
		return;
	}
	t->next=create(x);
	t=t->next;
}
void construct(mlptr &h,mlptr t)
{
	int x;
	cin>>x;
	if(x==-1)
		return;
	mlptr t1=mlcreate(x);
	if(h==NULL)
		t=h=t1;
	else
		t->next=t1;
	t=t1;
	//cin>>x;
	/*if(x==0)
		return construct(h,t);*/
	//if(x==1)
	{
		lptr h1=NULL,t2=NULL;
		while(1)
		{
			cin>>x;
			if(x==0)
				break;
			insert(t2,x);
			if(h1==NULL)
				h1=t2;
		}
		t->down=h1;
		construct(h,t);
	}
}
void qpush(deque<lptr>&q2,lptr t)
{
	q2.pf(NULL);
	while(q2.back())
	{
		q2.pf(q2.back());
		q2.popb();
	}
	q2.popb();
	q2.pb(t);
	q2.pb(NULL);
	while(q2.front())
	{
		q2.pb(q2.front());
		q2.popf();
	}
	q2.popf();
}
void sort(mlptr t,deque<mlptr>&q1,deque<lptr>&q2)
{
	q1.pb(NULL);
	q2.pb(NULL);
	q1.pf(t);
	q2.pf(t->down);
	int flag=0;
	while(q1.front() && q2.front())
	{
		if(q2.front()->data<q1.front()->data)
		{
			lptr t1=q2.front();
			q2.popf();
			if(t1->next)
			qpush(q2,t1->next);
		q2.pb(t1);
		continue;
		}
		//continue;
		mlptr t1=q1.front();
		q1.popf();
		if(t1->next)
		{
			//q1.popf();
			q1.pf(NULL);
			while(q1.back())
			{
				q1.pf(q1.back());
				q1.popb();
			}
			q1.popb();
			q1.pb(t1->next);
			q1.pb(NULL);
			while(q1.front())
			{
				q1.pb(q1.front());
				q1.popf();
			}
			q1.popf();
		}
		q1.pb(t1);	
		if(t1->down && flag)
			qpush(q2,t1->down);
			else
			flag=1;
	}
	while(q2.front())
	{
		lptr t1=q2.front();
		q2.popf();
		if(t1->next)
			qpush(q2,t1->next);
		q2.pb(t1);
	}
	q1.popf();
	q2.popf();
}
void print(deque<mlptr>q1,deque<lptr>q2)
{
	while(!q1.empty()&&!q2.empty())
	{
		if(q1.back()->data>q2.back()->data)
		{
			cout<<q1.back()->data<<" ";
			q1.popb();
			continue;
		}
		cout<<q2.back()->data<<" ";
		q2.popb();
	}
	while(!q1.empty())
	{
		cout<<q1.back()->data<<" ";
		q1.popb();
	}
	while(!q2.empty())
	{
		cout<<q2.back()->data<<" ";
		q2.popb();
	}
	cout<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	mlptr head=NULL;
	construct(head,head);
	deque<mlptr>q1;
	deque<lptr>q2;
	sort(head,q1,q2);
	print(q1,q2);
	return 0;
}