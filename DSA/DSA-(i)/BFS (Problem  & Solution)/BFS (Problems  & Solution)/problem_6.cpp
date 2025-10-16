#include <bits/stdc++.h>
using namespace std;

map<int, bool> vis;
map<int, int> level;
map<int, int> parent;

void path_print(int curr, int des)
{
    if (curr == -1) return;

    path_print(parent[curr], des);

    if (curr != des)  cout << curr << " -> ";
    else cout << curr;
}

void bfs(int x, int y)
{
    queue<int> q;
    q.push(x);

    vis[x] = true;
    level[x] = 0;
    parent[x] = -1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        if (par == y)
        {
            cout << level[par] << endl;
            path_print(y, y);
            return;
        }

        int child1 = par * 2;
        int child2 = par - 1;

        if (child1 <= 2 * y and vis[child1] == false)
        {
            q.push(child1);
            vis[child1] = true;
            level[child1] = level[par] + 1;
            parent[child1] = par;
        }

        if (child2 >= 1 and vis[child2] == false)
        {
            q.push(child2);
            vis[child2] = true;
            level[child2] = level[par] + 1;
            parent[child2] = par;
        }
    }
}

int main()
{
    int x, y;
    cin >> x >> y;

    bfs(x, y);

    return 0;
}

/*
INPUT-1:
-------
2  14

OUTPUT-1:
--------
4
2 -> 4 -> 8 -> 7 -> 14

INPUT-2:
-------
4  14

OUTPUT-2:
--------
3
4 -> 8 -> 7 -> 14

*/