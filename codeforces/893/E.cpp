#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MOD = 1000000007;

template<int SZ> struct Combo {
    ll fac[SZ+1], ifac[SZ+1];
    
    Combo() {
        fac[0] = ifac[0] = 1;
    	for(int i = 1; i < SZ+1; i++) {
    	    fac[i] = i*fac[i-1] % MOD;
    	    ifac[i] = inv(fac[i]);
    	}
    }
    
    ll po (ll b, ll p) {
        return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
    }
    
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll comb(ll a, ll b) {
        if (a < b) return 0;
        ll tmp = fac[a]*ifac[b] % MOD;
        tmp = tmp*ifac[a-b] % MOD;
        return tmp;
    }
};

Combo<2000005> C;

int q,x,y;
ll po2[1000005];
vi fac[1000001];

bool comp[1000001];

void solve() {
    cin >> x >> y;
    ll ans = po2[y-1];
    for (auto a: fac[x]) 
		ans = ans*C.comb(a+y-1,y-1) % MOD;
    cout << ans << "\n";
}

int main() {
	po2[0] = 1;
	for(int i = 2; i < 1000001; i++) 
		if (!comp[i]) {
			for (int j = i; j <= 1000000; j += i) {
				comp[j] = 1;
				int t = 0; int j1 = j; while (j1 % i == 0) j1 /= i, t++;
				fac[j].push_back(t);
			}
		}
	for(int i = 1; i < 1000005; i++) po2[i] = 2*po2[i-1] % MOD;
	cin >> q;
	for(int i =0 ; i < q; i++) {
		solve();
	}
}