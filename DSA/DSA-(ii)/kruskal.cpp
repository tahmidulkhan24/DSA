#include <bits/stdc++.h>
using namespace std;

class dsu {
public:
    vector<int> par, sz;
    dsu(int n) {
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int dsu_find(int x) {
        if(par[x] == x) return x;
        return par[x] = dsu_find(par[x]);
    }
    void unionset(int a, int b) {
        int ra = dsu_find(a);
        int rb = dsu_find(b);
        if(ra == rb) return;
        if(sz[ra] >= sz[rb]) {
            par[rb] = ra;
            sz[ra] += sz[rb];
        } else {
            par[ra] = rb;
            sz[rb] += sz[ra];
        }
    }
};

vector<pair<int, pair<int,int>>> edges;
vector<pair<int, pair<int,int>>> Tedges;

int kruskal(int n) {
    sort(edges.begin(), edges.end());
    dsu ds(n);
    int cost = 0;
   
    for(auto &ed : edges) {
        
        int w = ed.first;
        int u = ed.second.first;
        int v = ed.second.second;
        if(ds.dsu_find(u) != ds.dsu_find(v)) {
            ds.unionset(u, v);
            cost += w;
           Tedges.push_back(ed);
        }
    }
    return cost;
}

int main() {
    int n, e;
    cin >> n >> e;
   edges.resize(e);

    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }

    int minCost = kruskal(n);
    cout << minCost << endl;

     cout << "Edges in MST:\n";
    for (auto &edge : Tedges) {
        cout << edge.second.first << " - " << edge.second.second << " : " << edge.first << endl;
    }

    return 0;
}
/*
7 11
0 6 8
4 5 13
4 3 1
2 4 5
1 5 25
2 5 17
2 3 9
0 5 14
1 2 19
0 1 2
6 5 21
*/