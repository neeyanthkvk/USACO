/*
ID: neeyant2
PROG: theme
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 5001;

int n;
int x[MAXN];


int main() {
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    
    int ans = 0;
    
    for (int i = 5; i < n; ++i) {
        int a = i, b = 1;
        for (int j = i+1; j < n; ++j) {
            if (x[j] - x[j-i] == x[j-1] - x[j-i-1]  && j-i < a) {
                ++b;
                if (b > ans) ans = b;
            } else {
                a = j;
                b = 1;    
            }
        }
    }
    
    if (ans < 5)
        cout << 0 << endl;
    else
        cout << ans << endl;
    
    return 0;
}