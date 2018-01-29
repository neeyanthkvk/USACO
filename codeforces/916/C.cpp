#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(ll n) {
    ll bound = sqrtl(n);
    for(ll i = 2; i <= bound; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int minPrime(ll x) {
    ll y = x;
    while(!isPrime(y)) {
        y++;
    }
    return y;
}

int main() {
    int n,m;
    cin >> n >> m;
    ll k = minPrime(max(n,m));
    ll fin = k-(n-2);
    cout << k << " " << k << endl;
    for(int i = 1; i < n-1; i++) {
        cout << i << " " << (i+1) << " 1" << endl;
    }
    cout << (n-1) << " " << n << " " << fin << endl;
    m -= (n-1);
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(m <= 0) return 0;
            if(i == j || abs(i-j) == 1) continue;
            cout << i << " " << j << " " << (k+1) << endl;
            m -= 1;
        }
    }       

}
