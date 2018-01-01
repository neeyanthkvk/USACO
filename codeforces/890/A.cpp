#include <bits/stdc++.h>

using namespace std;

vector<int> ints(6);

int main() {
    cin >> ints[0] >> ints[1] >> ints[2] >> ints[3] >> ints[4] >> ints[5];
    sort(ints.begin(), ints.end());
    int sum = ints[0] + ints[1] + ints[2] + ints[3] + ints[4] + ints[5];
    if(sum % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    sum = sum/2;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                if(ints[i] + ints[j] + ints[k] == sum) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }   
    }
    cout << "NO" << endl;
}
