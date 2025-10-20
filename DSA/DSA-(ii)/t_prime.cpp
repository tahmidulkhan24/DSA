#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 1;
int a[N]; // 1 = not prime, 0 = prime
 
void init(int n) {
    for (int i = 0; i <= n; i++)
        a[i] = 0;
    a[0] = a[1] = 1;
}
 
void sieve(int n) {
    init(n);
    for (int i = 4; i <= n; i += 2)
        a[i] = 1;
 
    for (int i = 3; i * i <= n; i += 2) {
        if (a[i] == 1) continue;
        for (int j = i * i; j <= n; j += 2 * i)
            a[j] = 1;
    }
}
 
int main() {
    int n;
    cin >> n;
    sieve(1e6);
 
    while (n--) {
        long long x;
        cin >> x;
        long long y = sqrtl(x);
 
        if (y * y == x && a[y] == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}