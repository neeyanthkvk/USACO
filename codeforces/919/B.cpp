#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int N) {
    int sum = 0;
    int curr = N;
    while(true) {
        if(curr < 10) {
            sum += curr;
            break;
        }
        sum += (curr) % 10;
        curr /= 10;
    }
    return sum == 10;
}

int main() {
    int a;
    cin >> a;
    int num = 0;
    for(int i = 0; i < 100000000; i++) {
        if(isPerfect(i)) {
            num += 1;
            if(num == a) {
                cout << i << endl;
                return 0;
            }
        }
    }
}
