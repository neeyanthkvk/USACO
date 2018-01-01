/*
PROG: cowxor
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


int total[100010], a[22];
bool s[4200000];


int main() {
    freopen("cowxor.in", "r", stdin);
    freopen("cowxor.out", "w", stdout);
    int maxp = 1, ans = 0, n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        total[i] = total[i-1] ^ p;
    }
    
    a[1] = 1;
    for (int i = 2; i <= 21; ++i) a[i] = (a[i-1] << 1) + 1;
    
    for (int i = 1; i <= n; ++i) {
        int p, q = total[i-1];
        for (int j = 0; j <= 20; ++j) {
            p = (q & ~a[j]) >> j;
            s[a[21 - j] + p] = true;
        }
        q = 0;
        int now = total[i];
        for (int j = 20; j >= 0; --j) {
            q += a[j] + 1;
            if (s[(((q ^ now) & ~a[j]) >> j) + a[21 - j]]) {
                if (q > ans) {
                    ans = q;
                    maxp = i;
                }
            } else {
                q -= a[j] + 1;
            }
        }
    }
    
    int j;
    for (j = maxp; j >= 1; --j) 
     if ((total[j-1] ^ total[maxp]) == ans) break;
    
    cout << ans << " " << j << " " << maxp << endl;
    
    return 0;
}
