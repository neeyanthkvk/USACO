#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int,int> res[10000000];

int main() {
    ll n, x, k;
    cin >> n >> x >> k ;
    ll answer = 0;
    ll maxRes = 0;
    for(int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        ll residue = temp / x;
        if(residue > maxRes) {
            maxRes = residue;
        }
        if(temp % x == 0) {
            res[residue].second += 1;
        }
        else {
            res[residue].first += 1;
        }
    }

    for(ll i = 0; i < maxRes+1; i++) {
        if(k != 0) {
            ll a = res[i].first;
            ll b = res[i].second;
			ll c = 0, d = 0;
			if(i+k-1 < 10000000) {
				c = res[i+k-1].first + res[i+k-1].second;
			}
			if(i + k < 10000000) {
				d = res[i+k].first + res[i+k].second;
			}
            answer += b*c + a*d;
        }
        else {
            ll a = res[i].first;
            answer += a*a;
        }
    }
    cout << answer << endl;
}
