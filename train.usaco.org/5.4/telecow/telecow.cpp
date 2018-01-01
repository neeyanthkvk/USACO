/*
PROG: telecow
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


const int MAXN = 210;
const int INF = 1000000000;

int n, m;
long long x[MAXN][MAXN], xx[MAXN][MAXN];
int l[MAXN], fa[MAXN], h[MAXN], hh[MAXN];
long long ff[MAXN];


long long max_flow(int s, int t) {
    memset(ff, 0, sizeof(ff));
    memset(fa, 0, sizeof(fa));
    memset(h, 0, sizeof(h));
    memset(hh, 0, sizeof(hh));
    
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= n; ++j) x[i][j] = xx[i][j];
    
    hh[0] = n;
    for (int i = 1; i <= n; ++i) l[i] = 1;
    
    int i = s;
    long long now = INF, ans = 0;
    
    while (h[s] < n) {
        ff[i] = now;
        bool flag = false;
        for (int j = l[i]; j <= n; ++j) {
            if (x[i][j] > 0 && h[j] + 1 == h[i]) {
                flag = true;
                l[i] = j;
                if (x[i][j] < now) now = x[i][j];
                fa[j] = i;
                i = j;
                if (i == t) {
                    ans += now;
                    while (i != s) {
                        int tmp = i;
                        i = fa[i];
                        x[i][tmp] -= now;
                        x[tmp][i] += now;
                    }
                    now = INF;
                }
                break;
            }
        }
        if (flag) continue;
        int min = n-1, jl;
        for (int j = 1; j <= n; ++j)
         if (x[i][j] > 0 && h[j] < min) {
             jl = j;
             min = h[j];
         }
        
        l[i] = jl;
        --hh[h[i]];
        if (hh[h[i]] == 0) break;
        h[i] = min + 1;
        ++hh[h[i]];
        if (i != s) {
            i = fa[i];
            now = ff[i];
        }
    }
    
    return ans;
}



int main() {
    freopen("telecow.in", "r", stdin);
    freopen("telecow.out", "w", stdout);
    int s, t, a, b;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; ++i) xx[i*2][i*2+1] = 1;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        xx[a*2+1][b*2] = MAXN;
        xx[b*2+1][a*2] = MAXN;
    }
    
    n += n + 1;
    
    int ans = max_flow(s * 2 + 1, t * 2);
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        if (i == s || i == t) continue;
        xx[i*2][i*2+1] = 0;
        int tmp = max_flow(s * 2 + 1, t * 2);
        if (tmp + 1 == ans) {
            --ans;
            cout << i;
            if (ans == 0) 
                cout << endl;
            else 
                cout << " ";
        } else {
            xx[i*2][i*2+1] = 1;
        }
    }
    
    return 0;
}