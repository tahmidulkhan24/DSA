#include <bits/stdc++.h>
using namespace std;
void bfs(int a[],int n)
{
   queue<vector<int>> q;
   q.push({});
   for(int i=0;i<n;i++)
   {
    int sz=q.size();
    while(sz--)
    {
        vector<int> v=q.front();
        q.pop();
        cout<<"{ ";
        for(auto num:v)
        {
            cout<<num<<" ";
        }
        cout<<"}"<<endl;

        v.push_back(a[i]);
        q.push(v);

    }
   } 
   cout<<"{ ";
   for(int i=0;i<n;i++)
   {
     cout<<a[i]<<" ";
   }
   cout<<"}";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
         cin>>a[i];
    }
   bfs(a,n);
    return 0;
}