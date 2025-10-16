#include <bits/stdc++.h>
using namespace std;

int n, e;

vector<int> adj[100];
int vis[100], par[100], start[100], finish[100], timer;

vector<pair<int, int>> tree_edges, forward_edges, backward_edges, cross_edges;

void init()
{
    for(int i = 0; i < n; i++)
    {
        vis[i] = 0;
        start[i] = 0;
        finish[i] = 0;
        par[i] = -1;
    }
    timer = 1;
}

void dfs(int u)
{
    vis[u] = 1;
    start[u] = timer++;

    for(int v : adj[u])
    {
        if(vis[v] == 0)
        {
            par[v] = u;

            // collect tree edges
            tree_edges.push_back({u, v});

            dfs(v);
        }
    }

    finish[u] = timer++;
}

int main()
{
    cin >> n >> e;

    while(e--)
    {
        char uc, vc;
        cin >> uc >> vc;

        int u = (int) uc - 65;
        int v = (int) vc - 65;

        // for directed graph
        adj[u].push_back(v);
    }

    char src;
    cin >> src;

    int s = (int) src - 65;

    init();
    dfs(s);

    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
        }
    }

    // collect forward, backward and cross edges
    for(int i = 0; i < n; i++)
    {
        int u = i;
        for(int v : adj[u])
        {
            if(par[v] == u) continue;

            if(start[u] < start[v] and finish[v] < finish[u])
                forward_edges.push_back({u, v});
            else if(start[v] < start[u] and finish[u] < finish[v])
                backward_edges.push_back({u, v});
            else
                cross_edges.push_back({u, v});
        }
    }

    //tree edges
    cout << "Tree edges :" << endl;
    for(pair<int, int> p : tree_edges)
    {
        cout << (char)(p.first + 65) << " -> " << (char)(p.second + 65) << endl;
    }
    cout << endl;

    //forward edges
    cout << "Forward edges :" << endl;
    for(pair<int, int> p : forward_edges)
    {
        cout << (char)(p.first + 65) << " -> " << (char)(p.second + 65) << endl;
    }
    cout << endl;

    //backward edges
    cout << "Backward edges :" << endl;
    for(pair<int, int> p : backward_edges)
    {
        cout << (char)(p.first + 65) << " -> " << (char)(p.second + 65) << endl;
    }
    cout << endl;

    //cross edges
    cout << "Cross edges :" << endl;
    for(pair<int, int> p : cross_edges)
    {
        cout << (char)(p.first + 65) << " -> " << (char)(p.second + 65) << endl;
    }
    cout << endl;

    return 0;
}

/*
INPUT:
-----
8 14
A C
E A
A D
E B
B F
G H
E D
C E
D C
B D
F D
H D
G F
G B
E

OUTPUT:
------
Tree edges :
E -> A
A -> C
A -> D
E -> B
B -> F
G -> H

Forward edges :
E -> D

Backward edges :
C -> E

Cross edges :
B -> D
D -> C
F -> D
G -> F
G -> B
H -> D
*/