#include <bits/stdc++.h>
using namespace std;
int par[1000];
int sz[1000];
int lvl[1000];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        sz[i]=1;
        lvl[i]=0;
    }
}
int dsu_find(int node)
{
    if(par[node]==node)
    {
        return node;
    }
    int lead=dsu_find(par[node]);
    par[node]=lead;
    return lead;
}
int dsu_union_sz(int a,int b)
{
    int lead1=dsu_find(a);
    int lead2=dsu_find(b);
    if(sz[lead1]>sz[lead2])
    {
        par[lead2]=lead1;
        sz[lead1]+=sz[lead2];
    }
    else
    {
        par[lead1]=lead2;
        sz[lead2]+=sz[lead1];
    }
}
int dsu_union_lvl(int a,int b)
{
    int lead1=dsu_find(a);
    int lead2=dsu_find(b);
    if (lvl[lead1] > lvl[lead2])
    {
        par[lead2] = lead1;
    }
    else if (lvl[lead2] > lvl[lead1])
    {
        par[lead1] = lead2;
    }
    else
    {
        par[lead2] = lead1;
        lvl[lead1]++;
    }
}
int main()
{
    int n;
    cin>>n;
     init(n);
    dsu_union_sz(1, 2);
    dsu_union_sz(2, 3);
    dsu_union_sz(5, 6);
    dsu_union_sz(6, 7);
    cout << dsu_find(1) << endl;
    cout << dsu_find(5) << endl;
    return 0;
    return 0;
}