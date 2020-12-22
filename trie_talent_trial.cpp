#include<iostream>
using namespace std;
struct str;
struct tnode;
union uni
    {
        tnode* t;
        str* s;
    };
struct tnode
{
    bool flag;
    uni ptr[4];
};
typedef tnode* tptr;
tptr create()
{
    tptr t=new(tnode);
    for(int i=0;i<4;i++)
    t->ptr[i].t=NULL;
    t->flag=1;
    return t;
}
struct str 
{
    string s;
};
void insert(tptr t,string s,int i)
{
    if(s[i]=='\0')
    {
        t->ptr[3].s=new(str);
        t->ptr[3].s->s=s;
        return;
    }
    int j=s[i]-'A';
    if(t->flag==0 && !t->ptr[j].t)
    {
        t->flag=0;
        t->ptr[j].s=new(str);
        t->ptr[j].s->s=s;
        return;
    }
    if(!t->flag)
    {
        t->flag=1;
        for(int i1=0;i1<3;i1++)
        {
            if(t->ptr[i1].t)
            {
                string s1=t->ptr[i1].s->s;
                insert(t,s1,i);
            }
        }
    }
    if(!t->ptr[j].t)
    t->ptr[j].t=create();
    insert(t->ptr[j].t,s,i+1);
}
void print(tptr t)
{
    if(!t)
    return;
    
    for(int i=0;i<3;i++)
    {
        if(t->flag)
        print(t->ptr[i].t);
        if(!t->flag && t->ptr[i].s)
        cout<<t->ptr[i].s->s<<" ";
    }
    if(t->ptr[3].s)
    cout<<t->ptr[3].s->s<<" ";
}
int main()
{
    freopen("in.txt","r",stdin);
    tptr T=create();
    while(1)
    {
        string s;
        cin>>s;
        if(s=="#")
        break;
        insert(T,s,0);
       // print(T);
    }
    print(T);cout<<endl;
    while(1)
    {
        string s;
        cin>>s;
        if(s=="#")
        break;
        insert(T,s,0);
    }
    print(T);cout<<endl;
    while(1)
    {
        string s;
        cin>>s;
        if(s=="#")
        break;
        insert(T,s,0);
    }
    print(T);cout<<endl;
}
