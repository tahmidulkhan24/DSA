#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int p, int q)
{
    int mid = (p + q) / 2;
    int n1 = mid - p + 1;
    int n2 = q - mid;
    int l[n1+1], r[n2+1];
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[p + i];
    }
    for (int i = 0; i < n1; i++)
    {
        r[i] = a[mid + 1 + i];
    }
    l[n1]=INT_MIN;
    r[n2]=INT_MIN;
    int i=0,j=0;
    for(int k=p;k<=q;k++)
    {
        if(l[i]>=r[j])
        {
            a[k]=l[i++];
        }
        else a[k]=r[j++];
    }
}
void merge_sort(int a[],int p,int q)
{
    if(p<q)
    {
       int mid=(p+q)/2;
       merge_sort(a,p,mid);
       merge_sort(a,mid+1,q);
       merge(a,p,q);
    }
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
    merge_sort(a, p, q);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}