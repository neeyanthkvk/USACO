using namespace std;
#include <bits/stdc++.h> 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


const int MOD = 1000000007;

int n,m;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    DSU() {
		for(int i = 0; i < SZ; i++) {
			par[i] = i;
			sz[i] = 1;
		}
    }
    
    int get(int x) {
    	if (par[x] != x) {
			par[x] = get(par[x]);
		}
    	return par[x];
    }
    
    bool unite(int x, int y) { 
    	x = get(x);
		y = get(y);
    	if (x == y) { 
			return 0;
		}
		if (sz[x] < sz[y]) {
			swap(x,y);
		}
    	sz[x] += sz[y];
		par[y] = x;
    	return 1;
    }
};

DSU<100001> D;
int c[100001];
map<int,int> t;

int main() {
	cin >> n >> m;
	for(int i = 1; i < n+1; i++) {
		cin >> c[i];
	}
	for(int i = 0; i < m; i++) {
	    int a,b; 
		cin >> a >> b;
	    D.unite(a,b);
	}
	for(int i =1; i < n+1; i++) {
	    D.par[i] = D.get(i);
	    if (t.count(D.par[i])) {
			t[D.par[i]] = min(t[D.par[i]],c[i]);
		}
	    else {
			t[D.par[i]] = c[i];
		}
	}
	ll ans = 0;
	for (auto a: t) {
		ans += a.second;
	}
	cout << ans;
}