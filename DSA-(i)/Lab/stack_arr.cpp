#include <bits/stdc++.h>
using namespace std;
int sz=0;
int a[100];
void push(int x)
{
    if(sz>=100)
    {
        cout<<"stack overflow"<<endl;
        return; // Added return to prevent overflow
    }
    a[sz] = x;
    sz++;
}
void pop()
{
    if(sz==0)
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    sz--;
}
void top()
{
    if(sz==0)
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<a[sz-1]<<endl; // Corrected index to sz-1
}
void print(int i)
{
    if (i <= 0)
    {
        return;
    }
   
    cout << a[i-1] << " ";
    print(i-1);
}
int main()
{
    int n;
    while (1)
    {
        cout << "1.push\n2.pop\n3.print\n4.top" << endl;
        cin >> n;
        if (n == 1)
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (n == 2)
        {
            pop();
        }
        else if (n == 3)
        {
            print(sz);
            cout<<endl;
        }
        else if(n==4)
        {
            top();
        }
        else
        {
            cout<<"invalid";
        }
    }
    return 0;
}