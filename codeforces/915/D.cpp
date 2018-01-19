#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
int n;
vector<vector<int> > g;
bool marked[500];

int main() {
	int m;
	cin >> n >> m;
	F0R(i,n) {
		vector<int> l;
		g.push_back(l);
	}
	F0R(i,n) {
		marked[i] = false;
	}
	F0R(i,m) {
		int a,b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
	}
	
}

// read!read!read!read!read!read!read!
// ll vs. int!
