#include <bits/stdc++.h>
using namespace std;
void f(string s, int n, int a[])
{
    if (s.size() == n)
    {
         cout << "{ ";
       for(int i=0;i<n;i++)
       {
        if(s[i]=='1')
        {
            cout<<a[i]<<" ";
        }
       }
       cout<<"}"<<endl;
        return;
    }
    f(s + "0", n, a);
    f(s + "1", n, a);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    f("", n, a);
    return 0;
}