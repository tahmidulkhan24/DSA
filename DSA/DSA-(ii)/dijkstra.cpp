#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

class Node{
    public:
        int id;
        int key;

        Node(){
        }

        Node (int i, int k){
            id = i;
            key = k;
        }
};

class PriorityQueue{
     
  public:

    Node heap[105];
    int index[105];
    int length;

    PriorityQueue(int n){
        length = n;
        for(int i=0; i<n; i++){
            Node temp(i, INF);
            heap[i+1] = temp;
            index[i] = i+1;
        }
    }

    Node extractMin(){
        if(length==0)   return Node(-1, INF);
        Node n = heap[1];
        heap[1] = heap[length];
        index[heap[1].id]=1;
        length--;

        int i =1;
        while(i<=length/2){
            int l = 2*i;
            int r = l + 1;

            Node minNode = heap[l];
            int minIndex = l;
            if(r<=length && heap[r].key < heap[l].key){
                minIndex = r;
                minNode = heap[r];
            }

            if(minNode.key < heap[i].key){
                index[minNode.id] = i;
                index[heap[i].id] = minIndex;
                swap(heap[i], heap[minIndex]);
                i = minIndex;
                continue;
            }
            break;
        }
        index[n.id] = -1;
        return n;
    }

    void decreaseKey(int id, int v){
        int i = index[id];
        heap[i].key = v;
        while(i>1){
            int p = i/2;
            if(heap[p].key > heap[i].key){
                index[heap[p].id] = i;
                index[heap[i].id] = p;
                swap(heap[p],heap[i]);
                i = p;
                continue;
            }
            break;
        }
    }

    bool exists(int id){
        if(index[id]==-1)   return false;
        return true;
    }

    bool empty(){
        if(length==0)   return true;
        return false;
    }

};

vector<pair<int,int>> adj[105];
int dis[105];
int par[105];

void dijkstra(int n,int src)
{
    for(int i=0;i<n;i++)
    {
        dis[i]=INF;
        par[i] = -1;
    }
    PriorityQueue pq(n);
    dis[src]=0;
    pq.decreaseKey(src,0);

    while(!pq.empty())
    {
        Node un=pq.extractMin();
        for(auto v:adj[un.id])
        {
           if(pq.exists(v.first) && dis[v.first] > dis[un.id] + v.second)
           {
               par[v.first] = un.id;
               dis[v.first] = dis[un.id] + v.second;
               pq.decreaseKey(v.first, dis[v.first]);
           }
        }
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
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); 
    }

    char source;
    cin >> source;
    int src = source - 'A';

    dijkstra(n,src);

    cout << "\nNode\tDistance\tParent\n";
    for(int i=0; i<n; i++){
        cout << char('A' + i) << "\t";
        if(dis[i] == INF) cout << "INF\t\t";
        else cout << dis[i] << "\t\t";
        if(par[i] == -1) cout << "None\n";
        else cout << char('A' + par[i]) << "\n";
    }

    return 0;
}
