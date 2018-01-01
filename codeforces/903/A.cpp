#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x > 11) {
            cout << "YES" << endl;
            continue;
        }
        if(x % 3 == 0 ||((x-7) % 3 == 0 && x >= 7)) {
            cout << "YES" << endl;
            continue; 
        }
        cout << "NO" << endl;

    }
}
