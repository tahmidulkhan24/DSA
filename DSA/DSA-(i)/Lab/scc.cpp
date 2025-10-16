#include <bits/stdc++.h>
using namespace std;
int n,e;
vector<int> adj[100],adjt[100];
stack<int> st;
bool vis1[100],vis2[100];
void init(){
    for(int i=0; i<n; i++){
        vis1[i] = 0;
        vis2[i] = 0;
    }
}
 
void dfs(int u){
    vis1[u] = 1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(vis1[v]==0)   dfs(v);
    }
    st.push(u);
}
void dfs2(int u){
    vis2[u] = 1;
    cout<<(char)(u+97)<<" ";
    for(int i=0; i<adjt[u].size(); i++){
        int v = adjt[u][i];
        if(vis2[v]==0)   dfs2(v);
    }
}
 
int main()
{
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        char uc,vc;
        cin>>uc>>vc;
        int u = (int)uc - 97;
        int v = (int)vc - 97;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }
    init();
    for(int i=0; i<n; i++){
        if(vis1[i]==0)   dfs(i);
    }
    int scc=1;
    while(!st.empty())
    {
        int s=st.top();
        st.pop();
        if(!vis2[s])
        {
            cout<<"SCC->"<<scc<<": ";
            scc++;
            dfs2(s);
            cout<<endl;
        }
    }
    return 0;
}