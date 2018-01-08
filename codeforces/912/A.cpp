#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ll A, B, x, y, z;
    cin >> A >> B >> x >> y >> z;

    ll totA, totB;
    totA = 2*x+y;
    totB = y + 3*z;
    ll ans = 0;
    if(totA > A) {
        ans += (totA-A);
    }
    if(totB > B) {
        ans += (totB-B);
    }
    cout << ans;

}
