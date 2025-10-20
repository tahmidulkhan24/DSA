#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

   
    vector<int> primeDivCount(n + 1, 0);

    
    for (int i = 2; i <= n; i++) {
        if (primeDivCount[i] == 0) { // Means i is prime
            for (int j = i; j <= n; j += i) {
                primeDivCount[j]++; // Add this prime to all its multiples
            }
        }
    }

    int totalcnt = 0;
    for (int i = 2; i <= n; i++) {
        if (primeDivCount[i] == 2) { // Exactly 2 distinct prime divisors
            totalcnt++;
        }
    }

    cout << totalcnt << endl;
    return 0;
}
