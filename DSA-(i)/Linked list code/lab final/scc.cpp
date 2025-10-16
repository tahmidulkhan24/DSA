#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100],adjt[100];
bool vis[100],vist[100];
stack<int> st;
int n,e;
void init(){
    for(int i=0; i<n; i++){
        vis[i] = 0;
        vist[i] = 0;
    }
}
void dfs(int src)
{
    vis[src]=true;
    for(int child:adj[src])
    {
         if(!vis[child]) dfs(child);
    }
    st.push(src);
}
void dfst(int src)
{
    vist[src]=true;
    cout<<(char)(src+97)<<" ";
    for(int child:adjt[src])
    {
         if(!vist[child]) dfst(child);
    }
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        char a,b;
        cin>>a>>b;
        int u=(int)a-97;
        int v=(int)b-97;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }
    init();
    for(int i=0; i<n; i++){
        if(vis[i]==0)   dfs(i);
    }
    int scc=1;
    while(!st.empty())
    {
        int s=st.top();
        st.pop();
        if(!vist[s])
        {
            cout<<"SCC->"<<scc<<": ";
            scc++;
            dfst(s);
            cout<<endl;
        }
    }
    return 0;
}