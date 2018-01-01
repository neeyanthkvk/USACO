/*
ID: neeyant2
PROG: fence9
LANG: C++
*/
#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
    int n, m, p, a, b, ans = 0;
    cin >> n >> m >> p;
    for (int i = 1; i < m; ++i) {
        a = (i * n) / m + 1;
        if ((p * m + (n - p) * i) % m == 0)
            b = (p * m + (n - p) * i) / m - 1;
        else
            b = (p * m + (n - p) * i) / m;
        ans += (b - a + 1);
    }
    cout << ans << endl;
    return 0;
}
