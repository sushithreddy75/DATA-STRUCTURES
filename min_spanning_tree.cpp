#include<bits/stdc++.h>
using namespace std;
void spanning(int **G,int n)
{
    int a[n+1][3],sum=0,i;
    for(i=0;i<=n;i++)
    {
        a[i][0]=0;a[i][1]=1e9;
    }
    int ind=1;
    while(ind)
    {
        a[ind][0]=1;
        int x1=ind;
        for(i=1;i<=n;i++)
        {
            if(a[i][0])
            {
                int j,min=1e9;
                for(j=1;j<=n;j++)
                {
                    if(!a[j][0]&&G[i][j]&&G[i][j]<min)
                    {
                        min=G[i][j];
                        a[i][1]=min;a[i][2]=j;
                    }
                }
            }
        }
        ind=0;int min=1e9;
        for(i=1;i<=n;i++)
        {
            if(a[i][0]&&!a[a[i][2]][0]&&a[i][1]<min)
            {
                min=a[i][1];
                ind=a[i][2];
                x1=i;
            }
        }
        if(ind)
        sum+=min;
        if(ind)
        cout<<x1<<" "<<ind<<endl;
    }
    cout<<sum<<endl;
}
int main()
{
    int n=7,i;
    int **G=new int*[n+1];
    int i1[]={1,1,1,2,2,3,3,4,4,4,5,6};
    int i2[]={2,3,4,4,5,4,6,5,6,7,7,7};
    int i3[]={2,4,1,3,10,2,5,7,8,4,6,1};
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    int hc=0;
    for(i=0;i<12;i++)
    G[i1[i]][i2[i]]=G[i2[i]][i1[i]]=i3[i];
    spanning(G,n);
}