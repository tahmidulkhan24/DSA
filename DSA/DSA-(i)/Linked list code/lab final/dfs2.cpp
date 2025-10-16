#include <bits/stdc++.h>
using namespace std;
map<string,int> m1;
map<int,string> m2;
vector<int> adj[100];
bool vis[100];
int start[100];
int finish[100];
int timer,cnt=1,n,e;
void init()
{
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        start[i] = 0;
        finish[i] = 0;
    }
    timer = 1;
}
int converter(string s)
{
    if(m1[s]==0)
    {
        m1[s]=cnt;
        m2[cnt]=s;
        cnt++;
    }
    return m1[s];
}
void dfs(int src)
{
    vis[src]=true;
    start[src]=timer++;
    for(int child:adj[src])
    {
        if(!vis[child]) dfs(child);
    }
    finish[src]=timer++;
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        string a,b;
        cin>>a>>b;
        int u=converter(a);
        int v=converter(b);
        adj[u].push_back(v);
    }
    string sc;
    cin>>sc;
    int src=converter(sc);
    init();
    dfs(src);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << "Start of " << m2[i] << " = " << start[i] << endl;
        cout << "Finish of " << m2[i] << " = " << finish[i] << endl << endl;
    }
    return 0;
}