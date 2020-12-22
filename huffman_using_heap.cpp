#include<iostream>
using namespace std;
struct hfnode
{
	hfnode* lc;
	int freq;
	char c;
	hfnode *rc;
};
typedef hfnode* hfptr;
void swap(hfptr *x,hfptr *y)
{
	hfptr t=*x;
	*x=*y;
	*y=t;
}
void insert(hfptr h[],int i)
{
	if(i<=0)
		return;
	if(h[(i-1)/2]->freq>h[i]->freq)
	{
		swap(h+i,h+(i-1)/2);
		insert(h,(i-1)/2);
	}
}
void del(hfptr a[],int i,int n)
{
	if(i>=n)
		return;
	if(2*i+1<n && a[i]->freq>a[2*i+1]->freq)
	{
		swap(a+i,a+2*i+1);
		if(2*i+1<n && a[i]->freq>a[2*i+2]->freq)
            del(a,i,n);
        del(a,2*i+1,n);
	}
	else if(2*i+2<n && a[i]->freq>a[2*i+2]->freq)
    {
        swap(a+i,a+2*i+2);
        del(a,2*i+2,n);
    }
}
void construct(hfptr &T,int &n,hfptr h[])
{
	if(n<=1	)
		return;
	hfptr t=h[0];
	h[0]=h[n-1];
	n--;
	del(h,0,n);
	hfptr t1=h[0];
	h[0]=h[n-1];
	n--;
	del(h,0,n);
	hfptr t2=new(hfnode);
	if(t1->freq==t->freq)
		swap(t,t1);
	t2->rc=t;
	t2->lc=t1;
	t2->c='#';
	t2->freq=t->freq+t1->freq;
	h[n]=t2;
	insert(h,n);
	n++;
	T=t2;
	construct(T,n,h);
}
void print(hfptr t,string s)
{
	if(!t)
		return;
	print(t->lc,s+"0");
	if(t->c!='#')
	cout<<t->c<<" "<<s<<endl;
	print(t->rc,s+"1");
}
int main()
{
	freopen("in.txt","r",stdin);
	hfptr h[100];
	int k=0,n;
	cin>>n;
	while(n--)
	{
		hfptr t=new(hfnode);
		t->lc=t->rc=NULL;
		cin>>t->c>>t->freq;
		h[k]=t;
		insert(h,k);
		k++;
	}
	hfptr T=NULL;
	construct(T,k,h);
	string s="";
	print(T,s);
}