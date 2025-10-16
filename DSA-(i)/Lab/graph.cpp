#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int i;
    cin >> i;
    int in = adj[i].size();
    int out = 0;

    for (int j = 1; j <= n; j++)
    {
        for (int it : adj[j])
        {
            if (it == i)
                out++;
        }
    }

    cout << in << " " << out;
    return 0;
}