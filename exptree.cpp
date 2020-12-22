#include<iostream>
using namespace std;
struct etnode
{
	etnode *lc;
	int tag;
	union
	{
		int x;
		char c;
	}data;
	etnode *rc;
};
typedef etnode * etptr;
struct stack
{
	etptr data;
	stack *next;
};
struct snode
{
	char data;
	snode* next;
};
typedef snode* stk;
void push(stk &s,char t)
{
	if(s==NULL)
	{
		s=new(snode);
		s->data=t;
		s->next=NULL;
		return;
	}
	stk t1=new(snode);
	t1->data=t;
	t1->next=s;
	s=t1;
}
typedef stack* sptr;
void push(sptr &s,etptr t)
{
	if(s==NULL)
	{
		s=new(stack);
		s->data=t;
		s->next=NULL;
		return;
	}
	sptr t1=new(stack);
	t1->data=t;
	t1->next=s;
	s=t1;
}
void construct(sptr &st,string s,int &i)
{
	if(s[i]=='\0')
		return;
	while(s[i]==' ')
		i++;
	if(s[i]>='0' && s[i]<='9')
	{
		int x=0;
		while(s[i]!='\0' && s[i]>='0' && s[i]<='9')
		{
			x*=10;
			x+=s[i]-'0';
			i++;
		}
		i++;
		etptr t=new(etnode);
		t->tag=1;
		t->lc=t->rc=NULL;
		t->data.x=x;
		push(st,t);
		return construct(st,s,i);
	}
	etptr t=new(etnode);
	t->data.c=s[i];
	t->tag=0;
	if(st)
	{
		t->rc=st->data;
		st=st->next;
	}
    else
    	t->rc=NULL;
    if(st)
	{
		t->lc=st->data;
		st=st->next;
	}
    else
    	t->lc=NULL;
	push(st,t);
	i++;
	while(s[i]==' ')
		i++;
	construct(st,s,i);
}
void print(etptr t)
{
	if(t==NULL)
		return;
	print(t->lc);
	print(t->rc);
	if(t->tag==1)
		cout<<t->data.x<<" ";
	else
		cout<<t->data.c<<" ";
}
int eval(etptr t)
{
	if(t==NULL)
		return 0;
	if(t->tag==1)
		return t->data.x;
	int x=eval(t->lc);
	int y=eval(t->rc);
	//cout<<x<<" "<<y<<" "<<t->data.c<<endl;
	if(t->data.c=='*')
		return x*y;
	if(t->data.c=='/')
		return x/y;
	if(t->data.c=='-')
		return x-y;
	return x+y;
}
void infixtopostfix(string &s,string s1,int &i,stk &st)
{
	if(s1[i]=='(')
	{
		push(st,s1[i]);
		i++;
		return infixtopostfix(s,s1,i,st);
	}
	if(s1[i]=='\0')
	{
		while(st!=NULL)
		{
			s+=st->data;
			//s+=' ';
			st=st->next;
		}
		return;
	}
	if(s1[i]==')')
	{
		i++;
		while(st->data!='(')
		{
			s+=st->data;
			//s+=' ';
			st=st->next;
		}
		st=st->next;
		return infixtopostfix(s,s1,i,st);
	}
	if(s1[i]==' '||(s1[i]>='0' && s1[i]<='9'))
	{
		s+=' ';
		while((s1[i]>='0' && s1[i]<='9'))
		{
			s+=s1[i];
			i++;
		}
		s+=' ';
		return infixtopostfix(s,s1,i,st);
	}
	if(s1[i]=='+'||s1[i]=='-')
	{
		while(st!=NULL && st->data!='(')
		{
			s+=st->data;
			st=st->next;
		}
	}
	else
	{
		while(st!=NULL && (st->data=='*' || st->data=='/'))
		{
			s+=st->data;
			st=st->next;
		}
	}
	push(st,s1[i]);
	i++;
	infixtopostfix(s,s1,i,st);
}
int main()
{
	string s;
	getline(cin,s);
	int i=0;
	sptr st=NULL;
	string s1="";//int i=0;
	stk st1=NULL;
	infixtopostfix(s1,s,i,st1);
	i=0;
	construct(st,s1,i);
	etptr T=st->data;
	//print(T);cout<<endl;
	cout<<eval(T)<<endl;
	//cout<<s1<<endl;
}