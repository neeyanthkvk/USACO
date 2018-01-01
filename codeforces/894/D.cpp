#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000100;
vector<int> v[maxn];
vector<int> p[maxn];
int l[maxn];
int n;

int cal(int x,int h){
    if(x > n) return 0;
    if(h < 0) return 0;
    int ind = upper_bound(v[x].begin(), v[x].end(),h)-v[x].begin();
    //for2(i,0,ind) cout << v[x][i] << ' ';
    return h*ind-p[x][ind];
}

main(){
    int m; cin >> n >> m;
	for(int i = 2; i < 1+n; i++) {
		cin >> l[i];
	}
    for(int i = 1; i < n+1; i++){
        int x = i;
        int cur = 0;
        while(x){
            v[x].push_back(cur);
            cur += l[x];
            x /= 2;
        }
    }
    for(int i = 1; i < 1+n; i++){
        p[i].push_back(0);
        sort(v[i].begin(), v[i].end());
        int last = 0;
        for(auto x : v[i]){
            last += x;
            p[i].push_back(last);
        }
    }
    for(int i = 0;i < m; i++){
        int ans = 0;
        int x,h; cin >> x >> h;
        ans += cal(x,h);
        while(x > 1){
            h -= l[x];
            if(h < 0) break;
            ans += h;
            if(x%2) ans += cal(x-1,h-l[x-1]);
            else    ans +=cal(x+1,h-l[x+1]);
            x /= 2;
        }
        cout << ans << endl;
    }
}
