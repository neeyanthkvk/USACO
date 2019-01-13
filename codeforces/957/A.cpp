#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    char arr[N];
    cin >> arr;
    bool flag = false;
    for(int i = 0; i < N; i++) {
        char temp = arr[i];
        if(temp == '?' && i == 0) flag = true;
        if(i == 0) continue;
        if(arr[i] == arr[i-1] && arr[i] != '?') {cout << "No" << endl; return 0;}
        if(temp == '?' && i == N-1) flag = true;
        if(temp == '?' && (arr[i-1] == '?' || arr[i+1] == '?')) flag = true;
        if(temp == '?' && (arr[i-1] == arr[i+1])) flag = true;
    }
    cout << (flag?"Yes":"No") << endl;
}
