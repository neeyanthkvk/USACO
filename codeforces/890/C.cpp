#include <bits/stdc++.h>

using namespace std;

int arr[200000];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[temp] = 1;
    }
    int temp = 0;
    for(int i= 0; i <= n; i++) {
        if(!arr[i]) {
            temp += 1;
        }   
    }
    cout << temp;
}
