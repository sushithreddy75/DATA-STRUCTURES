#include<iostream>
#include<string>
using namespace std;
struct stack
{
int top,size;
char c[50];
void push(char x)
{
if(top>size-1)
cout<<"STACK IS FULL\n";
else
c[++top]=x;
}
void pop()
{
if(top==-1)
cout<<"STACK IS EMPTY\n";
else
top--;
}
};
int main()
{
stack a;
a.top=-1;a.size=50;
string s;
cin>>s;
int flag=1;
for(int i=0;s[i]!='\0';i++)
{
if(s[i]=='{'||s[i]=='['||s[i]=='(')
a.push(s[i]);
else if(a.top!=-1){
if((a.c[a.top]=='{' && s[i]=='}')||(a.c[a.top]=='[' && s[i]==']')||(a.c[a.top]=='(' && s[i]==')'))
a.pop();
else if((s[i]=='}'&&a.c[a.top]!='{')||(s[i]==']'&&a.c[a.top]!='[')||(s[i]==')'&&a.c[a.top]!='('))
{flag=0;break;}}
}
if(flag==1)
{
if(a.top!=-1)
flag=0;
}
if(flag==0)
cout<<"!!!ERROR\n";
else 
cout<<"NO ERROR\n";
return 0;
}

