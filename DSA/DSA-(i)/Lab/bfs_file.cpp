#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];  
map<string, int> m1;
map<int, string> m2; 
int ver_cnt = 1;
bool vis[N]; 
int dis[N];
int parent[N]; 


void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    parent[src] = -1;
    dis[src] = 0;

    while (!q.empty()) {
        int par = q.front();
        q.pop();

        for (int i = 0; i < adj[par].size(); i++) {
            int child = adj[par][i];
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
                dis[child] = dis[par] + 1;
            }
        }
    }
}


void findPath(int id) {
    if (!vis[id]) {
        cout << "File not found\n-1\n";
        return;
    }

    vector<string> path;
    int tmp = id;
    while (tmp != -1) {
        path.push_back(m2[tmp]);
        tmp = parent[tmp];
    }

    reverse(path.begin(), path.end()); 
    cout << path[0]; 
    for (int i = 1; i < path.size(); i++) {
        cout << "\\\\" << path[i]; 
    }
    cout << endl;

   
    cout << dis[id] * 2 << endl; 
}

int main() {
    int e;
    cin >> e;

   
    m1["C:"] = ver_cnt;
    m2[ver_cnt] = "C:";
    ver_cnt++;
    while (e--) {
        string u, v;
        cin >> u >> v;

        if (m1.find(u) == m1.end()) {
            m1[u] = ver_cnt;
            m2[ver_cnt] = u;
            ver_cnt++;
        }

        if (m1.find(v) == m1.end()) {
            m1[v] = ver_cnt;
            m2[ver_cnt] = v;
            ver_cnt++;
        }

        adj[m1[u]].push_back(m1[v]);
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    bfs(m1["C:"]);

    int q;
    cin >> q;

   
    while (q--) {
        string x;
        cin >> x;

  
        if (m1.find(x) == m1.end()) {
            cout << "File not found\n-1\n"; 
        } else {
            findPath(m1[x]);
        }
    }

    return 0;
}
