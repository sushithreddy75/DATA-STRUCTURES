#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;
};
typedef node* lptr;
lptr create(int x)
{
    lptr t=new(node);
    t->data=x;
    t->next=NULL;
    return t;
}
void insert(lptr &h,lptr t,int x)
{
    if(h==NULL)
    {
        h=create(x);
        return;
    }
    if(t->next==NULL)
    {
        t->next=create(x);
        return;
    }
    insert(h,t->next,x);
}
int main()
{
    lptr r[10]={NULL};
    int n,i;cin>>n;
    lptr h=NULL;
    for(i=0;i<n;i++)
    {
        int x;cin>>x;
        insert(r[x%10],r[x%10],x);
    }
    int y=1;
    while(1)
    {
        y*=10;
        h=NULL;
        int c=0;
        for(i=0;i<10;i++)
        {
            //c=0;
            while(r[i]!=NULL)
            {
                insert(h,h,r[i]->data);
                r[i]=r[i]->next;
                if(i==0)
                c++;
            }
            
        }
        if(c==n)
        break;
        while(h!=NULL)
        {
            insert(r[(h->data/y)%10],r[(h->data/y)%10],h->data);
            h=h->next;
        }
    }
    while(h!=NULL)
    {
        cout<<h->data<<" ";
        h=h->next;
    }
}
