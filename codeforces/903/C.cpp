#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr;
map<ll, int> occurences;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
        occurences[temp] += 1;
    }
    int ans = 0;
    for(map<ll, int>::iterator itr = occurences.begin(); itr != occurences.end(); ++itr) {
        int l = itr-> second;
        ans = ans > l?ans:l;
    }
    cout << ans;

}
