#include<iostream>
using namespace std;
struct ternode
{
    ternode *lc;
    int flow;
    char data;
    ternode *eq,*rc;
};
typedef ternode* terptr;
terptr create(char c)
{
    terptr t=new(ternode);
    t->data=c;
    t->eq=t->lc=t->rc=NULL;
    t->flow=0;
    return t;
}
void insert(terptr &t,string s,int i)
{
    if(!t)
    t=create(s[i]);
    if(t->data==s[i])
    {
        if(s[i+1]=='\0')
        {
            t->flow=1;
            return;
        }
        insert(t->eq,s,i+1);
        return;
    }
    if(s[i]<t->data)
    insert(t->lc,s,i);
    else
    insert(t->rc,s,i);
}
bool search(terptr t,string s,int i)
{
    if(!t)
    return false;
    if(t->data==s[i])
    {
        if(s[i+1]=='\0')
        {
            if(t->flow)
            return true;
            return false;
        }
        return search(t->eq,s,i+1);
    }
    if(t->data>s[i])
    return search(t->lc,s,i);
    return search(t->rc,s,i);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n=4;
    terptr T=NULL;
    while(n--)
    {
        string s;
        cin>>s;
        insert(T,s,0);
    }
    n=2;
    while(n--)
    {
        string s;
        cin>>s;
        cout<<search(T,s,0)<<" ";
    }
    cout<<endl;
    return 0;
}