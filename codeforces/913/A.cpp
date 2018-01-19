#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll pow2(int n) {
    if (n == 0) return 1;
    return 2 * pow2(n-1);
}

int main() {
    ll m, n;
    cin >> n >> m;

    int curPow = 0;
    ll pow = 1;
    while(m % pow == 0) {
        curPow += 1;
        pow *= 2;
    }
    pow /= 2;
    curPow -= 1;
    if(curPow >= n) {
        cout << 0 << endl;
        return 0;
    }
    n -= curPow;
    m /= pow;
    int base = log2(m);
    if(n > base) {
        cout << m*pow << endl;
        return 0;
    }
    if(n == base) {
        ll temp = pow2(n);
        cout << (m-temp)*pow << endl;
        return 0;
    }
    if(n < base) {
        ll temp = pow2(n);
        m = m%temp;
        cout << m*pow << endl;
        return 0;
    }
}
