#include<iostream>
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
	if(x==-2)
		return;
	mlptr t1=mlcreate(x);
	if(h==NULL)
		t=h=t1;
	else
		t->next=t1;
	t=t1;
	cin>>x;
	if(x==0)
		return construct(h,t);
	if(x==1)
	{
		lptr h1=NULL,t2=NULL;
		while(1)
		{
			cin>>x;
			if(x==-1)
				break;
			insert(t2,x);
			if(h1==NULL)
				h1=t2;
		}
		t->down=h1;
		construct(h,t);
	}
}
void find(mlptr t,int min,int &max)
{
	if(t==NULL)
		return;
	if(t->data>max)
		return;
	if(t->data<max && t->data>min)
	{
		max=t->data;
		return;
	}
	if(t->data<min)
	{
		lptr t1=t->down;
		while(t1!=NULL)
		{
			if(t1->data>max)
				break;
			if(t1->data>min && t1->data<max)
				max=t1->data;
			t1=t1->next;
		}
	}
	find(t->next,min,max);
}
void sort(mlptr h,int &min,int &max)
{
	if(h==NULL)
		return;
	min=max;
	if(h->data>max)
		max=h->data;
	find(h->next,min,max);
	if(min!=max)
	cout<<max<<" ";
	if(h->data==max||h->data<min)
	{
		min=max;
		lptr t=h->down;
		while(t!=NULL)
		{
			//min=max;
			if(t->data<min)
			{
				t=t->next;
				continue;
			}
			min=max;
			max=t->data;
			find(h->next,min,max);
			cout<<max<<" ";
			if(max==t->data)
				t=t->next;
		}
		sort(h->next,min,max);
	}
	else
	{
		min=max;
		sort(h,min,max);
		return;
	}
	
}
int main()
{
	mlptr head=NULL;
	construct(head,head);
	lptr h=NULL;int min=0,max=0;
	sort(head,min,max);
	//	print(head);
	cout<<endl;
	return 0;
}
void queue::enqueue(lptr x)
{
	if((r+1)%size==f)
	{
		cout<<"queue is full\n";
		return;
	}
	if(f==-1)
	{
		f=0;r=0;
	}
	else
		r=(r+1)%size;
	a[r]=x;
}
void queue::dequeue()
{
	if(f==-1)
	{
		cout<<"empty\n";
		return;
	}
	if(r==f)
	{
		r=-1;
		f=-1;
		return;
	}
	f++;
	f%=size;
}
lptr queue::front()
{
	return a[f];
}
bool queue::empty()
{
    if(f==-1)
    return true;
    return false;
}
lptr queue::rear()
{
	return a[r];
}
