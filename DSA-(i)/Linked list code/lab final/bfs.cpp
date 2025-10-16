#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int lvl[N];
int parent[N];
int n, e;
void init()
{
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
        lvl[i] = -1;
        parent[i] = -1;
    }
}
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    lvl[src] = 0;
    while (!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int child:adj[par])
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
    cin >> n >> e;
    while (e--)
    {
        char a, b;
        cin >> a >> b;
        int u = (int)a - 65;
        int v = (int)b - 65;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init();
    char src;
    cin >> src;
    int sc = (int)src - 65;
    bfs(sc);
    return 0;
}