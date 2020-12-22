#include<iostream>
using namespace std;
struct kqueue
{
	int a[1000];
	int f[100],r[100],pos[100],size[100];
	void enqueue(int,int);
	void dequeue(int);
	int front(int);
	bool empty(int);
	void partition(int);
};
int main()
{
	kqueue q;
	cout<<"enter no of queue\n";
	int k;
	cin>>k;
	q.partition(k);
	while(1	)
	{
		cout<<"enter queue no to perform operation 0 to stop: ";
		int n;
		cin>>n;
		if(n==0)
			break;
		cout<<"1 to dequeue,2 to enqueue,3 for front element: ";
		int op;
		cin>>op;
		if(op==1)
			q.dequeue(n);
		else if(op==2)
		{
			cout<<"enter element: ";
			int y;
			cin>>y;
			q.enqueue(n,y);
		}
		else
			cout<<"top element: "<<q.front(n)<<endl;
	}
}
void kqueue::enqueue(int n,int x)
{
	if((r[n]+1)%size[n]+pos[n]==f[n])
	{
		cout<<"queue is full\n";
		return;
	}
	if(f[n]-pos[n]==-1)
	{
		f[n]=pos[n];r[n]=pos[n];
	}
	else
		r[n]=(r[n]+1)%size[n]+pos[n];
	a[r[n]]=x;
}
void kqueue::dequeue(int n)
{
	if(f[n]-pos[n]==-1)
	{
		cout<<"empty\n";
		return;
	}
	if(r[n]==f[n])
	{
		r[n]=-1+pos[n];
		f[n]=-1+pos[n];
		return;
	}
	f[n]++;
	f[n]=f[n]%size[n]+pos[n];
}
int kqueue::front(int n)
{
	return a[f[n]];
}
bool kqueue::empty(int n)
{
    if(f[n]-pos[n]==-1)
    return true;
    return false;
}
void kqueue::partition(int k)
{
	for(int i=0;i<k;i++)
	{
		size[i]=1000/k;
		pos[i]=(1000/k)*i;
		f[i]=r[i]=pos[i]-1;
	}
}