#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> city;
vector<int> adj[100];
int vis[100], start[100], finish[100], timer;

void init()
{
    for(int i = 0; i < n; i++)
    {
        vis[i] = 0;
        start[i] = 0;
        finish[i] = 0;
    }
    timer = 1;
}

void dfs(int u)
{
    vis[u] = 1;
    start[u] = timer++;

    for(int v : adj[u])
    {
        if(!vis[v]) dfs(v);
    }

    finish[u] = timer++;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        city.push_back(s);
    }

    sort(city.begin(), city.end());

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(abs(city[i][0] - city[j][0]) == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
            return city[a] < city[b];
        });
    }

    init();
    dfs(0);

    for(int i = 0; i < n; i++)
    {
        cout << city[i] << " -> Finish : " << finish[i] << endl;
    }

    return 0;
}
