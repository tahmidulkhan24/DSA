#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1, -2, 2, -2, 2};

map<pair<int, int>, vector<pair<int, int>>> adj;

void bfs(pair<int, int> src, map<pair<int, int>, bool> &vis, map<pair<int, int>, pair<int, int>> &parent, map<pair<int, int>, int> &dis)
{
    queue<pair<int, int>> q;
    q.push(src);

    vis[src] = true;
    parent[src] = {-1, -1};
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        for (pair<int, int> child : adj[par])
        {
            if (vis[child] == false)
            {
                q.push(child);

                vis[child] = true;
                parent[child] = par;
                dis[child] = dis[par] + 1;
            }
        }
    }
}

void print_path(pair<int, int> curr, pair<int, int> des, map<pair<int, int>, pair<int, int>> &parent)
{
    if (curr == make_pair(-1, -1)) return;

    print_path(parent[curr], des, parent);

    // converting (x, y) point to string
    string a = "";
    a.push_back(curr.first + 'A' - 1);
    a.push_back(curr.second + '0');

    if (curr != des) cout << a << "->";
    else cout << a;
}

int main()
{
    // creating the graph
    for (int x = 1; x <= 8; x++)
    {
        for (int y = 1; y <= 8; y++)
        {
            // find all possible cells and establish connection
            for (int i = 0; i < 8; i++)
            {
                int a = x + dx[i];
                int b = y + dy[i];

                if (a >= 1 and a <= 8 and b >= 1 and b <= 8) // check if the cell is within the chessboard or not
                {
                    adj[{x, y}].push_back({a, b});
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        string x, y;
        cin >> x >> y;

        // converting string to (x, y) point
        int x_a = x[0] - 'A' + 1;
        int x_b = x[1] - '0';

        int y_a = y[0] - 'A' + 1;
        int y_b = y[1] - '0';

        pair<int, int> src = {x_a, x_b};
        pair<int, int> des = {y_a, y_b};

        map<pair<int, int>, bool> vis;
        map<pair<int, int>, pair<int, int>> parent;
        map<pair<int, int>, int> dis;

        bfs(src, vis, parent, dis);

        // minimum moves needed
        cout << dis[{y_a, y_b}] << endl;

        // print path
        print_path(des, des, parent);
        cout << endl;
    }

    return 0;
}

/*
INPUT:
-----
2
A1 B2
E2 E4

OUTPUT:
------
4
A1->C2->A3->C4->B2
2
E2->C3->E4

[Note: The output path may vary depending on the initialization sequence of the dx and dy arrays. However, the shortest distance will remain the same for any correctly implemented program.]

*/