#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

struct State {
    int curr;
    int character;
    int depth;
};

const int MOD = 1000000007;
vi graph[1000];
int ch[1000][1000];
int maxdis[1000];

int dfs(int source) {
    State t = {source,-1,0};
    int maxdepth = -1;
    queue<State> q;
    q.push(t);
    while(q.size() != 0) {
        State x = q.front();
        int d = x.depth;
        int charac = x.character;
        int curr = x.curr;
        q.pop();
        cout << d << charac << curr << endl;
        maxdepth = maxdepth>d?maxdepth:d;
        vi children = graph[curr];
        for(int c:children) {
            int xx = ch[curr][c];
            cout << xx << endl;
            if(xx <= charac) continue;
            int newd = d + 1;
            State temp = {c,xx,newd};
            q.push(temp);
        }
    }
    return maxdepth;
}

int main() {
    int n,m;
    cin >> n >> m;
    F0R(i,m) {
        int a,b;
        cin >> a >> b;
        graph[a-1].pb(b-1);
        char t;
        cin >> t;
        cout << "CHARACTER: " << t << " " ;
        int tt = (int) ( t - 'a' );
        cout << tt << endl;
        ch[a][b] = tt;
    }
    F0R(i,1) {
        maxdis[i] = dfs(i);
    }
    F0R(i,n) {
        F0R(j,n) {
            if(maxdis[i] > maxdis[j]) cout << 'A';
            else cout << 'B';
        }
        cout << endl;
    }
}


