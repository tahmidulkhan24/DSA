#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool vis[100];
int lvl[100];
int parent[100];
int n,e;
void init()
{
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
        parent[i]=-1;
        lvl[i]=-1;
    }
}
void bfs(int src)
{
    stack<int> q;
    q.push(src);
    vis[src]=true;
    lvl[src]=0;
    parent[src]=-1;
    while(!q.empty())
    {
        int par=q.top();
        q.pop();
        cout<<par<<" ";
        for(auto child:adj[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=true;
                parent[child]=par;
                lvl[child]=lvl[par]+1;
            }
        }
    }
}
int main()
{
    init();
    cin>>n>>e;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
   
    bfs(src);
    return 0;
}