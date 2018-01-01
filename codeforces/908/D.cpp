#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MOD 1000000007

ll mul_inv(ll a, ll b = MOD) {
  ll t1 = a, t2 = b, t3;
  ll v1 = 1, v2 = 0, v3;
  while (t2 != 1) {
    ll x = t1 / t2;
    t3 = t1 - x*t2;
    v3 = v1 - x*v2;
    t1 = t2, t2 = t3;
    v1 = v2, v2 = v3;
  }
  return (v2 + b) % b;
}

int K;
ll dp[1050][1050];
ll getdp(int a, int b) {
    if (b >= K) return b;
        return dp[a][b];
}
int main() {
    int Pa, Pb, i, j;
    cin >> K >> Pa >> Pb;
    for (i = 0; i < K; i++) {
      dp[K][i] = (i + K + Pa * mul_inv(Pb)) % MOD;
    }
    for (i = K - 1; i >= 1; i--) {
      for (j = K - 1; j >= 0; j--) {
        dp[i][j] = Pa * getdp(i + 1, j) + Pb * getdp(i, i + j);
        dp[i][j] %= MOD;
        dp[i][j] = (dp[i][j] * mul_inv(Pa + Pb)) % MOD;
      }
    }
    ll x = dp[1][0];
    cout << x << endl;
}
