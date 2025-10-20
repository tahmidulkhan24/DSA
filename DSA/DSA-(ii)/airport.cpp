#include <bits/stdc++.h>
using namespace std;

class dsu {
public:
    vector<int> par, sz;
    dsu(int n) {
        par.resize(n + 1); // Fix: 1-based indexing
        sz.resize(n + 1);
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int dsu_find(int x) {
        if(par[x] == x) return x;
        return par[x] = dsu_find(par[x]); // Path compression
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
    int t;
    cin >> t;
    int caseNo = 1;
    while(t--) {
        int n, e, cost;
        cin >> n >> e >> cost;

        edges.clear();
        Tedges.clear();

        for(int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if(w < cost) { // cheaper than airport
                edges.push_back({w, {u, v}});
            }
        }

        int minCost = kruskal(n);
        int edgesInMST = Tedges.size();
        int airports = n - edgesInMST; // number of connected components
        int airportCost = airports * cost;
        int totalCost = airportCost + minCost;

        cout << "Case #" << caseNo++ << ": " << totalCost << " " << airports << "\n";
    }
    return 0;
}
