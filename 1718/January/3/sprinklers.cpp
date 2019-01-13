#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()


const int MOD = 1000000007;

const int SZ = 1<<17;

template<class T> struct node {
    T val;
    node<T>* c[2];
    
    node() {
        val = 0;
        c[0] = c[1] = NULL;    
    }
    
    void upd(int ind, T v, int L = 0, int R = SZ-1) { // add v
        if (L == ind && R == ind && val == 0) { val += v; return; }
        
        int M = (L+R)/2;
        if (ind <= M) {
            if (!c[0]) c[0] = new node();
            c[0]->upd(ind,v,L,M);
        } else {
            if (!c[1]) c[1] = new node();
            c[1]->upd(ind,v,M+1,R);
        }
        
        val = 0;
        if (c[0]) val += c[0]->val;
        if (c[1]) val += c[1]->val;
    }
    
    T query(int low, int high, int L = 0, int R = SZ-1) { // query sum of segment
        if (low <= L && R <= high) return val;
        if (high < L || R < low) return 0;
        
        int M = (L+R)/2;
        T t = 0;
        if (c[0]) t += c[0]->query(low,high,L,M);
        if (c[1]) t += c[1]->query(low,high,M+1,R);
        return t;
    }
    
    void UPD(int ind, node* c0, node* c1, int L = 0, int R = SZ-1) { // for 2D segtree
        if (L != R) {
            int M = (L+R)/2;
            if (ind <= M) {
                if (!c[0]) c[0] = new node();
                c[0]->UPD(ind,c0 ? c0->c[0] : NULL,c1 ? c1->c[0] : NULL,L,M);
            } else {
                if (!c[1]) c[1] = new node();
                c[1]->UPD(ind,c0 ? c0->c[1] : NULL,c1 ? c1->c[1] : NULL,M+1,R);
            }
        } 
        val = 0;
        if (c0) val += c0->val;
        if (c1) val += c1->val;
    }
};

template<class T> struct Node {
    node<T> seg;
    Node* c[2];
    
    void upd(int x, int y, T v, int L = 0, int R = SZ-1) { // add v
        if (L == x && R == x) {
            seg.upd(y,v);
            return;
        }
        
        int M = (L+R)/2;
        if (x <= M) {
            if (!c[0]) c[0] = new Node();
            c[0]->upd(x,y,v,L,M);
        } else {
            if (!c[1]) c[1] = new Node();
            c[1]->upd(x,y,v,M+1,R);
        }
        
        seg.UPD(y,c[0] ? &c[0]->seg : NULL,c[1] ? &c[1]->seg : NULL);
    }
    
    T query(int x1, int x2, int y1, int y2, int L = 0, int R = SZ-1) { // query sum of rectangle
        if (x1 <= L && R <= x2) return seg.query(y1,y2);
        if (x2 < L || R < x1) return 0;
        
        int M = (L+R)/2;
        T t = 0;
        if (c[0]) t += c[0]->query(x1,x2,y1,y2,L,M);
        if (c[1]) t += c[1]->query(x1,x2,y1,y2,M+1,R);
        return t;
    }
};

int main() {
    freopen("sprinklers.in","r",stdin);
    freopen("sprinklers.out","w",stdout);
    int N;
    cin >> N;
    F0R(i,N) {
        int a,b;
        cin >> a >> b;
		sprinklerX[a] = b;
		sprinklerY[b] = a;
    }
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < N-1; j++) {
			for(int ii = i+1; ii < N-1; ii++) {
				for(int jj = j+1; jj < N-1; jj++) {
					
				}
			}
		}
	}

}

// read!read!read!read!read!read!read!
// ll vs. int!
