#include <bits/stdc++.h>
using namespace std;

map<string, int> mp1;
map<int, string> mp2;
int n, e, id = 1;

vector<int> adj[100], adjT[100];
int vis[100], visT[100];
stack<int> st;

void init()
{
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        visT[i] = 0;
    }
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

void dfs1(int u)
{
    vis[u] = 1;

    for(int v : adj[u])
    {
        if(vis[v] == 0) dfs1(v);
    }

    st.push(u);
}

void dfs2(int u)
{
    visT[u] = 1;
    cout << mp2[u] << " ";

    for(int v : adjT[u])
    {
        if(visT[v] == 0) dfs2(v);
    }
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

        // for directed graph
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }

    init();

    // independent dfs
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0) dfs1(i);
    }

    // output (dependent dfs)
    cout << "Strongly connected component sets are : " << endl;
    while(!st.empty())
    {
        if(visT[st.top()] == 0)
        {
            dfs2(st.top());
            cout << endl;
        }

        st.pop();
    }

    return 0;
}

/*
INPUT:
-----
8 14
h f
f a
a e
e a
g h
f c
a b
e d
g c
c b
b d
b c
d d
f g

OUTPUT:
------
Strongly connected component sets are : 
h g f 
a e 
b c 
d 
*/