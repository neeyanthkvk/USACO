#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll a, b, dig;
    cin >> a >> b >> dig;
    int place = 0;
    while(true) {
        place += 1;
        ll temp = a*10;
        ll dig2 = (temp)/((ll) b);
        ll rem = (temp) % ((ll) (b));
        if(dig2 == dig) {
            cout << place;
            return 0;
        }
        a = rem;
        if(place == 1000000) {
            cout << -1 << endl;
            return 0;
        }
    }
}
