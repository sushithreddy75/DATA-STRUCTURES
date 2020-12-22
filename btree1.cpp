#include<bits/stdc++.h>
using namespace std;
struct bdnode
{
	int cnt;
	int *key;
	bdnode **ptr;
};
typedef bdnode* bdptr;
bdptr create(int d)
{
	bdptr t=new(bdnode);
	t->cnt=0;
	t->key=new int[d-1];
	t->ptr=new bdptr[d];
	return t;
}
void search(bdptr T,bdptr &t,bdptr &p,int x)
{
	if(!T)
		return;
	p=t;
	t=T;
	for(int i=0;i<T->cnt;i++)
	{
		if(T->key[i]==x)
			return;
		if(T->key[i]>x)
			return search(T->ptr[i],t,p,x);
	}
	search(T->ptr[T->cnt],t,p,x);
}
void push(bdptr t,int x)
{
	int i=0,j=0;
	bdptr b[t->cnt+2]={NULL};
	while(i<=t->cnt)
	{
		if(t->key[i]>x)
		{
			int y=t->key[i];
			t->key[i]=x;
			x=y;
		}
		i++;
		b[j++]=t->ptr[i];
	}
	for(i=0;i<=t->cnt && j<=t->cnt+1;i++)
	{
		while(b[j]!=NULL)
			j++;
		if(t->key[i]>b[j]->key[0])
		{
			t->ptr[i]=b[j];
			j++;
		}
	}
	if(j<=t->cnt+1)
		t->ptr[i]=b[j];
	t->cnt++;
}
void insert(bdptr &T,int d,int x,int y);
void splitting(bdptr &T,bdptr t,bdptr p,int x,int d)
{
	bdptr t1=create(d+1);
	int flag=0,i;
	for(i=0;i<=t->cnt;i++)
	{
		if(!flag && t->key[i]>x)
		{
			flag=1;
			t1->key[i]=x;
			i++;
		}
		if(flag)
			t1->key[i]=t->key[i-1];
		else
			t1->key[i]=t->key[i];
		t1->ptr[i]=t->ptr[i];
	}
	bdptr t2=create(d);
	for(i=0;i<d/2;i++)
		t->key[i]=t1->key[i];
	for(i=d/2+1;i<=d;i++)
		t2->key[i-d/2-1]=t1->key[i];
	t->cnt=d/2;
	t2->cnt=d-d/2-1;
	int j=0;
	for(i=0;i<d/2&&j<=d+1;i++)
	{
		while(t1->ptr[j]==NULL)
			j++;
		if(j>d+1)
			break;
		if(t->key[i]>t1->ptr[j]->key[0])
		{
			t->ptr[i]=t1->ptr[j];
			j++;
		}
	}
	if(j<=d+1 && t1->ptr[j] && t->key[i-1]<t1->ptr[j]->key[0])
		t->ptr[i]=t1->ptr[j];
	for(i=0;i<(d-d/2-1)&& j<=d;i++)
	{
		while(t1->ptr[j]==NULL)
			j++;
		if(j>d+1)
			break;
		if(t2->key[i]>t1->ptr[j]->key[0])
		{
			t2->ptr[i]=t1->ptr[j];
			j++;
		}
	}
	if(!p)
	{
		p=create(d);
		p->key[i]=t1->key[d/2];
		T=p;
		p->cnt=1;
		p->ptr[0]=t;
		p->ptr[1]=t2;
		return;
	}
	insert(T,d,t1->key[d/2],p->key[0]);
	bdptr t3=NULL,p3=NULL;
	search(T,t3,p3,t1->key[d/2]);
	for(i=0;i<t3->cnt;i++)
		if(t3->key[i]==t1->key[d/2])
			break;
	t3->ptr[i]=t;
	t3->ptr[i+1]=t2;
}
void insert(bdptr &T,int d,int x,int y)
{
	if(!T)
	{
		T=create(d);
		T->cnt=1;
		T->key[0]=x;
		return;
	}
	bdptr t=NULL,p=NULL;
	if(y)
		search(T,t,p,y);
	else
		search(T,t,p,x);
	if(t->cnt<d-1)
		return push(t,x);
	splitting(T,t,p,x,d);
}
int main()
{
	int d,n;
	cin>>d>>n;
	bdptr BT=NULL;
	while(n--)
	{
		int x;
		cin>>x;
		insert(BT,d,x,0);
	}
}