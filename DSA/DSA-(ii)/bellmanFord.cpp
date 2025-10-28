#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
 class edge{
     public:
      int u,v,w;
      edge(int u,int v,int w)
      {
        this->u=u;
        this->v=v;
        this->w=w;
      }
 };
 vector<edge> ed;
 int dis[1005];
 int par[1005];

 void bellmanFord(int n,int src)
 {
      for(int i=0;i<n;i++)
      {
        dis[i]=INF;
        par[i]=-1;
      }
      dis[src]=0;
      for(int i=1;i<=n-1;i++)
      {
         for(auto e:ed)
         {
            if(dis[e.u]!=INF && dis[e.v]>dis[e.u]+e.w)
            {
                par[e.v]=e.u;
                dis[e.v]=dis[e.u]+e.w;
            }
         }
      }
        for(auto e:ed)
         {
            if(dis[e.u]!=INF && dis[e.v]>dis[e.u]+e.w)
            {
              cout<<"no sol"<<endl;
              return;
            }
         }

         cout << "Node\tDistance\tParent\n";
            for (int i = 0; i < n; i++) {
                cout << char('A' + i) << "\t";
                if (dis[i] == INF) cout << "INF\t\t";
                else cout << dis[i] << "\t\t";
                if (par[i] == -1) cout << "None\n";
                else cout << char('A' + par[i]) << "\n";
            }
 }
 
 int main(){
    int n, e;
    cin >> n >> e;


    for(int i=1; i<=e; i++){
        char cu, cv;
        int w;
        cin >> cu >> cv >> w;
        int u = cu - 'A';   // Convert char to int index
        int v = cv - 'A';
        ed.push_back(edge(u,v,w));
    }

    char source;
    cin >> source;
    int src = source - 'A';

    bellmanFord(n,src);

    return 0;
}
