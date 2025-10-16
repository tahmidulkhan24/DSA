#include <bits/stdc++.h>
using namespace std;
int n,e;
map<int,int> m1,m2;
vector<int> adj[100];
int cnt;
bool vis[100];
stack<int> st;
void init()
{
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
    }
    cnt=0;
}
int convert(int course)
{
    if(m1[course]==0)
    {
        m1[course]=cnt;
        m2[cnt]=course;
        cnt++;
    }
    return m1[course];
}
void dfs(int src)
{
    vis[src]=true;
    for(auto child:adj[src])
    {
        if(!vis[child]) dfs(child);
    }
    st.push(src);
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        int u=convert(a);
        int v=convert(b);
        adj[u].push_back(v);
    }
    init();
    dfs(convert(203));
    for(int i=0;i<n;i++)
    {
        if(!vis[i]) dfs(i);
    }
    for(int i=0;i<n;i++)
    {
        int ans=st.top();
        st.pop();
        cout<<m2[ans]<<endl;
    }
    return 0;
}