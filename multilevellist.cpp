#include<iostream>
using namespace std;
struct mlnode
{
	int tag;
	union
	{
		mlnode *down;
		char c;
	}data;
	mlnode *next;
};
typedef mlnode* mlptr;
void insert(mlptr &h,mlptr t)
{
    char c;
    cin>>c;
    if(c=='#' || c=='}')
    return;
    mlptr t1=new(mlnode);
    if(h==NULL)
    h=t1;
    else
    t->next=t1;
    t=t1;
    t->next=NULL;
    if(c=='{')
    {
       t->tag=1;
       mlptr h1=NULL;
       insert(h1,h1);
       t->data.down=h1;
       return insert(h,t);
    }
    t->tag=0;
    t->data.c=c;
    insert(h,t);
}
void print(mlptr h)
{
	if(h==NULL)
	{
		cout<<"} ";
		return;
	}
	if(h->tag==0)
	{
		cout<<h->data.c<<" ";
		return print(h->next);
	}
	if(h->tag==1)
	{
		cout<<"{ ";
		print(h->data.down);
		print(h->next);
	}
}
int main()
{
	string s;
	int i=0;
	//cin>>s;
	mlptr h,head=NULL;
	insert(head,head);
	cout<<"{ ";
	print(head->data.down);
	cout<<endl;
}