#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[200001];
map<ll, int> occur;
int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for(int j = 0; j < n; j++) {
        cin >> arr[j];
        occur[arr[j]] += 1;
        ll a = arr[j];
        for(map<ll, int>::iterator iter = occur.begin(); iter != occur.end(); ++iter) {
            ll b = iter->first;
            int c = iter->second;
            if(b - a == 0 || b-a == 1 || b-a == -1) {
                continue;
            }
            else {
                ans += c*(a-b);
            }
        }
    }
    cout << ans;
}
