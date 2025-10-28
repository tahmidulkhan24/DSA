#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

struct Node{
    int id;
    int key;

    Node(){
    }

    Node (int i, int k){
        id = i;
        key = k;
    }
};

struct PriorityQueue{
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

vector < pair<int, int> > adj[105];
int key[105], par[105];
int weight[105][105];

int prims(int n, int r){
    for(int i=0; i<n; i++)  key[i] = INF;
    PriorityQueue pq(n);
    key[r] = 0;
    pq.decreaseKey(r, 0);
    par[r] = -1;

    while( !pq.empty() ){
        Node un = pq.extractMin();
        int u = un.id;
        for(int i=0; i<adj[u].size(); i++){
            pair<int, int> p;
            p = adj[u][i];
            int v = p.first;
            int w = p.second;
            if( pq.exists(v) && w < key[v] ){
                par[v] = u;
                key[v] = w;
                pq.decreaseKey(v, w);
            }
        }
    }

    int cost = 0;
    for(int i=0; i<n; i++)  cost+=key[i];
    return cost;
}


int main(){
    int n, e;
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        pair<int, int>p;
        p.first = v;
        p.second = w;
        adj[u].push_back(p);
        p.first = u;
        adj[v].push_back(p);

        weight[u][v] = w;
        weight[v][u] = w;
    }
    int res = prims(n, 0);
    cout<<res<<endl;
    return 0;
}
/*
9 14
7 6 1
8 2 2
6 5 2
0 1 4
2 5 4
8 6 6
2 3 7
7 8 7
0 7 8
1 2 8
3 4 9
5 4 10
1 7 11
3 5 14
*/