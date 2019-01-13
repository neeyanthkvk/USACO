#include <bits/stdc++.h>
using namespace std;

char arr[2000][2000];

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    for(int i = 0; i < a; i++) {
        scanf("%s", arr[i]);
    }
    int ans = 0;
    for(int i = 0; i < a; i++) {
        int s = 0;
        for(int j = 0; j < b; j++) {
            if(arr[i][j] == '.') {
                s++;
                if(s >= c) ans++;
            }       
            else { 
                s = 0;
            }
        }
    }
    if(c != 1) 
    for(int j = 0; j < b; j++) {
        int s = 0;
        for(int i = 0; i < a; i++) {
            if(arr[i][j] == '.') {
                s++;
                if(s >= c) ans++;
            }
            else {
                s = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
