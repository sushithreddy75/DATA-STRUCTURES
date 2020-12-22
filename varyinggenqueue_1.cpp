#include<iostream>
using namespace std;
union uni 
{
    int x;
    float f;
    char c;
};
struct queuestr
{
	int f,r,size;
	uni a[100];
	int tag[100];
	void enqueue(uni &x,int tag);
	void dequeue();
	uni front(int&);
	bool empty();
};
int main()
{
	queuestr q;
	q.f=q.r=-1;
	q.size=100;
	int a[100]={0};
	int i=0;
	while(1)
	{
		int c=0;
		cout<<"-1 to stop,1 to enter ";
		int x;cin>>x;
		if(x==-1)
			break;
		while(1)
		{
			cout<<"1 for int,2 for float,3 for char,-1 to stop ";
			cin>>x;
			if(x==-1)
				break;
			c++;
			cout<<"enter value\n";
			uni u;
			if(x==1)
				cin>>u.x;
			if(x==2)
				cin>>u.f;
			if(x==3)
				cin>>u.c;
			q.enqueue(u,x);
		}
		a[i++]=c;
	}
	cout<<"printing\n";
	for(int j=0;j<i;j++)
	{
		while(a[j]--)
		{
			int t;
			uni u=q.front(t);
			if(t==1)
				cout<<u.x<<" ";
			if(t==2)
				cout<<u.f<<" ";
			if(t==3)
				cout<<u.c<<" ";
			q.dequeue();
		}
		cout<<endl;
	}
}
void queuestr::enqueue(uni &x,int t)
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
	tag[r]=t;
}
void queuestr::dequeue()
{
	if(f==-1)
	{
		cout<<"empty\n";
		return;
	}
	if(r==f)
	{
	    //a[r]="***";
	    int t=tag[r];
		r=-1;
		f=-1;
		return;
	}
	//a[f]="***";
	int t=tag[f];
	f++;
	f%=size;
	//return t;
}
uni queuestr::front(int &t)
{
	t=tag[f];
	return a[f];
}
bool queuestr::empty()
{
	if(f==-1)
		return true;
	return false;
}