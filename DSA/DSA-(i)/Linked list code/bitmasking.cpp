#include <bits/stdc++.h>
using namespace std;
void f(string s, int n)
{
    if (s.size() == n)
    {
        cout << s << endl;
        return;
    }
    f(s + "0", n);
    f(s + "1", n);
}
int main()
{
    int n;
    cin >> n;
    f("", n);
    return 0;
}