/**
* Sources: various
*/

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


char ch[1100];
int K,n,f[1100],dp[1100];

const int MOD=1e9+7;

int main(){
	cin >> ch+1;
	cin >> K; n=strlen(ch+1);
	if (K==0){
		cout << 1 << endl; return 0;
	}
	f[1]=0;
	FOR(i,2,n+1) f[i]=f[__builtin_popcount(i)]+1;
	int pre=0; dp[0]=0;
	FOR(i,1,n+1){
		for (int j=n;j;j--) dp[j]=(dp[j]+dp[j-1])%MOD;
		if (ch[i]=='1') dp[pre]++;
		pre+=ch[i]-'0';
	}
	dp[pre]++;
	int ans=0;
	FOR(i,1,n+1) if (f[i]==K-1){
		ans=(ans+dp[i])%MOD;
	}
	if (K==1) ans=(ans-1+MOD)%MOD;
	cout<<ans<<endl; return 0;
}

// read!read!read!read!read!read!read!
// ll vs. int!
