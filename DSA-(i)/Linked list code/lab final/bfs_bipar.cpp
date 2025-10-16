#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> adj;
map<int, bool> vis;
map<int, string> color;
bool bipartile(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    color[src] = "red";
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto child : adj[par])
        {
            if (vis[child])
            {
                if (color[child] == color[par])
                    return false;
            }
            else
            {
                q.push(child);
                vis[child]=true;
                if (color[par] == "red")
                    color[child] = "blue";
                else
                    color[child] = "red";
            }
        }
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool flg = true;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            flg = flg && bipartile(i);
        }
    }
    if (flg)
    {
        cout << "yes" << endl;
    }
    else
        cout << "no" << endl;
    return 0;
}