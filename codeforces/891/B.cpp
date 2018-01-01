#include <bits/stdc++.h>

using namespace std;

int u[100050];
int in[100050];
int ch[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= N; i++) u[i] = i;
	sort(u + 1, u + N + 1, [](int a, int b) {
		return in[a] < in[b];
	});
	for (i = 1; i <= N; i++) ch[u[i]] = i;
	for (i = 1; i <= N; i++) {
		int t = ch[i];
		if (t == N) t = 1;
		else t++;
		printf("%d ", in[u[t]]);
	}
	return !printf("\n");
}