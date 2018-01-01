#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int n,d;

template<class T, int SZ> struct LazySegTree {
    T mx[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (mx,0,sizeof mx);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        mx[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        mx[ind] = max(mx[2*ind],mx[2*ind+1]);
    }
    
    void build() {
        for(int i = SZ-1; i >= 0; i--) pull(i);
    }
    
    T qmax(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return -1e18;
        if (lo <= L && R <= hi) return mx[ind];
        
        int M = (L+R)/2;
        return max(qmax(lo,hi,2*ind,L,M),qmax(lo,hi,2*ind+1,M+1,R));
    }
    
    void upd(int lo, int hi, long long inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<long long,1<<17> L;

int lst = 0;
long long ans = 0;
int a[100000];

int main() {
	cin >> n >> d;
	for(int i = 0;i < n; i++) {
	    cin >> a[i]; lst += a[i];
	    L.upd(i,i,lst);
	}
	for(int i = 0; i < n; i++) {
	    if (L.qmax(i,i) > d) {
	        cout << -1;
	        return 0;
	    }
	    if (a[i] == 0) {
	        long long mx = L.qmax(i,n-1);
	        if (mx > d) {
	            cout << -1;
	            return 0;
	        }
	        if (L.qmax(i,i) < 0) {
	            long long z = d-mx;
	            L.upd(i,n-1,z); ans++;
	            if (L.qmax(i,i) < 0) {
	                cout << -1;
	                return 0;
	            }
	        }
	    }
	}
	cout << ans;
}
