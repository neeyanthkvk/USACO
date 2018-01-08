#include <bits/stdc++.h>

using namespace std;
int steps[1000];
int main() {
    int n, d;
    cin >> n >> d;
    string temp;
    cin >> temp;
    const char* arr = temp.c_str();
    
    steps[0] = 1;
    int latestReached = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == '1') {
            for(int j = 0; j <= min(i,d); j++) {
               if( 
            }
        }
    }
}
