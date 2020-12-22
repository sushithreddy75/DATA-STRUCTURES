#include<iostream>
using namespace std;
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
void swap(int*,int*);
int main()
{
	stack s1,s2;
	s1.t=-1;s2.t=-1;
	int n;
	cout<<"enter size: ";
	cin>>n;
	cout<<"enter elements\n";
	int a[n],i;
	for(i=0;i<n;i++)
		cin>>a[i];
	s1.push(0);
	s2.push(n-1);
	while(!s1.empty())
	{
		int x=s1.top(),y=s2.top();
		s1.pop();s2.pop();
		if(x<y && x>=0 && y<n)
		{
			int p=a[x],l=x+1,h=y;
			int l1=l;
			while(l<=y && l1<=y)
			{
				if(a[l]<p)
				{
					swap(a+l1,a+l);
					l1++;
					cout<<l1<<endl;
				}
				l++;
			}
			l1--;
			swap(a+x,a+l1);
			s1.push(x);s2.push(l1-1);
			s1.push(l1+1);s2.push(y);
		}
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
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
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}