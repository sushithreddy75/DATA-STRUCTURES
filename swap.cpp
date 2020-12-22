#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void swap(int &x,int &y)
{
	int t=x;
	x=y;
	y=t;
}
void swap(int *x,int &y)
{
	int t=*x;
	*x=y;
	y=t;
}
void swap(int &x,int *y)
{
	int t=x;
	x=*y;
	*y=t;
}
int swap1(int *x,int y)
{
	int t=*x;
	*x=y;
	return t;
}
int swap1(int &x,int y)
{
	int t=x;
	x=y;
	return t;
}
int swap2(int x,int *y)
{
	int t=*y;
	*y=x;
	return t;
}
int swap2(int x,int &y)
{
	int t=y;
	y=x;
	return t;
}
int main()
{
	int a,b,x,y;
	cout<<"ENTER 2 NUMBERS\n";
	cin>>x>>y;
	cout<<"initial "<<x<<" "<<y<<endl;
	a=x,b=y;
	swap(&a,&b);
	cout<<a<<" "<<b<<endl;
	a=x,b=y;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
	a=x,b=y;
	swap(&a,b);
	cout<<a<<" "<<b<<endl;
	a=x,b=y;
	swap(a,&b);
	cout<<a<<" "<<b<<endl;
	a=x,b=y;
	b=swap1(&a,b);
	cout<<a<<" "<<b<<endl;
	a=x,b=y;
	b=swap1(a,b);
	cout<<a<<" "<<b<<endl;
	a=x,b=y;
	a=swap2(a,&b);
	cout<<a<<" "<<b<<endl;
	a=x,b=y;
	a=swap2(a,b);
	cout<<a<<" "<<b<<endl;
}