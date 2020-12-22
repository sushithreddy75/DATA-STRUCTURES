#include<iostream>
#include<queue>
using namespace std;
struct trpnode
{
    trpnode *lc;
    char key;
    int pri;
    trpnode *rc;
};
typedef trpnode* trptr;
void lr(trptr &t1)
{
    trptr t = t1->rc;
    t1->rc = t->lc;
    t->lc = t1;
    t1 = t;
}
void rr(trptr &t1)
{
    trptr t=t1->lc;
    t1->lc=t->rc;
    t->rc=t1;
    t1=t;
}
void insert(trptr &t,int x,char c)
{
    if(!t)
    {
        t=new(trpnode);
        t->lc=t->rc=NULL;
        t->pri=x;
        t->key=c;
        return;
    }
    if(c<t->key)
    insert(t->lc,x,c);
    else
    insert(t->rc,x,c);
    if(t->lc && t->lc->pri<t->pri)
    rr(t);
    if(t->rc && t->rc->pri<t->pri)
    lr(t);
}
void inorder(trptr t)
{
    if(!t)
    return;
    inorder(t->lc);
    cout<<t->key<<" "<<t->pri<<" ";
    inorder(t->rc);
}
void del(trptr &t,char c)
{
    if(t->key==c)
    {
        if(!t->lc && !t->rc)
        {
            t=NULL;
            return;
        }
        if(!t->lc)
        {
            t=t->rc;
            return;
        }
        if(!t->rc)
        {
            t=t->rc;
            return;
        }
        int x;
        if(t->lc->pri>t->rc->pri)
        {
            int x=t->pri;
            t->pri=t->rc->pri;
            t->rc->pri=x;
            t->key=t->rc->key;
            t->rc->key=c;
            return del(t->rc,c);
        }
         x=t->pri;
            t->pri=t->lc->pri;
            t->lc->pri=x;
            t->key=t->lc->key;
            t->lc->key=c;
            return del(t->lc,c);
    }
    if(c>t->key)
    del(t->rc,c);
    else
    del(t->lc,c);
}
void levelorder(trptr t)
{
    queue<trptr>q;
    q.push(t);
    while(!q.empty())
    {
        q.push(NULL);
        while(q.front())
        {
            cout<<q.front()->key<<" "<<q.front()->pri<<"   ";
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
    freopen("in.txt","r",stdin);
    trptr TR=NULL;
    while(1)
    {
        int x;char c;
        cin>>c;
        if(c=='#')
        break;
        cin>>x;
        insert(TR,x,c);
    }
    inorder(TR);cout<<endl;
    //levelorder(TR);
    string s;
    int i=2;
    //cin>>s;
    while(i--)
    {
        char c;
        cin>>c;
        del(TR,c);
        //levelorder(TR);
    }
    inorder(TR);cout<<endl;
}