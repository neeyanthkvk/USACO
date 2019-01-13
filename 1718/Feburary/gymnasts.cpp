#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1000000007;

set<ll> divs;
map<ll,ll> dp;

ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;  
    }
    return res;
}

set<ll> getDivs(ll n) {
	set<ll> temp;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) {
            temp.insert(i);
            temp.insert(n/i);
        }
    }
	return temp;
}

set<ll> getPrimes(ll n) {
	set<ll> temp;
	while(n % 2 == 0) {
		n /= 2;
		temp.insert(2);
	}
	for(int i = 3; i <= sqrt(n); i += 2) {
		while(n % i == 0) {
			n /= i;
			temp.insert(i);
		}
	}
	if(n > 2) temp.insert(n);
	return temp;
}


int main() {
    freopen("gymnasts.in","r",stdin);
    freopen("gymnasts.out","w",stdout);
    ll N;
    scanf("%lld", &N);
    if(N == 1) {
        cout << 1 << endl;
        return 0;
    }
    divs = getDivs(N);
    ll ans = N;
    if(ans >= MOD) ans %= MOD;
    for(ll p:divs) {
		if(N == p) continue;
        if(p == 2) {
            ans += N-2;
			dp[2] = ans;
            if(ans >= MOD) ans %= MOD;
        }
        else {
            ll temp = ((N-p)/p) % MOD;
			ll powers = power(2,p)-2;
			powers %= MOD;
			set<ll> primes = getPrimes(p);
			ll sumPrimes = 0;
			double tot = p;
			for(ll x:primes) {
				tot *= (x-1.0)/x;
				sumPrimes += power(2,x);
				if(sumPrimes > MOD) sumPrimes %= MOD;
			}
			ll totient = (ll) tot;
			ans += ((ll) (tot * powers/p)) % MOD;
			ll subtr = 0;
			for(ll x:primes) {
				ll n = p/x;
				subtr += power(2,n);
				if(n % x == 0) subtr -= power(2,x);
				if(subtr > MOD) subtr %= MOD;
			}
			powers = powers - subtr + (primes.size()-1) * sumPrimes;
			powers %= MOD;
			if(powers < 0) powers += MOD;
			ans += powers*ceil((p + 0.0 - tot)/ p);
			ans %= MOD;
        }
    }
    cout << ans << endl;
}


// read!read!read!read!read!read!read!
// ll vs. int!
