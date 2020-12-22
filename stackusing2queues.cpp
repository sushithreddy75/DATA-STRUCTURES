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
struct stack
{
	int t;
	int a[100];
	int top();
	void push(int);
	void pop();
	bool empty();
	int size();
};
void pushcostly()
{
	stack s;
	s.t=-1;
	queue q1,q2;
	q1.f=-1;q2.f=-1;
	q1.r=-1;q2.r=-1;
	q1.size=100;q2.size=-1;
	int n;
	cout<<"enter no of operations\n";
	cin>>n;
	while(n--)
	{
		cout<<"1 to pop,2 to push,3 for top element: ";
		int x;cin>>x;
		if(x==1)
		{
			//cout<<q1.front()<<" popped\n";
			q1.dequeue();
		}
		else if(x==2)
		{
			cout<<"enter element: ";
			int y;cin>>y;
			while(!q1.empty())
			{
				q2.enqueue(q1.front());
				q1.dequeue();
			}
			q1.enqueue(y);
			while(!q2.empty())
			{
				q1.enqueue(q2.front());
				q2.dequeue();
			}
		}
		else
			cout<<"top element: "<<q1.front()<<endl;
	}
}
void popcostly()
{
	stack s;
	s.t=-1;
	queue q1,q2;
	q1.f=-1;q2.f=-1;
	q1.r=-1;q2.r=-1;
	q1.size=100;q2.size=-1;
	int n;
	cout<<"enter no of operations\n";
	cin>>n;
	while(n--){
	cout<<"1 to pop,2 to push,3 for top element: ";
		int x;cin>>x;
		if(x==2)
		{
			cout<<"enter element: ";
			int y;cin>>y;
			q1.enqueue(y);
		}
		else if(x==1)
		{
			while(q1.r>0)
			{
				q2.enqueue(q1.front());
				q1.dequeue();
			}
			q1.dequeue();
			while(!q2.empty())
			{
				q1.enqueue(q2.front());
				q2.dequeue();
			}
		}
		else
			cout<<"top element: "<<q1.rear()<<endl;}
}
int main()
{
	cout<<"enter-1 to make push costly,2 to pop costly: ";
	int x;
	cin>>x;
	if(x==1)
		pushcostly();
	else
		popcostly();
	return 0;
}
int stack::top()
{
	return a[t];
}
void stack::push(int x)
{
	t++;
	a[t]=x;
}
void stack::pop()
{
	t--;
}
bool stack::empty()
{
	if(t==-1)
		return true;
	return false;
}
int stack::size()
{
	return t+1;
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