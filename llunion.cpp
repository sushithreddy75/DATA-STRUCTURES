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
void print(lptr t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		print(t->next);
	}
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
int main()
{
    lptr head=NULL,t=NULL,head1=NULL,t1=NULL;
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)
        break;
        t=insert(t,n);
        if(head==NULL)
        head=t;
    }
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)
        break;
        t1=insert(t1,n);
        if(head1==NULL)
        head1=t1;
    }
    t->next=head1;
    deletedup(head);
    print(head);
    cout<<endl;
    return 0;
}