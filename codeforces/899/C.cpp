#include <bits/stdc++.h>

using namespace std;
int arr[60000];
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        arr[i] = i+1;
    }

    vector<int> first, second;
    int a = 0, b = 0;
    sort(arr, arr+N);
    for(int i = N-1; i >= 0; i--) {
        int num = arr[i];
        if(a > b) {
            b += num;
            second.push_back(num);
        }
        else {
            a += num;
            first.push_back(num);
        }
    }
    cout << (a > b? a-b:b-a) << endl;
    cout << first.size();
    for(int i = 0; i < first.size(); i++) {
        cout << " " << first[i];
    }
    cout << endl;
}
