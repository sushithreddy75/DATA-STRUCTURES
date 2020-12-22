#include<iostream>
using namespace std;
struct queue
{
	int f,r,size;
	string a[100];
	void enqueue(string);
	void dequeue();
	string front();
	bool empty();
};
int main()
{
	queue q;
	q.f=q.r=-1;
	q.size=100;
	while(1)
	{
		cout<<"enter -1 to stop enqueue,1 to enqueue ";
		int x;
		cin>>x;
		if(x==-1)
			break;
		string s="";
		while(1)
		{
			cout<<"enter value or # to break ";
			string s1;
			cin>>s1;
			if(s1=="#")
				break;
			s+=s1+" ";
		}
		q.enqueue(s);
	}
	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.dequeue();
	}
	return 0;
}
bool queue::empty()
{
    if(f==-1)
    return true;
    return false;
}
string queue::front()
{
    return a[f];
}
void queue::enqueue(string s)
{
    if(f==-1)
    {
        f=r=0;
    }
    else
    {r++;
    r%=size;}
    a[r]=s;
}
void queue::dequeue()
{
    if(f==r)
    {
        f=-1;
        r=-1;
        return;
    }
    f++;
    f%=size;
}