#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef map<ll,ll> mll;

mll occur;

int main() {
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    ll answer = 0;
    if(2r-2 < n && 2r-2 < m) {
        int tempn = n-(2r-2);
        int tempm = m-(2r-2);
        if(k <= tempn*tempm) {
            answer += k*r*r;
            print(answer,n,m,r);
        }
        else {
            answer += tempm*tempn*r*r;
            k -= temp*tempn;
        }
    }
    for(int dis = 1; 
}
