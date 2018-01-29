#include <bits/stdc++.h>

using namespace std;
#define t "\t"
bool check(int a, int b) {
    int a1 = a % 10;
    int a2 = a/10;
    a1 = a-10*a2;
    int b1 = b & 10;
    int b2 = b/10;
    b1 = b-10*b2;
    return a1 == 7 || b1 == 7 || a2 == 7 || b2 == 7;
}

int main() {
    int x,h,m;
    cin >> x >> h >> m;

    int answer = 0;
    while(!check(h,m)) {
        answer += 1;
        m -= x;
        if(m < 0) {
            h -= 1;
            m += 60;
            if(h < 0) {
                h += 24;
            }
        }
    }
    cout << answer << endl;
}
