#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int n,x,k;
vi a;
ll ans = 0;
map<int,int> tmp;

void solve() {
    map<int,int> co;
    for(int i = 0; i < n; i++) {
        co[(a[i]-1)/x] ++;
        ans += co[a[i]/x-k];
    }
}

bool ok(int z) {
    if (z % x == 0 && k == 1) return 1;
    if (z % x != 0 && k == 0) return 1;
    return 0;
}

int main() {
	cin >> n >> x >> k; a.resize(n);
	for(int i = 0; i < n; i++) {
	    cin >> a[i];
	    tmp[a[i]] ++;
	}
	sort(a.begin(),a.end());
	for (auto& a: tmp) if (ok(a.first)) {
	    ans += (ll)a.second*(a.second-1)/2;
	}
	solve();
	cout << ans;
}
