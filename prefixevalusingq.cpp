#include<iostream>
using namespace std;
union uni 
{
    int x;
    char c;
};
struct queuestr
{
	int f,r,size;
	uni a[15];
	int tag[15];
	void enqueue(uni &x,int tag);
	int dequeue();
	uni front();
	bool empty();
};
int main()
{
	string s="-+*9+28*+4863";
	cout<<"enter string: ";
	//getline(cin,s);
	cin>>s;
	queuestr q;
	q.f=q.r=-1;
	q.size=15;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			if(i<s.size()-2)
			{
				if(s[i+1]>='0'&&s[i+1]<='9'&&s[i+2]>='0'&&s[i+2]<='9')
				{
					int x=s[i+1]-48;
					int y=s[i+2]-48;
					if(s[i]=='+')
						x+=y;
					if(s[i]=='-')
						x-=y;
					if(s[i]=='*')
						x*=y;
					if(s[i]=='/')
						x/=y;
					uni u;u.x=x;
					q.enqueue(u,1);
					i+=2;
				}
				else
				{
				    uni u;u.c=s[i];
				    q.enqueue(u,2);
				}
			}
		}
		else
		{
		    uni u;
		    if(s[i]>='0'&&s[i]<='9'){
		    u.x=s[i]-48;
			q.enqueue(u,1);}
			else
			{
			    u.c=s[i];
			    q.enqueue(u,2);
			}
		}
	}
	uni x,y,z;
	int xt,yt,zt;
	if(q.f!=q.r)
	{
	    x=q.front();xt=q.dequeue();
	//y=q.front();q.dequeue();
	    //z=q.front();q.dequeue();
	}
	
	while(q.f!=q.r)
	{
		//string x,y,z;
	//	x=q.front();q.dequeue();
	y=q.front();yt=q.dequeue();
	    z=q.front();zt=q.dequeue();
		if((xt==2)&&yt==1 && zt==1)
		{
			int x1=y.x,y1=z.x,i=0;
			if(x.c=='+')
						x1+=y1;
					if(x.c=='-')
						x1-=y1;
					if(x.c=='*')
						x1*=y1;
					if(x.c=='/')
						x1/=y1;
					uni u1;u1.x=x1;
					q.enqueue(u1,1);
			if(q.f!=q.r){
	x=q.front();xt=q.dequeue();
	//y=q.front();q.dequeue();}
		}}
		else
		{
			q.enqueue(x,xt);
			q.enqueue(y,yt);
			x=z;//y=z;
			xt=zt;
		}
	}
	cout<<q.front().x<<endl;
}
void queuestr::enqueue(uni &x,int t)
{
	if((r+1)%size==f)
	{
		cout<<"queue is full\n";
		return;
	}
	if(f==-1)
	{
		f=0;r=0;
	}
	else
		r=(r+1)%size;
	a[r]=x;
	tag[r]=t;
}
int queuestr::dequeue()
{
	if(f==-1)
	{
		cout<<"empty\n";
		return 0;
	}
	if(r==f)
	{
	    //a[r]="***";
	    int t=tag[r];
		r=-1;
		f=-1;
		return t;
	}
	//a[f]="***";
	int t=tag[f];
	f++;
	f%=size;
	return t;
}
uni queuestr::front()
{
	return a[f];
}
bool queuestr::empty()
{
	if(f==-1)
		return true;
	return false;
}

