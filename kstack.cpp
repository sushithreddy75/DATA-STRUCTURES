#include<iostream>
using namespace std;
struct stack
{
	int t[10];
	int a[1000];
	int k;
	int top(int);
	void push(int,int);
	void pop(int);
	int size(int);
};
int main()
{
	cout<<"enter no of stacks: ";
	stack s;
	cin>>s.k;
	int k=s.k,i;
	for(i=0;i<k;i++)
	{
		s.t[i]=(i*100)/k-1;
	}
	int x=0;
	do
	{
		cout<<"enter stack to perform operation: ";
		cin>>x;
		cout<<"enter\n1.push,2.top,3.pop,4.size\n";
		int y;
		cin>>y;
		if(y==1)
		{
			cout<<"enter element: ";
			int z;cin>>z;
			s.push(x-1,z);
		}
		if(y==2)
			cout<<"top element "<<s.top(x-1)<<endl;
		if(y==3)
			s.pop(x-1);
		if(y==4)
			cout<<"size: "<<s.size(x-1);
	}while(x!=0);
	return 0;
}
int stack::top(int x)
{
	return a[t[x-1]];
}
void stack::push(int x,int y)
{
	t[x-1]++;
	a[t[x-1]]=y;
}
void stack::pop(int x)
{
	t[x-1]--;
}
int stack::size(int x)
{
	return ((100*x/k)+t[x]);
}