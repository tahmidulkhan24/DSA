#include <bits/stdc++.h>
using namespace std;
int n,e;
vector<int> adj[100];
int in_deg[100];
int cnt;
map<int,int> m1,m2;
queue<int> q;
vector<int> res;
void init()
{
    cnt=0;
    for(int i=0;i<n;i++)
    {
        in_deg[i]=0;

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
void top_sort()
{
    for(int i=1;i<=cnt;i++)
    {
        if(in_deg[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        res.push_back(u);
        for(int v:adj[u])
        {
            in_deg[v]--;
            if(in_deg[v]==0)
            {
                q.push(v);
            }
        }
    }
    if (res.size() != cnt) {
        cout << "Cycle detected! Topological sort not possible.\n";
    } else {
        cout << "Topological Order (Course Codes):\n";
        for (int node : res) {
            cout << m2[node] << endl;  // Output the corresponding course code
        }
    }
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
        in_deg[v]++;
    }
     top_sort();
    return 0;
}