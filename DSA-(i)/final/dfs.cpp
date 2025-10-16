#include <bits/stdc++.h>
using namespace std;

map<string, int> mp1;
map<int, string> mp2;
int n, e, id = 1;

vector<int> adj[100];
int vis[100], start[100], finish[100], timer;

void init()
{
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        start[i] = 0;
        finish[i] = 0;
    }
    timer = 1;
}

int converter(string s)
{
    if(mp1[s] == 0)
    {
        mp1[s] = id;
        mp2[id] = s;
        id++;
    }

    return mp1[s];
}

void dfs(int u)
{
    vis[u] = 1;
    start[u] = timer++;

    for(int v : adj[u])
    {
        if(vis[v] == 0) dfs(v);
    }

    finish[u] = timer++;
}

int main()
{
    cin >> n >> e;

    while(e--)
    {
        string us, vs;
        cin >> us >> vs;

        int u = converter(us);
        int v = converter(vs);

        adj[u].push_back(v); // for directed graph
    }

    string src;
    cin >> src;

    int s = converter(src);

    init();
    dfs(s);

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0) dfs(i);
    }

    // output
    for(int i = 1; i <= n; i++)
    {
        cout << "Start of " << mp2[i] << " = " << start[i] << endl;
        cout << "Finish of " << mp2[i] << " = " << finish[i] << endl << endl;
    }

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
Start of A = 2
Finish of A = 7

Start of C = 3
Finish of C = 4

Start of E = 1
Finish of E = 12

Start of D = 5
Finish of D = 6

Start of B = 8
Finish of B = 11

Start of F = 9
Finish of F = 10

Start of G = 13
Finish of G = 16

Start of H = 14
Finish of H = 15
*/