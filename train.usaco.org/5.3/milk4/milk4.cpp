#include <bits/stdc++.h>
using namespace std;
/*
TASK: milk4
LANG: C++

*/
int n, m;
int x[101], y[101];
bool z[20010];

bool check(int nn) {
    if (nn == 1) return m % y[0] == 0;
    if (nn == 2) {
        int i = m;
        while (i > 0) {
            if (i % y[1] == 0) return true;
            i -= y[0];
        }
        return false;
    }
    
    memset(z, 0, sizeof(z));
    z[0] = true;
    
    for (int i = 0; i < nn; ++i)
     for (int j = 0; j <= m - y[i]; ++j) {
         if (z[j]) z[j+y[i]] = true;
         if (z[m]) return true;
     }
    
    return false;    
}


bool dfs(int a, int b, int nn) {
    if (a == nn) {
        if (check(nn)) {
            cout << nn;
            for (int i = 0; i < nn; ++i) cout << " " << y[i];
            cout << endl;
            return true;
        }
        return false;
    }
    for (int i = b; i < n - (nn - a - 1); ++i) {
        y[a] = x[i];
        if (dfs(a + 1, i + 1, nn)) return true;
    }
    return false;
}


int main() {
    freopen("milk4.in", "r", stdin);
    freopen("milk4.out", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    sort(x, x+n);
    
    for (int i = 1; i <= n; ++i) 
     if (dfs(0, 0, i)) break;
    
    return 0;
}
