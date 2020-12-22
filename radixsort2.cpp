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
	int len();
	bool empty();
};
int main()
{
	int n,i;
	cout<<"enter size: ";
	cin>>n;
	queue q[10];
	for(i=0;i<10;i++)
	{
		q[i].f=q[i].r=-1;
		q[i].size=100;
	}
	int a[n];
	cout<<"enter elements\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		q[a[i]%10].enqueue(a[i]);
	}
	int y=1;
	while(q[0].len()!=n)
	{
		int j=0;y*=10;
		for(i=0;i<10;i++)
		{
			while(!q[i].empty())
			{
				a[j]=q[i].front();
				j++;
				q[i].dequeue();
			}
		}
		for(i=0;i<n;i++)
			q[(a[i]/y)%10].enqueue(a[i]);
	}
	cout<<"sorted array\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
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
int queue::len()
{
	if(f==-1)
		return 0;
	return (r-f)%size+1;
}