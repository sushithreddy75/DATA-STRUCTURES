#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*next;
};
typedef node* lptr;
void insert(lptr &h,int x)
{
    lptr t1=new(node);
    t1->data=x;
    t1->next=NULL;
    if(!h)
    {h=t1;return;}
    lptr t=h;
    while(t->next)
    t=t->next;
    t->next=t1;
}
void splice(lptr &h,lptr t)
{
    if(h->data==t->data)
    {
        lptr t1=t;
        while(t1->next)
        t1=t1->next;
        t1->next=h->next;
        h=t;
        return;
    }
    splice(h->next,t);
}
int check(lptr t,int a[])
{
    while(t)
    {
        if(a[t->data]>0)
        return t->data;
        t=t->next;
    }
    return 0;
}
void dfs(int **G,int n,int a[],int x,lptr &t)
{
    stack<int>s,s1;
    s.push(x);
    while(!s.empty())
    {
        if(!s1.empty())
        {
            int i=s.top(),j=s1.top();
            a[s.top()]--;
            a[s1.top()]--;
            G[i][j]=G[j][i]=0;
            if(i==x){
                insert(t,x);
            
        break;}
        }
        int i=s.top();
        insert(t,i);
        s.pop();
        if(!s1.empty())
        s1.pop();
        int flag=0;
        for(int j=1;j<=n;j++)
        {
            if(G[i][j]&&a[j]>0&&a[i]>0)
            {
                s.push(j);
                s1.push(i);
                break;
                flag=1;
            }
        }
        
    }
}
void print(lptr t)
{
    while(t)
    {cout<<t->data<<" ";t=t->next;}
    cout<<endl;
}
void euler(int **G,int n,int a[])
{
    lptr t=NULL;
    dfs(G,n,a,1,t);
    while(1)
    {
        int x=check(t,a);
        if(x==0)
        break;
        lptr t1=NULL;
        dfs(G,n,a,x,t1);
        splice(t,t1);
    }
    print(t);
}
int main()
{
    int n=12;
    int **G=new int*[n+1],i;
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    G[1][3]=G[1][4]=G[2][3]=G[2][8]=1;
    G[3][1]=G[3][2]=G[3][4]=G[3][6]=G[3][7]=G[3][9]=1;
    G[4][1]=G[4][3]=G[4][5]=G[4][7]=G[4][10]=G[4][11]=1;
    G[5][4]=G[5][10]=1;
    G[6][3]=G[6][9]=1;
    G[7][3]=G[7][4]=G[7][9]=G[7][10]=1;
    G[8][2]=G[8][9]=1;
    G[9][3]=G[9][6]=G[9][7]=G[9][8]=G[9][10]=G[9][12]=1;
    G[10][4]=G[10][5]=G[10][7]=G[10][9]=G[10][11]=G[10][12]=1;
    G[11][4]=G[11][10]=1;
    G[12][9]=G[12][10]=1;
    int a[n+1]={0},j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(G[i][j])
            {a[i]++;}
        }
    }
    euler(G,n,a);
}