#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

map<ll,ll> occur;

int main() {
    int m, n;
    cin >> n >> m;
    int r;
    ll totalAns = (ll) r * (ll) r;
    cin >> r;
    int b = r-1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int firstdis = min(i,m-1-i);
            int secondis = min(j,n-1-j);
            ll answer = 0;
            if(firstdis >= b && secondis >= b) {
                answer = totalAns;
            }
            else if(firstdis >= b) {
                answer = r * (secondis+1);
            }
            else if(secondis >= b) {
                answer = r * (firstdis + 1);
            }
            else {
                answer = (firstdis+1) * (secondis + 1);
            }
            if(occur.find(answer) == occur.end()) {
                
            }
        }
    }
    
}
