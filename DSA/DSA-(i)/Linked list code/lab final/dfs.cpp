#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> adj;
map<string, bool> vis;
map<string, int> start;
map<string, int> finish;
int timer = 1;
void dfs(string src)
{
    vis[src] = true;
    start[src] = timer++;
    for (auto child : adj[src])
    {
        if (!vis[child]) dfs(child);
    }
    finish[src]=timer++;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        string a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    string src;
    cin >> src;
    dfs(src);
    for(auto v:adj)
    {
        string node=v.first;
        if(!vis[node]) dfs(node);
    }
    for(auto v:adj)
    {
        string node=v.first;
        cout << "Start of " << node << " = " << start[node] << endl;
        cout << "Finish of " << node << " = " << finish[node] << endl << endl;
    }
    return 0;
}