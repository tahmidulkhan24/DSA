#include <bits/stdc++.h>
using namespace std;
int flag[1000];
//1=false
//0=true
void sieve(int n)
{
    flag[0]=flag[1]=1;
    for(int i=4;i<=n;i+=2)
    {
       flag[i]=1;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(flag[i]==1) continue;
        for(int j=i*i;j<=n;j=j+2*i)
        {
            flag[j]=1;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    sieve(n);
    for(int i=0;i<n;i++)
    {
       if(flag[i]==0)
       {
         cout<<i<<" ";
       }
    }
    return 0;
}