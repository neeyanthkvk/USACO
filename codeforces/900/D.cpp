#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD 1000000007;
ll choose(ll n, ll k) {
    if(k == 0) return 1;
    return (n* choose(n-1, k-1) / k) % MOD;
}

vector<ll> divisors(ll n) {

    vector<ll> v;
    for (ll i=2; i<=sqrt(n); i++)
    {
        if(n % i == 0) {
			v.push_back(i);
			v.push_back(n/i);
		}

	}
	return v;
}

int main() {
    long long x, y;
    cin >> x >> y;
    if(y % x != 0) {
        cout << 0;
    }
    y = y/x;
	vector<ll> divs = divisors(y);
	ll ans = choose(2*y-1, y-1);
	for(int i = 0; i < divs.size(); i++) {
		ll temp = divs[i];
		ans -= choose(2*temp-1, temp-1);
		if(ans < 0) {
			ans += MOD;
		}
		ans  = ans % MOD;
	}
	cout << ans;
}
