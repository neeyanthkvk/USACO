#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int main() {
    int m;
    cin >> m;
    int x;
    cin >> x;
    for(int i = 1; i < m; i++) {
        cin >> arr[i];
        if(arr[i] % x != 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    if(m == 1) {
        cout << 1 << endl << x << endl;
        return 0;
    }
    cout << 2*(m-1) << endl;
    for(int i = 1; i < m; i++) {
        cout << x <<" " << arr[i] <<" ";
    }
    cout << endl;
}
