#include<bits/stdc++.h>
using namespace std;
struct qtnode
{
	int key;
	qtnode **child;
};
typedef qtnode* qtptr;
qtptr	 create(int x)
{
	qtptr t=new(qtnode);
	t->key=x;
	t->child=new qtptr[4];
	return t;
}
void swap(qtptr t1,qtptr t2)
{
	int x=t1->key;
	t1->key=t2->key;
	t2->key=x;
}
void heapify(qtptr t)
{
	for(int i=0;i<4;i++)
	{
		if(t->child[i])
		{
			heapify(t->child[i]);
			if(t->child[i]->key<t->key)
				swap(t->child[i],t);
		}
		else
		return;
	}
}
void insert(qtptr &t)
{
	queue<qtptr*>q;
	q.push(&t);
	while(!q.empty())
	{
		int x;
		cin>>x;
		if(x==-1)
			return;
		qtptr t1=create(x);
		*q.front()=t1;
		for(int i=0;i<4;i++)
			q.push(&(t1->child[i]));
		q.pop();
		heapify(t);
	}
}
void levelorder(qtptr t)
{
	queue<qtptr>q;
	q.push(t);
	while(!q.empty())
	{
		q.push(NULL);
		while(q.front())
		{
			cout<<q.front()->key<<" ";
			int i;
			for(i=0;i<4;i++)
			{
				if(q.front()->child[i])
					q.push(q.front()->child[i]);
				else
					break;
			}
			q.pop();
		}
		cout<<endl;
		q.pop();
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	qtptr H=NULL;
	insert(H);
	levelorder(H);
}