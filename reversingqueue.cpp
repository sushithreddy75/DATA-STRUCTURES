#include<iostream>
using namespace std;
struct queue
{
	int f,r,size;
	int a[100];
	void enqueue(int x);
	void dequeue();
	int front();
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
int main()
{
    stack s;
    s.t=-1;
    queue q;
    q.f=q.r=-1;
    int n,i;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        q.enqueue(x);
    }
    while(!q.empty())
    {
        s.push(q.front());
        q.dequeue();
    }
    while(!s.empty())
    {
        q.enqueue(s.top());
        s.pop();
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.dequeue();
    }
    cout<<endl;
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