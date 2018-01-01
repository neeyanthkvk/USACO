#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < i; k++) {
				if (a <= i and i <= 2*a and b <= j and j <= 2*b and c <= k and k <= 2*c
						and d <= k and k <= 2*d and j > 2*d) {
					cout << i << endl;
					cout << j << endl;
					cout << k << endl;
					return 0;
				}
			}
		}
	}

	cout << -1 << endl;

	return 0;
}
