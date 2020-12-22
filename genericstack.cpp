#include<iostream>
using namespace std;
union u
{
    int i;
    char c;
    float f;
};
struct stack
{
    int tag[100];
    u a[100];
    int t;
};
void pushint(stack &s,int x)
{
    s.t++;
    s.a[s.t].i=x;
    s.tag[s.t]=1;
}
void pushchar(stack &s,char x)
{
    s.t++;
    s.a[s.t].c=x;
    s.tag[s.t]=2;
}
void pushfloat(stack &s,float f)
{
    s.t++;
    s.a[s.t].f=f;
    s.tag[s.t]=3;
}
void pop(stack &s)
{
    s.t--;
}
int top(stack &s)
{
    return s.t;
}
bool empty(stack &s)
{
    if(s.t==-1)
        return true;
    return false;
}
int main()
{
    stack s;
    s.t=-1;
    int x;
    do
    {
        //int x;
        cout<<"enter\n1.push,2.top,3.pop\n";
        cin>>x;
        if(x==1)
        {
            cout<<"1 for int,2 for char,3 for float\n";
            int y;
            cin>>y;
            if(y==1)
            {
                int in;cin>>in;
                pushint(s,in);
                //cout<<s.t;
            }
            if(y==2)
            {
                char ch;cin>>ch;
                pushchar(s,ch);
            }
            if(y==3)
            {
                float fl;cin>>fl;
                pushfloat(s,fl);
            }
        }
        if(x==2)
        {
            //cout<<"4";
            int t=top(s);
            int tag=s.tag[t];
            cout<<tag;
            if(tag==1)
                cout<<s.a[t].i<<endl;
            if(tag==2)
                cout<<s.a[t].c<<endl;
            if(tag==3)
                cout<<s.a[t].f<<endl;
        }
        if(x==3)
            pop(s);
    }while(x!=0 && !empty(s));
    return 0;
}