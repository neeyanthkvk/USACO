#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

int N, posi[5001];
char c[5000];

int main() {
	cin >> N;
	posi[0] = 1;
	F0R(i,N) {
	    cin >> c[i];
	    if (i > 0 && c[i-1] == 'f') {
	        FORd(i,1,5001) posi[i] = posi[i-1];
	        posi[0] = 0;
	    } else {
	        int cum = 0;
	        F0Rd(j,5001) {
	            cum = (cum+posi[j]) % MOD;
	            posi[j] = cum;
	        }
	    }
	}
	int ans = 0;
	F0R(i,5001) ans = (ans+posi[i])%MOD;
	cout << ans;
}