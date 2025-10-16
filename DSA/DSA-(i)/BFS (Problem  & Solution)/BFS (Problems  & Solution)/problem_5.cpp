#include <bits/stdc++.h>
using namespace std;

void bfs(string src, map<int, vector<string>> &ans, int n)
{
    queue<string> q;
    q.push(src);

    while (!q.empty())
    {
        string par = q.front();
        q.pop();

        if (par.size() > 0) ans[par.size()].push_back(par);
        
        if (par.size() == n) continue;

        // add '0' at left
        q.push(par + '0');

        // add '1' at right
        q.push(par + '1');
    }
}
int main()
{
    int n;
    cin >> n;

    map<int, vector<string>> ans;
    bfs("", ans, n);

    for (auto [x, y] : ans)
    {
        cout << "Length " << x << ": ";
        for (auto s : y) cout << s << " ";
        cout << endl;
    }

    return 0;
}

/*
INPUT-1:
-------
3

OUTPUT-1:
--------
Length 1: 0 1 
Length 2: 00 01 10 11 
Length 3: 000 001 010 011 100 101 110 111

INPUT-2:
-------
4

OUTPUT-2:
--------
Length 1: 0 1 
Length 2: 00 01 10 11 
Length 3: 000 001 010 011 100 101 110 111 
Length 4: 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111

*/