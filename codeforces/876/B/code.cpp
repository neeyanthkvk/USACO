#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> remainders[m];
    for(int i = 0; i < m; i++) {
        vector<int> temp;
        remainders[i] = temp;
    }
    int modulus = -1;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        remainders[temp%m].push_back(temp);
        if(remainders[temp%m].size() == k) {
            modulus = temp%m;
            break;
        }
    }
    if(modulus == -1) {
        cout << "No";
    }
    else {
        cout << "Yes" << endl;
        for(int i : remainders[modulus]) {
            cout << i << " ";
        }
    }
    cout << endl;
}
