#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<int> adj[100];
bool vis[100];
int start[100];
int finish[100];
int parent[100];
int timer;
void init()
{
    timer = 1;
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
        start[i] = 0;
        finish[i] = 0;
        parent[i]=-1;
    }
}
void dfs(int src)
{
    vis[src] = true;
    start[src]=timer++;
    for (auto child : adj[src])
    {
        if (!vis[child])
        {
            parent[child]=src;
            cout<<(char)(src+65)<<"->"<<(char)(child+65)<<" is a tree edges\n";
            dfs(child);
        }
        else if(child!=parent[src])
        {
            if(start[child]<start[src] && finish[0]==0)
            {
                cout<<(char)(src+65)<<"->"<<(char)(child+65)<<" is a back edges\n";
            }
            else if(start[child]>start[src] && finish[0]!=0)
            {
                cout<<(char)(src+65)<<"->"<<(char)(child+65)<<" is a forward edges\n";
            }
            else if (finish[child] < start[src])
            {
                cout<<(char)(src+65)<<"->"<<(char)(child+65)<<" is a cross edges\n";
            }
        }
           
    }
    finish[src]=timer++;
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        char uc, vc;
        cin >> uc >> vc;
        int u = (int)uc - 65; // uppercase letter
        int v = (int)vc - 65;
        adj[u].push_back(v);
    }
    char src;
    cin>>src;
    int u=(int)src-65;
    init();
    dfs(u);
    for(int i=0;i<n;i++)
    {
        if(!vis[i]) dfs(i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<"start-"<<(char)(i+65)<<" "<<start[i]<<" || ";
        cout<<"end-"<<finish[i]<<endl;
    }
    return 0;
}