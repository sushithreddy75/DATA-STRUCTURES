#include<iostream>
using namespace std;
struct tnode
{
    bool wrd;
    tnode *ptr[36];
};
typedef tnode* tptr;
void insert(tptr t,string s,int i)
{
    if(s[i]=='\0')
    return;
    int j=s[i]-'a';
    if(s[i]>='0' && s[i]<='9')
    j=26+s[i]-'0';
    if(s[i+1]=='\0')
    {
        t->wrd=1;
       // return;
    }
    if(!t->ptr[j])
    t->ptr[j]=new(tnode);
    insert(t->ptr[j],s,i+1);
}
void search(tptr t,int i,string s)
{
    if(!t)
    return;
    for(int j=0;j<36;j++)
    {
        if(t->ptr[j])
        {
            char c='a'+j;
            if(j>25)
            c='0'+j-26;
            string s1=s+c;
            if(t->wrd)
            cout<<s1<<endl;
            search(t->ptr[j],j,s1);
        }
    }
}
int main()
{
    tptr T=new(tnode);
    while(1)
    {
        string s;
        cin>>s;
        if(s=="#")
        break;
        insert(T,s,0);
    }
    search(T,0,"");
}
