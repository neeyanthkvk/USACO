#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SIZE(a) ((int)(a).size())

int n, m;

void check(int n, int m) {

}

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};

int check(vector<vector<int>> result) {
	vector<vector<int>> a(n, vector<int> (m));
	int cur = 0;
	REP(i, n) REP(j, m) a[i][j] = cur++;
	vector<int> all;
	REP(i, n) REP(j, m) all.push_back(result[i][j]);
	sort(all.begin(), all.end());
	REP(i, SIZE(all)) if (all[i] != i) return 0;
	set<pair<int,int>> banned;
	REP(i, n) REP(j, m) {
		REP(iter, 4) {
			int x = i + dx[iter], y = j + dy[iter];
			if (x >= 0 && x < n && y >= 0 && y < m) banned.insert({a[i][j], a[x][y]});
		}
	}
	REP(i, n) REP(j, m) {
		REP(iter, 4) {
			int x = i + dx[iter], y = j + dy[iter];
			if (x >= 0 && x < n && y >= 0 && y < m && banned.count({result[i][j], result[x][y]})) {
				return 0;
			}
		}
	}
	return 1;
}

void output(vector<vector<int>> result) {
	if (!check(result)) {
		cerr << "DUPA" << endl;
		exit(-1);
	}
	cout << "YES\n";
	REP(i, n) {
		REP(j, m) cout << result[i][j]+1 << ' ';
		cout << '\n';
	}
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (m));
	int cur = 0;
	REP(i, n) REP(j, m) a[i][j] = cur++;

	if (m > 4) {
		vector<int> b[2];
		REP(i, n) {
			b[0].clear(); b[1].clear();
			REP(j, m) b[j%2].push_back(a[i][j]);
			if (i%2) b[0].swap(b[1]);
			b[0].insert(b[0].end(), b[1].begin(), b[1].end());
			REP(j, m) a[i][j] = b[0][j];
		}
		output(a);
	}

	if (n > 4) {
		vector<int> b[2];
		REP(j, m) {
			b[0].clear(); b[1].clear();
			REP(i, n) b[i%2].push_back(a[i][j]);
			if (j%2) b[0].swap(b[1]);
			b[0].insert(b[0].end(), b[1].begin(), b[1].end());
			REP(i, n) a[i][j] = b[0][i];
		}
		output(a);
	}

	if (n == 4 && m == 4) {
		vector<vector<int>> out = {
			{4, 3, 6, 1}, 
			{2, 5, 0, 7},
			{12, 11, 14, 9},
			{10, 13, 8, 15}
		};
		output(out);
	}

	if (n == 3 && m == 4) {
		vector<vector<int>> out = {
			{0, 2, 4, 1}, 
			{3, 5, 11, 8},
			{10, 7, 9, 6},
		};
		output(out);
	}

	if (n == 4 && m == 3) {
		vector<vector<int>> out = {
			{0, 2, 3},
			{4, 6, 1}, 
			{10, 5, 7},
			{8, 9, 11}
		};
		output(out);
	}

	vector<int> p(n*m);
	REP(i, n*m) p[i] = i;
	do {
		REP(i, n) REP(j, m) a[i][j] = p[i*m+j];
		if (check(a)) output(a);
	} while (next_permutation(p.begin(), p.end()));

	cout << "NO\n";

	return 0;
}
