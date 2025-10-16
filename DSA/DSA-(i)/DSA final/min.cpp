#include <bits/stdc++.h>
using namespace std;
int findMin(int a[], int p, int q)
{
    if(p<q)
    {
        int mid=(p+q)/2;
        int x=findMin(a,p,mid);
        int y=findMin(a,mid+1,q);
        return min(x,y);
    }
    else
    return a[p];
}
int main()
{
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int p, q;
    p = 0;
    q = n - 1;
    int res = findMin(a, p, q);
    cout<<res;
    return 0;
}