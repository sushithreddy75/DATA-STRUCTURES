#include<iostream>
#include<stack>
#define lc lchild
#define rc rchild
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
	int s;cin>>s;
	stack<bstptr>s1,s2;
	bstptr t=T;
	while(t!=NULL)
	{
		s1.push(t);
		t=t->lc;
	}
	t=T;
	while(t!=NULL)
	{
		s2.push(t);
		t=t->rc;
	}
	while(!s1.empty() && !s2.empty() && s1.top()->data<s2.top()->data)
	{
		if(s1.top()->data+s2.top()->data==s)
		{
			if(s1.top()!=s2.top())
			cout<<s1.top()->data<<" "<<s2.top()->data<<endl;
			t=s1.top();
			s1.pop();
			t=t->rc;
			while(t)
			{
				s1.push(t);
				t=t->lc;
			}
			t=s2.top();
			s2.pop();
			t=t->lc;
			while(t)
			{
				s2.push(t);
				t=t->rc;
			}
			continue;
		}
		if(s1.top()->data+s2.top()->data<s)
		{
			t=s1.top();
			s1.pop();
			t=t->rc;
			while(t)
			{
				s1.push(t);
				t=t->lc;
			}
			continue;
		}
		t=s2.top();
		s2.pop();
		t=t->lc;
		while(t)
		{
			s2.push(t);
			t=t->rc;
		}
	}
}