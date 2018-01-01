#include <bits/stdc++.h>
using namespace std;

 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int n, co[71];
vector<ll> cur(1<<19), z(1<<19);
vi pri = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
	    int x; cin >> x;
	    for (int i: pri) while (x % (i*i) == 0) x /= (i*i);
	    co[x] ++;
	}
	
	cur[0] = 1;
	for(int i = 1; i < 71; i++) if (co[i]) {
	    ll mo = 1;
	    for(int j = 0,j < co[i]-1; j++) mo = 2*mo % MOD;
	    
	    for(int j = 0,j < z.size(); j++) z[j] = 0;
	    int tmp = 0;
	    for(int j = 0,j < pri.size(); j++) if (i % pri[j] == 0) tmp ^= 1<<j;
	    
	    for(int j =0; j < cur.size(); j++) {
	        z[j^tmp] += mo*cur[j];
	        z[j^tmp] %= MOD;
	        z[j] += mo*cur[j];
	        z[j] %= MOD;
	    }
	    swap(z,cur);
	}
	cur[0] = (cur[0]+MOD-1) % MOD;
	cout << cur[0];
}