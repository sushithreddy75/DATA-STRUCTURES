#include<iostream>
using namespace std;
struct kdnode
{
	kdnode *lc;
	int *data;
	int d;
	kdnode *rc;
};
typedef kdnode* kdptr;
kdptr create(int n)
{
	kdptr t=new(kdnode);
	t->d=n;
	t->lc=t->rc=NULL;
	t->data=new int[n];
	return t;
}
void insert(kdptr &t,int a[],int i,int d)
{
	if(t==NULL)
	{
		t=create(d);
		for(i=0;i<d;i++)
			t->data[i]=a[i];
		return;
	}
	if(t->data[i]>a[i])
		return insert(t->lc,a,(i+1)%d,d);
	insert(t->rc,a,(i+1)%d,d);
}
bool search(kdptr t,int a[],int i,int d)
{
	if(!t)
		return false;
	if(t->data[i]==a[i])
	{
		int j;
		for(j=0;j<d;j++)
		{
			if(a[j]!=t->data[j])
				break;
		}
		if(j==d)
			return true;
	}
	if(t->data[i]>a[i])
		return search(t->lc,a,(i+1)%d,d);
	return search(t->rc,a,(i+1)%d,d);
}
int main()
{
	kdptr T=NULL;
	int d;
	cin>>d;
	int a[d];
	while(1)
	{
		int x;
		cin>>x;
		if(x==-1)
			break;
		for(int i=0;i<d;i++)
			cin>>a[i];
		insert(T,a,0,d);
	}
	//searching input
	for(int i=0;i<d;i++)
		cin>>a[i];
	cout<<search(T,a,0,d)<<endl;
}