#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> adj;
map<string, bool> vis;
map<string, string> color;
vector<string> busA, busB;
bool isBipartite(string src)
{
    queue<string> q;
    q.push(src);
    vis[src] = true;
    color[src] = "red";
    busA.push_back(src);
    while (!q.empty())
    {
        string par = q.front();
        q.pop();
        for (string child : adj[par])
        {
            if (vis[child])
            {
                if (color[child] == color[par])
                    return false;
            }
            else
            {
                q.push(child);
                vis[child] = true;
                if (color[par] == "red")
                {
                    color[child] = "blue";
                    busB.push_back(child);
                }

                else
                {
                    color[child] = "red";
                    busA.push_back(child);
                }
                    
            }
        }
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    set<string> stu;
    while (e--)
    {
        string a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        stu.insert(a);
        stu.insert(b);
    }
    for (auto student : stu)
    {
        if (!vis[student])
        {
            if (!isBipartite(student))
            {
                cout << "Bus Arrangement Not Possible\n";
                return 0;
            }
        }
    }
    cout<<"Bus-A:";
    for(string s:busA)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<"Bus-B:";
    for(string x:busB)
    {
        cout<<x<<" ";
    }
    return 0;
}