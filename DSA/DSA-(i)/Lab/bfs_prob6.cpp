#include <bits/stdc++.h>
using namespace std;
map<int, bool> vis;
map<int, int> lvl;
map<int, int> parent;
void path(int curr, int des)
{
    if (curr == -1)
    {
        return;
    }
    path(parent[curr], des);
    if (curr != des)
        cout << curr << " -> ";
    else
        cout << curr;
}
void bfs(int s, int d)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    lvl[s] = 0;
    parent[s] = -1;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        if (par == d)
        {
            cout << lvl[par] << endl;
            path(d, d);
            return;
        }
        int child1 = par * 2;
        int child2 = par - 1;
        if (child1 <= 2 * d && !vis[child1])
        {
            q.push(child1);
            vis[child1] = true;
            lvl[child1] = lvl[par] + 1;
            parent[child1] = par;
        }
        if (child2 >= 1 && !vis[child2])
        {
            q.push(child2);
            vis[child2] = true;
            lvl[child2] = lvl[par] + 1;
            parent[child2] = par;
        }
    }
}
int main()
{
    int s, d;
    cin >> s >> d;
    bfs(s, d);
    return 0;
}