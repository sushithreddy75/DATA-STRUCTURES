#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef node* lptr;
lptr create(int x)
{
	lptr t=new (node);
	t->data=x;
	t->next=NULL;
	return t;
}
lptr insert(lptr t,int x)
{
	if(t==NULL)
		return create(x);
	lptr t1=create(x);
	t->next=t1;
	return t1;
}
bool palindromecheck(lptr &h,lptr t)
{
	if(t==NULL)
		return true;
	if(palindromecheck(h,t->next))
	{
		if(t->data==h->data)
		{
			h=h->next;
			return true;
		}
	}
	return false;
}
void sorteddupdel(lptr h)
{
	if(h==NULL)
		return;
	if(h->next!=NULL && h->data==h->next->data)
		h->next=h->next->next;
	else
		h=h->next;
	sorteddupdel(h);
}
void deletedup(lptr head)
{
    if(head==NULL)
    return;
    lptr t=head->next,p=head;
    int x=head->data;
    while(t!=NULL)
    {
        if(t->data==x)
        {
            p->next=t->next;
            delete(t);
            t=p->next;
            continue;
        }
        p=t;
        t=t->next;
    }
    deletedup(head->next);
}
void reverse(lptr &h,lptr t,lptr p)
{
	if(t->next==NULL)
	{
		t->next=p;
		h=t;
		return;
	}
	reverse(h,t->next,t);
	t->next=p;
}
void dellastocc(lptr h)
{
	if(h==NULL)
		return;
	lptr t=h,p=NULL;
	int c=0;
	while(t->next!=NULL)
	{
		if(t->next->data==h->data)
		{
			p=t;
			c++;
		}
		t=t->next;
		if(c>1)
			break;
	}
	if(c==1)
		p->next=p->next->next;
	dellastocc(h->next);
}
void segevodd(lptr &h,lptr t,lptr p)
{
	if(t==NULL)
		return;
	if(p==NULL)
	{
		if(h->data%2==0)
			p=h;
		else
		{
			lptr t1=h;
			p=h;
			while(p->data%2!=0)
			{
				t1=p;
				p=p->next;
			}
			t1->next=p->next;
			p->next=h;
			h=p;
		}
		segevodd(h,h,h);
		return;
	}
	if(t->next!=NULL && t->next->data%2==0)
	{
		lptr t1=t->next;
		t->next=t1->next;
		t1->next=p->next;
		p->next=t1;
		p=t1;
		segevodd(h,t,p);
		return;
	}
	segevodd(h,t->next,p);
}
void swapktnnode(lptr &h,lptr t,lptr &k1,int &c1,int &c2,int k)
{
	if(t==NULL)
		return;
	if(k==1)
	{
		while(t->next->next!=NULL)
			t=t->next;
		lptr t1=t->next;
		t1->next=h->next;
		t->next=h;
		h->next=NULL;
		h=t1;
		return;
	}
	c1++;
	if(c1==k-1)
		k1=t;
	swapktnnode(h,t->next,k1,c1,c2,k);
	c2++;
	if(c2==k+1 || (t==h && c2==k))
	{
		if(k1->next->next==NULL)
		{
			lptr t1=k1->next;
			t1->next=h->next;
			k1->next=h;
			h->next=NULL;
			h=t1;
			return;
		}
		lptr k2=t;
		lptr t1=k1->next,t2=k2->next;
		lptr t3=t2->next;
		t2->next=t1->next;
		t1->next=t3;
		k1->next=t2;
		k2->next=t1;
	}
}
bool checkl2inl1(lptr t1,lptr t2)
{
	if(t1==NULL)
		return false;
	if(t1->data==t2->data)
	{
		lptr t3=t2,t4=t1;
		while(t4!=NULL && t3!=NULL && t4->data==t3->data)
		{
			t3=t3->next;
			t4=t4->next;
		}
		if(t3==NULL)
			return true;
		if(t4==NULL)
			return false;
	}
	checkl2inl1(t1->next,t2);
}
void merge(lptr h1,lptr h2)
{
	lptr h=h1;h1=h1->next;
	while(h1!=NULL && h2!=NULL)
	{
		h->next=h2;
		h2=h2->next;
		h=h->next;
		h->next=NULL;
		h->next=h1;
		h1=h1->next;
		h=h->next;
		h->next=NULL;
	}
	if(h1!=NULL)
		h->next=h1;
	if(h2!=NULL)
		h->next=h2;
}
void insertionsort(lptr &h)
{
	lptr p=h,t=h;
	while(t->next!=NULL)
	{
		if(t->next->data>p->data)
		{
			p=p->next;
			t=t->next;
			continue;
		}
		lptr t1=h;
		if(t1->data>t->next->data)
		{
			t1=t->next;
			t->next=t->next->next;
			t1->next=h;
			h=t1;
			continue;
		}
		while(t1->next->data<t->next->data)
			t1=t1->next;
		lptr t3=t->next;
		t->next=t->next->next;
		t3->next=t1->next;
		t1->next=t3;
	}
}
void print(lptr t)
{
	if(t==NULL)
		return;
	cout<<t->data<<" ";
	print(t->next);
}
int main()
{
	lptr L1=NULL,t=NULL,L2;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	cout<<palindromecheck(L1,L1)<<endl;
	//p-2
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	sorteddupdel(L1);
	print(L1);cout<<endl;
	//p-3
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	deletedup(L1);
	print(L1);cout<<endl;
	//p-4
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	dellastocc(L1);
	print(L1);cout<<endl;
	//p-5
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	segevodd(L1,L1,NULL);
	print(L1);cout<<endl;
	//p-6
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	insertionsort(L1);
	print(L1);cout<<endl;
	//p-7
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	reverse(L1,L1,NULL);
	print(L1);cout<<endl;
	//p-8
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	//reverse(L1,L1,NULL);
	//print(L1);cout<<endl;
	int k;cin>>k;
	lptr k1=NULL;int c1=0,c2=0;
	swapktnnode(L1,L1,k1,c1,c2,k);
	print(L1);cout<<endl;
	//p-9
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	L2=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L2==NULL)
	    L2=t;
	}
	cout<<checkl2inl1(L1,L2)<<endl;
	//p-10
	L1=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L1==NULL)
	    L1=t;
	}
	L2=NULL;t=NULL;
	while(1)
	{
	    int n;
	    cin>>n;
	    if(n==-1)
	    break;
	    t=insert(t,n);
	    if(L2==NULL)
	    L2=t;
	}
	merge(L1,L2);
	print(L1);cout<<endl;
}
