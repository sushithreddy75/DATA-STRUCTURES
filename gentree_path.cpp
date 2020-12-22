#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct gtnode
{
	char data;
	gtnode *fc,*ns;
};
typedef gtnode* gtptr;
gtptr create(char c)
{
	gtptr t=new(gtnode);
	t->data=c;
	t->fc=t->ns=NULL;
	return t;
}
void create(gtptr &t,string c,int &i)
{
	if(c[i]=='\0')
	return;
if(c[i]=='.')
{
	i++;
	return;
}
if(c[i]!='.')
	t=create(c[i]);
i++;
	create(t->fc,c,i);
	create(t->ns,c,i);
}
void search(int &val,queue<gtptr>q,gtptr t,char c)
{
	if(!t||val)
		return;
	q.push(t);
	//cout<<t->data<<endl;
	if(t->data==c)
	{
		val=1;
		cout<<"1\n";	
		while(!q.empty())
		{
			cout<<q.front()->data<<" ";
			q.pop();
		}
		cout<<endl;
		return;
	}
	search(val,q,t->fc,c);
	t=t->fc;
	while(t)
	{
		search(val,q,t,c);
		t=t->ns;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	gtptr GT=NULL;
	string s;
	cin>>s;
	while(1){
	char c;
	cin>>c;
	if(c=='#')
		break;
	int i=0;
	create(GT,s,i);
	i=0;
	queue<gtptr>q;
	//q.push(GT);
	search(i,q,GT,c);
	if(!i)
		cout<<i<<endl;}
}