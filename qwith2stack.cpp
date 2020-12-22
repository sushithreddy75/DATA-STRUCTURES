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
void enqueuecostly()
{
	stack s1,s2;
	s1.t=-1;s2.t=-1;
	queue q;
	q.f=-1;
	q.r=-1;
	q.size=100;
	int n;
	cout<<"enter no of operations\n";
	cin>>n;
	while(n--)
	{
		cout<<"1 to dequeue,2 to enqueue,3 for front element: ";
		int x;cin>>x;
		if(x==2)
		{
			cout<<"enter element ";
			int y;cin>>y;
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(y);
			while(!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		else if(x==1)
		{
			s1.pop();
		}
		else
			cout<<"front element: "<<s1.top()<<endl;
	}
}
void dequeuecostly()
{
	stack s1,s2;
	s1.t=-1;s2.t=-1;
	queue q;
	q.f=-1;
	q.r=-1;
	q.size=100;
	int n;
	cout<<"enter no of operations\n";
	cin>>n;
	while(n--)
	{
		cout<<"1 to dequeue,2 to enqueue,3 for front element: ";
		int x;cin>>x;
		if(x==1)
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
			while(!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		else if(x==2)
		{
			cout<<"enter element ";
			int y;cin>>y;
			s1.push(y);
		}
		else
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			cout<<"front element: "<<s2.top()<<endl;
			while(!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
	}
}
int main()
{
	cout<<"enter-1 to make enqueue costly,2 to dequeue costly: ";
	int x;
	cin>>x;
	if(x==1)
		enqueuecostly();
	else
		dequeuecostly();
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
	if(t!=-1)
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