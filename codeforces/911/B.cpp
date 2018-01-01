#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, n;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 1; i < n; i++) {
        int ax = a/i;
        int bx = b/(n-i);
        int minx = ax>bx?bx:ax;
        if(minx > ans) {
            ans = minx;
        }
    }
    cout << ans << endl;
}
