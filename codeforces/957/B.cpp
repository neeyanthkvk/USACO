#include <bits/stdc++.h>
using namespace std;

bool arr[50][50];
bool check[50];
int main() {
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c;
            cin >> c;
            arr[i][j] = (c == '#');
        }
    }

    for(int i = 0; i < N;  i++) {
        for(int j = 0; j < M; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }   
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            int x = 0;
            for(int k = 0; k < M; k++) {
                if(arr[i][k] == arr[j][k]) {
                    x = (x == 0 || x == 1)? 1 : -1;
                }
                else {
                    x = (x == 0)?0 : -1;
                }
            }
            if(x == -1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
