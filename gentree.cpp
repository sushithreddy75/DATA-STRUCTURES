#include<iostream>
#include<queue>
using namespace std;
struct gtnode
{
	char data;
	gtnode *fc,*ns;
};
typedef gtnode* gtptr;
gtptr create1(char c)
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
	t=create1(c[i]);
i++;
	create(t->fc,c,i);
	create(t->ns,c,i);
}
void print(gtptr t)
{
	queue<gtptr>q;
	q.push(t);
	while(!q.empty())
	{
		q.push(NULL);
		while(q.front())
		{
			gtptr t=q.front()->fc;
			cout<<q.front()->data<<" ";
			if(t)
			{//q.push(t->fc);
//t=t->fc;
			while(t)
			{
				q.push(t);
				t=t->ns;
			}
		}
			q.pop();
		}
		q.pop();
		cout<<endl;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	gtptr GT=NULL;
	string c;
	cin>>c;
	int i=0;
	create(GT,c,i);
	print(GT);
}