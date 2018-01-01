#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define ll long long
#define for2(a,b,c) for(int (a) = (b); (a) < (c); (a)++)
#define setp cout << fixed << setprecision(7)
#define endl "\n"
#define minit(a,b) a = min(a,b)
#define maxit(a,b) a = max(a,b)
#define PII pair<int,int>
#define Vec vector<int>
#define error(x) cerr << #x << " = " << (x) << endl;
#define all(x) (x).begin() , (x).end()

const int maxn = 1000100;
vector<int> v[maxn];
vector<int> p[maxn];
int l[maxn];
int n;

int cal(int x,int h){
    if(x > n) return 0;
    if(h < 0) return 0;
    int ind = upper_bound(all(v[x]),h)-v[x].begin();
    //for2(i,0,ind) cout << v[x][i] << ' ';
    return h*ind-p[x][ind];
}

main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m; cin >> n >> m;
    for2(i,1+1,1+n) cin >> l[i];
    for2(i,1,n+1){
        int x = i;
        int cur = 0;
        while(x){
            v[x].pb(cur);
            cur += l[x];
            x /= 2;
        }
    }
    for2(i,1,1+n){
        p[i].pb(0);
        sort(all(v[i]));
        int last = 0; 
        for(auto x : v[i]){
            last += x;
            p[i].pb(last);
        }
    }
    for2(i,0,m){
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