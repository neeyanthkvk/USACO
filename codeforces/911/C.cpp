#include <bits/stdc++.h>

using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    if(1/a + 1/b == 1 || 1/a + 1/c == 1 || 1/b + 1/c == 1 || a == 1 || b == 1 || c == 1) {
        cout << "YES" << endl;
        return 0;
    }
    if(a == 3 && b == 3 && c == 3) {
        cout << "YES" << endl;
        return 0;
    }
    if(a == 2 && b == c && b == 4) {
        cout << "YES" << endl;
		return 0;
    }
	if(b == 2 && a == c && a == 4) {
        cout << "YES" << endl;
		return 0;
    }
	if(c == 2 && a == b && b == 4) {
        cout << "YES" << endl;
		return 0;
    }
    cout << "NO" << endl;
}
