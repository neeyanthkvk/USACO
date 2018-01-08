#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int logbase(ll temp) {
    int ans = 0;
    ll curr = 1;
    while(curr < temp) {
        ans += 1;
        curr *= 2;
    }
    if(temp == curr)
    return ans;
    return ans-1;
}

int main() {
    ll n,k;
    cin >> n >> k;
    int temp = logbase(n);
    ll x = 1;
    for(int i = 0; i < temp; i++) {
        x *= 2;
    }
    x = x*2 - 1;
    if(k != 1)
        cout << x << endl;
    else 
        cout << n << endl;
}
