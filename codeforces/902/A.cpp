#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int maxRN = 0;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        if(a <= maxRN) {
            maxRN = maxRN > b?maxRN:b;
            if(maxRN == m) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}
