/*
ID: neeyant2	
PROG: milk6
LANG: C++11
*/


#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 33;
const long long INF = 2100000000;

struct line {
    int x, y;
    long long v;
};

int n, m;
long long x[MAXN][MAXN], xx[MAXN][MAXN];
int l[MAXN], fa[MAXN], h[MAXN], hh[MAXN];
long long ff[MAXN];
line origin[1010];


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
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        origin[i].x = a;
        origin[i].y = b;
        origin[i].v = c * 1001 + 1;
        xx[a][b] += c * 1001 + 1;
    }
    
    long long flow = max_flow(1, n);
    
    cout << flow / 1001 << " ";
    
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        a = origin[i].x;
        b = origin[i].y;
        c = origin[i].v;
        if (flow == xx[a][b] && xx[a][b] == c) {
            cout << 1 << endl << i+1 << endl;
            return 0;
        }
        xx[a][b] -= c;
        long long temp_flow = max_flow(1, n);
        
        if (temp_flow + c == flow) ans.push_back(i+1);
        xx[a][b] += c;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    
    return 0;
}