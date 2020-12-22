#include<bits/stdc++.h>
using namespace std;
void sort(int **G,int a[],int n)
{
    vector<int>v;
    int i,ind;
    for(i=1;i<=n;i++)
    if(a[i]==0)
    v.push_back(i);
    ind=0;
    while(v.size())
    {
        int x=v[ind];
        cout<<x<<" ";
        for(i=1;i<=n;i++)
        {
            if(G[x][i])
            {a[i]--;
            if(!a[i])
            v.push_back(i);}
        }
        v.erase(v.begin()+ind);
        ind=0;
        for(i=0;i<v.size();i++)
        cout<<char(v[i]-1+'A');
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n=7,i;
    //cin>>n;
    int **G=new int*[n+1];
    for(i=0;i<=n;i++)
    G[i]=new int[n+1];
    int ind[n+1]={0};
    G[1][2]=G[2][3]=G[3][4]=G[5][6]=G[6][7]=G[7][3]=1;
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(G[i][j])
            ind[j]++;
        }
    }
    sort(G,ind,n);
}

//INPUT
/*
7
1 2 
1 3 
1 5 
2 4
3 5
3 6 
4 6 
5 7
6 7
-1 -1

OUTPUT
1 2 3 4 5 6 7
*/