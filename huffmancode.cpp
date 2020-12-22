#include<iostream>
using namespace std;
struct hfnode
{
	hfnode *lc;
	char data;
	int freq;
	hfnode *rc;
};
typedef hfnode* hfptr;
struct node
{
	hfptr data;
	node *next;
};
typedef node* lptr;
void push(lptr &t,hfptr x)
{
	if(t==NULL)
	{
		t=new(node);
		t->data=x;
		t->next=NULL;
		return;
	}
	lptr t1=new(node);
	t1->data=x;
	t1->next=t;
	t=t1;
}
void del(lptr t,lptr &h,hfptr x,hfptr y)
{
	if(!h || !t->next)
		return;
	if(h->data==x||h->data==y)
		h=h->next;
	else if(t->next->data==x||t->next->data==y)
		t->next=t->next->next;
	else
		t=t->next;
	del(t,h,x,y);
}
void findmin(lptr t,hfptr &x,hfptr &y)
{
	if(!t)
		return;
	if(t->data->freq<x->freq)
	{
		y=x;
		x=t->data;
	}
	else if(t->data->freq<y->freq)
		y=t->data;
	findmin(t->next,x,y);
}
void create(int a[],lptr &l,int i)
{
	if(i==52)
		return;
	if(a[i]>0){
	hfptr t=new(hfnode);
	t->freq=a[i];
	if(i>=26)
		t->data='A'+i-26;
	else
		t->data='a'+i;
	t->lc=t->rc=NULL;
	push(l,t);}
	create(a,l,i+1);
}
void create(lptr &l,hfptr &T)
{
    if(!l)
    return;
	if(l->next==NULL)
	{
		T=l->data;
		return;
	}
	hfptr x=new(hfnode),y=new(hfnode);
	x->freq=1000;y->freq=1000;
	findmin(l,x,y);
	hfptr t=new(hfnode);
	t->freq=x->freq+y->freq;
	t->data='#';
	t->rc=x;
	t->lc=y;
	push(l,t);
	del(l,l,x,y);
	create(l,T);
}
void codedata(hfptr t,string a[],string s)
{
	if(!t)
		return;
	if(t->data!='#')
	{
		if(t->data<'a')
			a[t->data-'A'+26]=s;
		else
			a[t->data-'a']=s;
	}
	string s1=s;
	s+='0';
	s1+='1';
	codedata(t->lc,a,s);
	codedata(t->rc,a,s1);
}
void encode(string s,string &s1,string code[],int i)
{
	if(s[i]=='\0')
		return;
	if(s[i]<'a')
		s1+=code[s[i]-'A'+26];
	else
		s1+=code[s[i]-'a'];
	encode(s,s1,code,i+1);
}
void decode(hfptr t,string s,int &i)
{
	if(s[i]=='0')
	{
		if(!t->lc)
		{
			cout<<t->data;
			return;
		}
		i++;
		return decode(t->lc,s,i);
	}
	if(!t->rc)
	{
		cout<<t->data;
		return;
	}
	i++;
	decode(t->rc,s,i);
}
void decode(hfptr t,string s)
{
	int i=0;
	while(s[i]!='\0')
		decode(t,s,i);
}
int main()
{
	string s;
	cin>>s;
	int freq[52]={0},i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]<'a')
			freq[s[i]-'A'+26]++;
		else
			freq[s[i]-'a']++;
	}
	lptr l=NULL;
	create(freq,l,0);
	hfptr T=NULL;
	create(l,T);
	string code[52],s1="";
	codedata(T,code,s1);
	encode(s,s1,code,0);
	cout<<s1<<endl;
	decode(T,s1);
	cout<<endl;
	return 0;
}