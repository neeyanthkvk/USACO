#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}

int in[2050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	int g = 0;
	for (i = 1; i <= N; i++) g = gcd(g, in[i]);
	if (g != 1) return !printf("-1\n");

	int c = 0;
	for (i = 1; i <= N; i++) if (in[i] == 1) c++;
	if (c) return !printf("%d\n", N - c);

	int mn = 0x3f3f3f3f;
	for (i = 1; i <= N; i++) {
		int g = in[i];
		for (j = i - 1; j >= 1; j--) {
			g = gcd(g, in[j]);
			if (g == 1) break;
		}
		if (j >= 1) mn = min(mn, i - j);

		g = in[i];
		for (j = i + 1; j <= N; j++) {
			g = gcd(g, in[j]);
			if (g == 1) break;
		}
		if (j <= N) mn = min(mn, j - i);
	}
	return !printf("%d\n", mn + N - 1);
}