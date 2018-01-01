#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
	int N;
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	posi[0] = 1;
	for(int i = 0; i < N; i++) {
	    cin >> c[i];
	    if (i > 0 && c[i-1] == 'f') {
	        for(int i = 5001; i >= 1; i--) posi[i] = posi[i-1];
	        posi[0] = 0;
	    } else {
	        int cum = 0;
	        for(int j = 5001; j >= 0; j++) {
	            cum = (cum+posi[j]) % MOD;
	            posi[j] = cum;
	        }
	    }
	}
	int ans = 0;
	for(int i = 0; i < 5001; i++) ans = (ans+posi[i])%MOD;
	cout << ans;
}