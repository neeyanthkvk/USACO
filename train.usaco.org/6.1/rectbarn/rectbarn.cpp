/*
PROG: rectbarn
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 3010;

int n, m, p, ans;
vector<pair<int, int> > x;
int l[MAXN], r[MAXN], h[MAXN];


int check(int a, int b) {
    for (int i = a; i <= b; ++i) {
        ++h[i];
        if (h[i] == 1) {
            l[i] = a;
            r[i] = b;
        } else {
            l[i] = max(a, l[i]);
            r[i] = min(b, r[i]);
        }
        int k = h[i] * (r[i] - l[i] + 1);
        if (k > ans) ans = k;
    }
}


int main() {
    freopen("rectbarn.in", "r", stdin);
    freopen("rectbarn.out", "w", stdout);
    cin >> n >> m >> p;
    for (int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        x.push_back(make_pair(a, b));
    }
    x.push_back(make_pair(n + 1, m + 1));
    sort(x.begin(), x.end());
    
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        if (x[k].first != i) {
            check(1, m);
            continue;
        } 
        int left = 1, j = x[k].second;
        while (true) {
            if (x[k].first == i && x[k].second == j) {
                check(left, j - 1);
                h[j] = 0;
                left = j + 1;
                while (x[k].first == i && x[k].second == j) ++k;
                j = x[k].second;
                if (x[k].first > i) break;
            } else {
                break;
            }
        }
        check(left, m);
    }
    
    cout << ans << endl;
    
    return 0;
}
