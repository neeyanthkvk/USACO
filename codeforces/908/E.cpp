#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int r[1050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
char in[55][1050];

int sz[1050];
ll dp[1050];
ll C[1050][1050];
int main() {
	int M, N, i, j, k;
	scanf("%d %d", &M, &N);
	for (i = 0; i <= 1000; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	dp[0] = dp[1] = 1;
	for (i = 2; i <= 1000; i++) {
		dp[i] = 0;
		for (j = 0; j <= i - 1; j++) dp[i] = (dp[i] + dp[i - 1 - j] * C[i - 1][j]) % MOD;
	}

	for (i = 0; i < N; i++) scanf("%s", in[i]);

	for (i = 0; i < M; i++) r[i] = i;
	for (i = 0; i < M; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < N; k++) if (in[k][i] != in[k][j]) break;
			if (k >= N) r[root(i)] = root(j);
		}
	}

	int c = 0;
	for (i = 0; i < M; i++) sz[root(i)]++;


	ll ans = 1;
	for (i = 0; i < M; i++) ans = ans * dp[sz[i]] % MOD;
	return !printf("%lld\n", ans);
}
