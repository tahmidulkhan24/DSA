#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
int vis[N];
int dis[N];
int parent[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int i=0;i<adj[par].size();i++)
        {
             int child=adj[par][i];
             if(vis[child]==0)
             {
                q.push(child);
                vis[child]=1;
             }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}