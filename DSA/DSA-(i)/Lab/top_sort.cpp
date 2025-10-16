#include <bits/stdc++.h>
using namespace std;
int n,e;
vector<int> adj[100];
bool vis[100];
int cnt;
map<int,int> m1,m2;
stack<int> s;
void init()
{
    cnt=0;
    for(int i=0;i<n;i++)
    {
        vis[i]=false;

    }
}
int convert(int course_code)
{
    if(m1[course_code]==0)
    {
        cnt++;
        m1[course_code]=cnt;
        m2[cnt]=course_code;
        return cnt;
    }
    return m1[course_code];
}
void dfs(int src)
{
    vis[src]=true;
    for(int child:adj[src])
    {
        if(!vis[child]) dfs(child);
    }
    s.push(src);
}
int main()
{
    cin>>n>>e;
    init();
    while(e--)
    {
        int uc,vc;
        cin>>uc>>vc;
        int u=convert(uc);
        int v=convert(vc);
        adj[u].push_back(v);
    }
    dfs(convert(203));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    for(int i=0;i<n;i++)
    {
        int ans=s.top();
        s.pop();
        cout<<m2[ans]<<endl;
    }
    return 0;
}