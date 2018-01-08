#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;



vector <pll> Vu[2];
vector <pll> Vsum[2];
void aa(vector <pll>& Vu, vector <pll>& Vsum, int N, int R) {
	if (N >= 2 * R - 1) {
		for (int i = 1; i <= R - 1; i++) Vu.emplace_back(i, 2);
		Vu.emplace_back(R, N - (2 * R - 2));
	}
	else {
		for (int i = 1; i <= N - R; i++) Vu.emplace_back(i, 2);
		Vu.emplace_back(N - R + 1, N - (2 * N - 2 * R));
	}
	Vsum.emplace_back(Vu[0].second, Vu[0].first * Vu[0].second);
	for (int i = 1; i < Vu.size(); i++) {
		Vsum.push_back(Vsum.back());
		Vsum.back().first += Vu[i].second;
		Vsum.back().second += Vu[i].first * Vu[i].second;
	}
}
pll getv(ll mi) {
	ll c1 = 0, c2 = 0;
	for (int i = 0; i < Vu[0].size(); i++) {
		ll t = Vu[0][i].first;
		t = (mi + t - 1) / t;

		int st2 = 0, en2 = (int)Vu[1].size() - 1, mi2, rv2 = Vu[1].size();
		while (st2 <= en2) {
			mi2 = (st2 + en2) / 2;
			if (Vu[1][mi2].first >= t) {
				rv2 = mi2;
				en2 = mi2 - 1;
			}
			else st2 = mi2 + 1;
		}

		ll u1 = Vsum[1].back().first;
		if (rv2) u1 -= Vsum[1][rv2 - 1].first;
		ll u2 = Vsum[1].back().second;
		if (rv2) u2 -= Vsum[1][rv2 - 1].second;
		c1 += u1 * Vu[0][i].second, c2 += u2 * Vu[0][i].first * Vu[0][i].second;
	}
	return pll(c1, c2);
}
int main() {
	int N, M, R, K, i, j;
	scanf("%d %d %d %d", &N, &M, &R, &K);

	aa(Vu[0], Vsum[0], N, R);
	aa(Vu[1], Vsum[1], M, R);

	ll st = 1, en = 0x3f3f3f3f3f3f3f3f, mi, rv = 0;
	pll val;
	while (st <= en) {
		mi = (st + en) / 2;

		pll u = getv(mi);
		if (u.first >= K) {
			rv = mi;
			st = mi + 1;
			val = u;
		}
		else en = mi - 1;
	}

	db sum = val.second - (val.first - K) * rv;
	sum /= (N - R + 1);
	sum /= (M - R + 1);
	return !printf("%.20lf\n", sum);
}
