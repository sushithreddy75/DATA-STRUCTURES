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
lptr insert(int x,lptr t)
{
	if(t==NULL)
		return create(x);
	lptr t1=create(x);
	t->next=t1;
	return t1;
}
void print(lptr t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		print(t->next);
	}
}
lptr uni(lptr l1,lptr l2)
{
	lptr l=NULL,l3=l;
	while(l1!=NULL && l2!=NULL)
	{
		if(l1->data==l2->data)
		{
			if(l==NULL)
			{
				l3=create(l1->data);
				l=l3;
			}
			else
			{
				l3->next=create(l1->data);
				l3=l3->next;
			}
			int x=l1->data;
			while(l1!=NULL && l1->data==x)
				l1=l1->next;
			while(l2!=NULL && l2->data==x)
				l2=l2->next;
			continue;
		}
		if(l1->data>l2->data)
		{
			if(l==NULL)
			{
				l3=create(l2->data);
				l=l3;
			}
			else
			{
				l3->next=create(l2->data);
				l3=l3->next;
			}
			int x=l2->data;
			while(l2!=NULL && l2->data==x)
				l2=l2->next;
			continue;
		}
		if(l==NULL)
		{
			l3=create(l1->data);
			l=l3;
		}
		else
		{
			l3->next=create(l1->data);
			l3=l3->next;
		}
		int x=l1->data;
		while(l1!=NULL && l1->data==x)
		l1=l1->next;
	}
	while(l1!=NULL)
	{
		l3->next=create(l1->data);
		int x=l1->data;
		l3=l3->next;
		while(l1!=NULL && l1->data==x )
			l1=l1->next;
	}
	while(l2!=NULL)
	{
		l3->next=create(l2->data);
		int x=l2->data;
		l3=l3->next;
		while(l2!=NULL && l2->data==x)
			l2=l2->next;
	}
	return l;
}
lptr intersection(lptr h1,lptr h2)
{
	lptr h3=NULL,h=NULL;
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->data==h2->data)
		{
			int x=h1->data;
			if(h==NULL)
			{
				h=create(x);
				h3=h;
			}
			else
			{
				h3->next=create(x);
				h3=h3->next;
			}
			while(h1!=NULL && h1->data==x)
				h1=h1->next;
			while(h2!=NULL && h2->data==x)
				h2=h2->next;
			continue;
		}
		if(h1->data>h2->data)
			h2=h2->next;
		else
			h1=h1->next;
	}
	return h;
}
lptr difference(lptr h1,lptr h2)
{
	lptr h=NULL,h3=NULL;
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->data<h2->data)
		{
			int x=h1->data;
			while(h1!=NULL && h1->data==x)
				h1=h1->next;
			if(h==NULL)
			{
				h=create(x);
				h3=h;
			}
			else
			{
				h3->next=create(x);
				h3=h3->next;
			}
			continue;
		}
		if(h1->data==h2->data)
		{
			int x=h1->data;
			while(h1!=NULL && h1->data==x)
				h1=h1->next;
			while(h2!=NULL && h2->data==x)
				h2=h2->next;
			continue;
		}
		while(h2!=NULL && h2->data<h1->data)
			h2=h2->next;
	}
	while(h1!=NULL)
	{
		int x=h1->data;
		while(h1!=NULL && h1->data==x)
			h1=h1->next;
		h3->next=create(x);
		h3=h3->next;
	}
	return h;
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
lptr uunion(lptr h1,lptr h2)
{
	lptr h=create(h1->data),h3=h;
	h1=h1->next;
	//h1=h3;
	while(h1!=NULL)
	{
		h3->next=create(h1->data);
		h3=h3->next;
		h1=h1->next;
	}
	while(h2!=NULL)
	{
		h3->next=create(h2->data);
		h3=h3->next;
		h2=h2->next;
	}
	deletedup(h);
	return h;
}
lptr uintersection(lptr h1,lptr h2)
{
	lptr h=NULL,h3=NULL;
	while(h1!=NULL)
	{
		lptr t=h2;
		while(t!=NULL && t->data!=h1->data)
			t=t->next;
		if(t!=NULL && t->data==h1->data)
		{
			if(h==NULL)
			{
				h=create(h1->data);
				h3=h;
			}
			else
			{
				h3->next=create(h1->data);
				h3=h3->next;
			}
		}
		h1=h1->next;
	}
	return h;
}
lptr udifference(lptr h1,lptr h2)
{
	lptr h=NULL,h3=NULL;
	while(h1!=NULL)
	{
		lptr t=h2;
		while(t!=NULL && t->data!=h1->data)
			t=t->next;
		if(t==NULL)
		{
			if(h==NULL)
			{
				h=create(h1->data);
				h3=h;
			}
			else
			{
				h3->next=create(h1->data);
				h3=h3->next;
			}
		}
		h1=h1->next;
	}
	return h;
}
int main()
{
	lptr L1=NULL,L2=NULL,t=NULL;
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
			break;
		t=insert(n,t);
		if(L1==NULL)
			L1=t;
	}
	t=NULL;
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
			break;
		t=insert(n,t);
		if(L2==NULL)
			L2=t;
	}
	lptr L3;
	L3=uni(L1,L2);
	print(L3);cout<<endl;
	L3=intersection(L1,L2);
	print(L3);cout<<endl;
	L3=difference(L1,L2);
	print(L3);cout<<endl;
	//
	//unsorted
	L1=NULL,L2=NULL,t=NULL;
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
			break;
		t=insert(n,t);
		if(L1==NULL)
			L1=t;
	}
	t=NULL;
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
			break;
		t=insert(n,t);
		if(L2==NULL)
			L2=t;
	}
	deletedup(L1);
	deletedup(L2);
	//cout<<"uni\n";
	L3=uunion(L1,L2);
	print(L3);cout<<endl;
	L3=uintersection(L1,L2);
	print(L3);cout<<endl;
	L3=udifference(L1,L2);
	print(L3);cout<<endl;
	return 0;
}