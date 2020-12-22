#include<bits/stdc++.h>
using namespace std;
void print(int **a,int y)
{
    if(!a[y][1])
    {
        cout<<y<<" ";
        return;
    }
    print(a,a[y][2]);
    cout<<y<<" ";
}
void minpath(int **G,int x,int y,int n)
{
    int **a=new int*[n+1],i;
    for(i=0;i<=n;i++)
    a[i]=new int[3];
    for(i=1;i<=n;i++)
    {
        a[i][0]=0;
        a[i][1]=1e9;
    }
    a[x][0]=1;
    a[x][1]=0;
    while(a[y][0]==0)
    {
        for(i=1;i<=n;i++)
        {
            if(G[x][i] && !a[i][0])
            {
                if(a[i][1]-G[x][i]-a[x][1]>0)
                {
                    a[i][2]=x;
                    a[i][1]=a[x][1]+G[x][i];
                }
            }
        }
        int min=1e9,ind;
        for(i=1;i<=n;i++)
        {
            if(a[i][1]<min && !a[i][0])
            {
                ind=i;
                min=a[i][1];
            }
        }
        x=ind;
        a[x][0]=1;
    }
    cout<<a[y][1]<<endl;
    print(a,y);cout<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,i;
    cin>>n;
    int **G=new int*[n+1];
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    while(1)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==-1)
        break;
        G[x][y]=z;
    }
    int x,y;
    cin>>x>>y;
    minpath(G,x,y,n);
}

//INPUT
/*
7
1 2 2 
1 4 1 
2 4 3 
2 5 10 
3 1 4
3 6 5
4 6 8
4 7 4
4 5 2 
5 7 6 
7 6 5
4 3 2
-1 -1 -1
1 6

OUTPUT
8
1 4 3 6
*/