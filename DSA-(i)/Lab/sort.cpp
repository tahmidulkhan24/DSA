#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a[7] = {4, 8, 3, 0, 2, 6, 7};
    int x;
    cin >> x;
    sort(a + 1, a + x + 2);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}