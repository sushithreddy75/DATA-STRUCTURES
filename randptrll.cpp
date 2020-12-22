#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next,*rand;
};
typedef node* lptr;
struct queue
{
	int f,r,size;
	lptr a[1000];
	void enqueue(lptr x);
	void dequeue();
	lptr front();
	lptr rear();
	bool empty();
};
void construct(lptr &h,lptr t,queue &q)
{
    if(h!=NULL && t==NULL)
    return;
	int x,y,z;
	cin>>x>>y>>z;
	if(!q.empty())
	{
		lptr t1=q.front();
		int x2=t1->data;
		int flag=0;
		while(1)
		{
			t1=q.front();
			if(t1->data==x2 && flag==1)
				break;
			flag=1;
		q.dequeue();
		int x1=t1->data;
		if(x==x1)
		{
			t->next=t1;
			t=t1;
			if(z!=0)
			{
				t1->rand=new(node);
				t1=t1->rand;
				t1->data=z;
				q.enqueue(t1);
			}
			//q.enqueue(t1);
			if(y==0)
				return;
			return construct(h,t,q);
		}
		q.enqueue(t1);
		}
	}
	lptr t1=new(node);
	t1->data=x;
	t1->next=t1->rand=NULL;
	if(h==NULL)
		h=t1;
	else
	t->next=t1;
	if(y==0)
		return;
	if(z!=0)
	{
		t1->rand=new(node);
		t1->rand->data=z;
		t1->rand->next=t1->rand->rand=NULL;
		q.enqueue(t1->rand);
	}
	t=t1;
	construct(h,t,q);
}
void print(lptr h,int t,int &u,int ig)
{
    if(h==NULL)
    return;
    cout<<h->data<<" ";
    if(h->rand!=NULL && ig>0)
    ig--;
    else if(h->rand!=NULL && t==0 && ig==0)
    u++;
    else if(h->rand!=NULL && t>0)
    {
        t--;
        return print(h->rand,t,u,ig);
    }
    print(h->next,t,u,ig);
}
void callprint(lptr h)
{
    int t=0,u=0,ig=0,c=-1;
    print(h,t,u,ig);cout<<endl;
    c=u;
    ig=0;
    while(1)
    {
        t=1;
        while(1)
        {
            u=0;
            print(h,t,u,ig);
            cout<<endl;
            if(u==0)
            break;
            t++;
        }
        ig++;
        if(ig==c)
        break;
    }
}
int main()
{
	lptr h=NULL;
	queue q;
	q.f=q.r=-1;
	q.size=100;
	construct(h,h,q);
	callprint(h);
}
void queue::enqueue(lptr x)
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
lptr queue::front()
{
	return a[f];
}
bool queue::empty()
{
    if(f==-1)
    return true;
    return false;
}
lptr queue::rear()
{
	return a[r];
}
