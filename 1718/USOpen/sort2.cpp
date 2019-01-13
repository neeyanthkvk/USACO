#include <bits/stdc++.h>

using namespace std;
#define tab "\t"
set<int> arr2;
int ordered[100000];
map<int,int> comp;
map<int,int> mults;
int N;

template<int SZ> struct BIT {
    int bit[SZ+1];
    BIT() { memset(bit,0,sizeof bit); }
    
    void upd(int k, int val) { // add val to index k
        for( ;k <= SZ; k += (k&-k)) bit[k] += val;
    }
    
    int query(int k) {
        int temp = 0;
        for (;k > 0;k -= (k&-k)) temp += bit[k];
        return temp;
    }
    int query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};
BIT<2 << 17> bit;
int mo[100000];
int le[100000];
int mo2[100000];
int le2[100000];
int main() {
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin >> N;
	int answer = N*(N+1)/2;
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		ordered[i] = a;
		arr2.insert(a);
	}
	int a = 1;
	for(set<int>::iterator iter = arr2.begin(); iter != arr2.end(); iter++) {
		comp[*iter] = a;
		a++;
	}
	for(int i = 0; i < N; i++) {
		int curr = ordered[i];
		if(mults.find(curr) == mults.end()) mults[curr] = 0;
		mults[curr]++;
		bit.upd(comp[curr],1);
		int less = bit.query(comp[curr]);
		mo[i] = i - (less-1);
		le[i] = less-1 - (mults[curr]-1);
	}
	multiset<int> rm;
	for(int i = 0; i < N; i++) {
		int curr = ordered[i];
		int nowless = bit.query(comp[curr]);
		mo2[i] = N-nowless;
		le2[i] = nowless - 1 - (mults[curr]-1);
		//cout << mo[i] << tab << le[i] << tab << mo2[i] << tab << le2[i] << endl;
		if(le2[i] == le[i]) {
			rm.insert(i);
		}
	}
	for(int i = N-1; i >= 0; i--) {
		if(le2[i] > mo2[i]) {
			rm.insert(mo2[i]);
		}else break;
	}
	int dup = 0;
	int prev = -1;
	for(int rem:rm) {
		if(rem <= prev) {
			prev ++;
		}
		else {
			prev = rem;
		}
		answer -= (N-prev);
	}
	cout << (answer<=0?N:answer) << endl;
	return 0;
}
