#include<iostream>
using namespace std;
struct dlnode
{
	int data;
	dlnode *right,*left;
};
typedef dlnode* dlptr;
dlptr create(int x)
{
	dlptr t=new(dlnode);
	t->data=x;
	t->left=t->right=NULL;
	return t;
}
void insert(dlptr &h,int x)
{
	if(h==NULL)
	{
		h=create(x);
		return;
	}
	dlptr t=h;
	while(t->right!=NULL)
		t=t->right;
	t->right=create(x);
	t->right->left=t;
}
int main()
{
	dlptr head=NULL;
	while(1)
	{
		int n;cin>>n;
		if(n==-1)
			break;
		insert(head,n);
	}
	int s;cin>>s;
	dlptr l=head;
	while(l->right!=NULL)
		l=l->right;
	dlptr t1=head,t2=head->right,t3=l;
	while(t1->data<s/2 && t1->right!=NULL)
	{
		t2=t1->right,t3=l;
		int x=s-2*t1->data;
		while(t2!=t3 && x>0)
		{
			if(t2->data+t3->data==x)
			{
				cout<<t1->data<<" "<<t2->data<<" "<<t3->data<<endl;
				t3=t3->left;
			}
			else if(t2->data+t3->data>x)
				t3=t3->left;
			else
				t2=t2->right;
		}
		t1=t1->right;
	}
}