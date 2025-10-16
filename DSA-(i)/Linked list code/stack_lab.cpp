#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    for(int i=1;i<=5;i++)
    {
        int n;
        cin>>n;
        s.push(n);
    }
    int sum=0;
    while(!s.empty())
    {
        sum=sum+s.top();
        s.pop();
    }
    cout<<sum;

    return 0;
}