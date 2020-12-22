#include<iostream>
#include<queue>
using namespace std;
struct bstnode
{
    bstnode *lc;
    int data;
    bstnode *rc;
};
typedef bstnode* bstptr;
void lr(bstptr &t)
{
    bstptr t1=t->rc;
    t->rc=t1->lc;
    t1->lc=t;
    t=t1;
}
void rr(bstptr &t)
{
    bstptr t1=t->lc;
    t->lc=t1->rc;
    t1->rc=t;
    t=t1;
}
int height(bstptr t)
{
    if(!t)
    return -1;
    return (max(height(t->lc),height(t->rc))+1);
}
void insert(bstptr &t,int x,bstptr &t1,bstptr &t2, bstptr &t3)
{
    if(!t)
    {
        t=new(bstnode);
        t->data=x;
        t->lc=t->rc=NULL;
        t1=t;
        return;
    }
    if(t->data>x)
    insert(t->lc,x,t1,t2,t3);
    else
    insert(t->rc,x,t1,t2,t3);
    int h=height(t->lc)-height(t->rc);
    t3=t2;t2=t1;t1=t;
    if(h>1)
    {
        if(t3 && t1->lc==t2&&t2->lc==t3)
        rr(t);
        else 
        {
            lr(t->lc);
            rr(t);
        }
        t1=t;
    }
    else if(h<-1)
    {
        if(t3 && t1->rc==t2&&t2->rc==t3)
        lr(t);
        else 
        {
            rr(t->rc);
            lr(t);
        }
        t1=t;
    }
}
void levelorder(bstptr t)
{
    queue<bstptr>q;
    q.push(t);
    while(!q.empty())
    {
        q.push(NULL);
        while(q.front())
        {
            cout<<q.front()->data<<" ";
            if(q.front()->lc)
            q.push(q.front()->lc);
            if(q.front()->rc)
            q.push(q.front()->rc);
            q.pop();
        }
        cout<<endl;
        q.pop();
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    bstptr T=NULL;
    while(1)
    {
        int x;
        cin>>x;
        if(x==-1)
        break;
        bstptr t1=NULL,t2=NULL,t3=NULL;
        insert(T,x,t1,t2,t3);
    }
    levelorder(T);
}

//INPUT
//6 4 2 1 3 5 8 7 9 -1
//OUTPUT
//4 
//2 6 
//1 3 5 8 
//7 9 