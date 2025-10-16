#include <bits/stdc++.h>
using namespace std;
map<int, vector<string>> m;
void bfs(int n)
{
    queue<string> q;
    q.push("0");
    q.push("1");
    for(int i=1;i<=n;i++)
    {
        cout<<"Length "<<i<<":";
        vector<string> v;
        int size=q.size();
        while(size--)
        {
            string par=q.front();
            q.pop();
            cout<<par<<" ";
            v.push_back(par+'0');
            v.push_back(par+'1');
        }
        cout<<endl;
        for(auto s:v)
        {
            q.push(s);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    bfs(n);
    return 0;
}