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

vector<pair<double, pair<int,int>>> edges;
vector<double> mstEdges;

void kruskal(int n) {
    sort(edges.begin(), edges.end());
    dsu ds(n);
    mstEdges.clear(); 
    int token=0;
   
    for(auto &ed : edges) {
        
        double w = ed.first;
        int u = ed.second.first;
        int v = ed.second.second;
        if(ds.dsu_find(u) != ds.dsu_find(v)) {
            ds.unionset(u, v);
           mstEdges.push_back(w);
           token++;
           if(token==n-1) break;
        }
    }
   
}

int main() {
   int t;
   cin>>t;
   while(t--)
   {
    int s,p;
    cin>>s>>p;

    vector<pair<int,int>> points(p);
    for(int i=0;i<p;i++)
    {
        cin>>points[i].first>>points[i].second;
    }
    
     if (s>= p) {
            cout << fixed << setprecision(2) << 0.00 << "\n";
            continue;
        }
     
    for(int i=0;i<p;i++)
    {
        for(int j=i+1;j<p;j++)
        {
            double dx=points[j].first-points[i].first;
            double dy=points[j].second-points[i].second;
            double dis=sqrt((dx*dx)+(dy*dy));
            edges.push_back({dis,{i,j}});

        }
    }
    kruskal(p);
    sort(mstEdges.begin(),mstEdges.end(),greater<double>());
    double D=mstEdges[s-1];
    cout << fixed << setprecision(2) << D << "\n";

   }

    return 0;
}
