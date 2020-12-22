#include<iostream>
using namespace std;
struct queue
{
	int f,r,size;
	int a[100];
	void enqueue(int x);
	void dequeue();
	int front();
	int rear();
	bool empty();
};
void recursive(queue &q,int n,int j,int min);
void iterative(queue &q,int n);
int main()
{
	queue q;
	q.f=q.r=-1;
	q.size=100;
	int x,n;
	cout<<"enter 1 for recursive 2 for iterative: ";
	cin>>x;
	cout<<"enter no of elements in queue: ";
	cin>>n;
	cout<<"enter elements\n";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		q.enqueue(x);
	}
	if(x==1)
		recursive(q,n,0,-1);
	else
		iterative(q,n);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.dequeue();
	}
	cout<<endl;
	return 0;
}
void recursive(queue &q,int n,int j,int min)
{
	if(j==n)
		return;
	int i;
	for(i=0;i<n-j;i++)
	{
		if(min==-1)
		{
			min=q.front();
			q.dequeue();
		}
		else if(min>q.front())
		{
			q.enqueue(min);
			min=q.front();
			q.dequeue();
		}
		else
		{
			q.enqueue(q.front());
			q.dequeue();
		}
	}
	for(i;i<n;i++)
	{
		q.enqueue(q.front());
		q.dequeue();
	}
	q.enqueue(min);
	recursive(q,n,j+1,-1);
}
void iterative(queue &q,int n)
{
	int j,min=-1,i;
	for(j=0;j<n;j++)
	{
		min=-1;
		for(i=0;i<n-j;i++)
	{
		if(min==-1)
		{
			min=q.front();
			q.dequeue();
		}
		else if(min>q.front())
		{
			q.enqueue(min);
			min=q.front();
			q.dequeue();
		}
		else
		{
			q.enqueue(q.front());
			q.dequeue();
		}
	}
	for(i;i<n;i++)
	{
		q.enqueue(q.front());
		q.dequeue();
	}
	q.enqueue(min);
	}
}
void queue::enqueue(int x)
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
int queue::front()
{
	return a[f];
}
bool queue::empty()
{
    if(f==-1)
    return true;
    return false;
}
int queue::rear()
{
	return a[r];
}