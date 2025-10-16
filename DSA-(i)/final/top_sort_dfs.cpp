#include <bits/stdc++.h>
using namespace std;

map<string, int> mp1;
map<int, string> mp2;
int n, e, id = 1;

vector<int> adj[100];
int vis[100];
stack<int> st;

void init()
{
    for(int i = 1; i <= n; i++) vis[i] = 0;
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

    for(int v : adj[u])
    {
        if(vis[v] == 0) dfs(v);
    }

    st.push(u);
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

    init();

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0) dfs(i);
    }

    // sorted sequence
    while(!st.empty())
    {
        cout << mp2[st.top()] << " ";
        st.pop();
    }

    return 0;
}

/*
INPUT:
-----
7 6
105 205
203 215
169 279
205 220
203 220
105 203

OUTPUT:
------
169 279 105 203 215 205 220
*/