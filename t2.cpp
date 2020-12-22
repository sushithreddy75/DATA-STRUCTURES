#include<iostream>
using namespace std;
struct node
{
    int data;
    char data1;
    node *next;
};
typedef node* lptr;
struct mnode
{
    int data;
    char data1;
    mnode *next;
    int count;
};
typedef mnode* mptr;
void insert(lptr &h,int n,char c)
{
    if(h==NULL)
    {
        h=new(node);
        h->data=n;h->data1=c;
        h->next=NULL;
        return;
    }
    lptr t=h;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=new(node);t=t->next;
    t->data=n;t->data1=c;
        t->next=NULL;
}
void print(lptr t)
{
    while(t!=NULL)
    {
        cout<<t->data1<<t->data<<" ";
        t=t->next;
    }
}
void mapit(mptr map[],int n,char c)
{
    mptr t=map[(n+int(c))%10];
    if(t==NULL)
    {
        t=new(mnode);
        t->data=n;t->data1=c;
        t->count=1;t->next=NULL;
        map[(n+int(c))%10]=t;
        return;
    }
    while(t->next!=NULL)
    {
        if(t->data==n && t->data1==c)
        {
            t->count++;
            return;
        }
        t=t->next;
    }
    if(t->data==n && t->data1==c)
    {
        t->count++;
        return;
    }
    t->next=new(mnode);
    t->data=n;t->data1=c;
    t->count=1;t->next=NULL;
}
void mapprint(mptr map[])
{
    for(int i=0;i<10;i++)
    {
        mptr t=map[i];
        while(t!=NULL)
        {
            if(t->count==3)
                cout<<t->data1<<t->data<<" ";
            t=t->next;
        }
    }
}
int main()
{
    lptr l1=NULL,l2=NULL,l3=NULL,l=NULL,l4=NULL,t;
    int n;char c;
    mptr map[10]={NULL};
    while(1)
    {
        cin>>c>>n;
        if(n==-1)
        break;
        insert(l1,n,c);
        mapit(map,n,c);
    }
    while(1)
    {
        cin>>c>>n;
        if(n==-1)
        break;
        insert(l2,n,c);
        mapit(map,n,c);
    }
    while(1)
    {
        cin>>c>>n;
        if(n==-1)
        break;
        insert(l3,n,c);
        mapit(map,n,c);
    }
    print(l1);print(l2);print(l3);cout<<endl;
    mapprint(map);
}
