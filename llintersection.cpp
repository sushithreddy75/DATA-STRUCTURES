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
void intersection(lptr &head,lptr head1,lptr head2,lptr p)
{
    if(head1==NULL)
    return;
    lptr h=head1,t=head2;
    int x=h->data;
    while(t!=NULL)
    {
        if(t->data==x)
        {
            //cout<<t->data<<endl;
            intersection(head,head1->next,head2,head1);
            return;
        }
        t=t->next;
    }
    if(p==NULL)
    {
        head=head->next;
        delete(head1);
        intersection(head,head,head2,NULL);
        return;
    }
    p->next=head1->next;
    delete(head1);
    head1=p->next;
    intersection(head,head1,head2,p);
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
    intersection(head,head,head1,NULL);
    print(head);
    cout<<endl;
    return 0;
}