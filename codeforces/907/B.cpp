#include <bits/stdc++.h>

using namespace std;

int main() {
	string grid[3][3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> grid[i][k][j];
			}
		}
	}

	int a, b;
	cin >> a >> b;

	int gi = (a-1)%3;
	int gj = (b-1)%3;

	bool shit = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[gi][gj][i][j] == '.')
				shit = false;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (shit || i == gi && k == gj) {
					for (int l = 0; l < 3; l++) {
						if (grid[i][k][j][l] == '.')
							cout << "!";
						else
							cout << grid[i][k][j][l];
					}
					cout << " ";
				} else {
					cout << grid[i][k][j] << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}