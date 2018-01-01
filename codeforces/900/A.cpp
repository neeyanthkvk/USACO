#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int countB = 0;
    int countA = 0;
    for(int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        if(x < 0) {
            countA += 1;
        }
        else {
            countB += 1;
        }
    }
    if(countA >= 2 && countB >= 2) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
