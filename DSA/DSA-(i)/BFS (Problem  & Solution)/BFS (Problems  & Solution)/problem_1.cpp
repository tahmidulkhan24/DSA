#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> adj;
map<string, bool> vis;
map<string, string> parent;
map<string, int> dis;

void bfs(string src)
{
    queue<string> q;
    q.push(src);

    vis[src] = true;
    parent[src] = "-1";
    dis[src] = 0;

    while (!q.empty())
    {
        string par = q.front();
        q.pop();

        for (string child : adj[par])
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

void print_path(string current, string destination)
{
    if (current == "-1")
        return;

    print_path(parent[current], destination);

    if (current != destination)
        cout << current << "\\\\";
    else
        cout << current;
}

int main()
{
    int e;
    cin >> e;

    while (e--)
    {
        string u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    bfs("C:");

    int q;
    cin >> q;

    while (q--)
    {
        string destination;
        cin >> destination;

        if (vis[destination] == false)
        {
            cout << "File not found" << endl
                 << "-1" << endl;
        }
        else
        {
            print_path(destination, destination);

            cout << endl
                 << dis[destination] * 2 << endl;
        }
    }

    return 0;
}

/*
INPUT:
-----
9
Photos Maldives
C: Photos
Videos Memories
C: Videos
Memories sunset.mp4
Maldives Sea.jpg
Videos tour.mp4
C: Result.pdf
Photos Download
5
Sea.jpg
Memories
tour.mp4
Photos
Codes

OUTPUT:
------
C:\\Photos\\Maldives\\Sea.jpg
6
C:\\Videos\\Memories
4
C:\\Videos\\tour.mp4
4
C:\\Photos
2
File not found
-1

*/