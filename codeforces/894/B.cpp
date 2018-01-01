#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll recurPowMod(ll a, ll b, ll MOD) {
    if(b == 1) {
        return a%MOD;
    }
    if(b == 0) {
        return 1;
    }
    ll half = recurPowMod(a, b/2, MOD);
    if(b % 2 == 0) {
        return half*half % MOD;
    }
    return half*half%MOD * a%MOD;
}
#define MODN 1000000007
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    if(n % 2 == 0 && m % 2 == 1 && k == -1) {
        cout << 0 << endl;
        return 0;
    }
    if(n % 2 == 1 && m % 2 == 0 && k == -1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    int sq = (((n-1)%(MODN-1))*((m-1)%(MODN-1)))%(MODN-1);
    cout << ans * recurPowMod(2, sq, MODN) << endl;
}
