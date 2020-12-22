#include<iostream>
using namespace std;
union uni 
{
    int x;
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
	while(1)
	{
		cout<<"0 to stop,1 to dequeue,2 to enqueue,3 for front element: ";
		int x;
		cin>>x;
		if(x==0)
			break;
		if(x==2)
		{
			uni u;
			cout<<"1 for int,2 for char: ";
			int tag;
			cin>>tag;
			if(tag==1)
			{
				cout<<"enter int: ";
				cin>>u.x;
			}
			else
			{
				cout<<"enter char: ";
				cin>>u.c;
			}
			q.enqueue(u,tag);
		}
		else if(x==1)
			q.dequeue();
		else
		{
			int tag;
			uni u=q.front(tag);
			if(tag==1)
				cout<<"front element: "<<u.x<<endl;
			else
				cout<<"front element: "<<u.c<<endl;
		}
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