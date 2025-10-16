#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
map<int, bool> vis;
map<int, string> color;

bool isBipartite(int src)
{
    queue<int> q;
    q.push(src);

    vis[src] = true;
    color[src] = "red";

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj[par])
        {
            if (vis[child]) // if visited, check child and parent color
            {
                if (color[par] == color[child]) return false;
            }
            else
            {
                q.push(child);

                // mark as visited
                vis[child] = true;

                // set color
                if (color[par] == "red") color[child] = "blue";
                else color[child] = "red";
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
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool check = true;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false) check = check && isBipartite(i);
    }

    if (check == true) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

/*
INPUT-1:
-------
9 8
0 1
2 0
6 2
3 7
8 3
4 6
4 0
0 5

OUTPUT-1:
--------
YES

INPUT-2:
-------
6 7
1 2
5 4
5 1
2 5
5 3
1 0
0 3

OUTPUT-2:
--------
NO

*/