#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int workpow = 1;
    int curpow = 2;
    int curpownum = 1;
    while(true) {
        if(n % curpow != 0) {
            int ans = workpow*(2*workpow-1);
            cout << ans << endl;
            return 0;
        }
        if(n % (2*curpow-1) == 0) {
            workpow = curpow;
        }
        curpownum += 1;
        curpow *= 2;
    }
    return 0;
}
