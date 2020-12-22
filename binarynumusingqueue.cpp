#include<iostream>
using namespace std;
struct queuestr
{
	int f,r,size;
	string a[100];
	void enqueue(string x);
	void dequeue();
	string front();
};
int main()
{
	queuestr q;
	q.size=100;
	q.f=q.r=-1;
	q.enqueue("0");
	int n;
	cout<<"enter n: ";
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cout<<q.front()<<" = "<<i<<endl;
		string x=q.front();
		q.dequeue();
		if(x!="0")
		{
			q.enqueue(x+'0');
			q.enqueue(x+'1');
			continue;
		}
		q.enqueue("1");
	}
	return 0;
}
void queuestr::enqueue(string x)
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
void queuestr::dequeue()
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
string queuestr::front()
{
	return a[f];
}