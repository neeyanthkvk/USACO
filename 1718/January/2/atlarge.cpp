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
vi graph[71000];
int dis[71000];
int dir[71000];
set<int> visited;
vi leaf;
set<int> leafset;
int n;
queue<pii> qu;

inline void dfs(int curr) {
    int depth = dis[curr];
    vi children = graph[curr];
    for(int child:children) {
        if(visited.find(child) == visited.end()) {
            dir[child] = curr;         
            dis[child] = depth + 1;
            visited.insert(child);
            dfs(child);
        }
    }
}

set<int> visitedn;

int main() {
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    cin >> n;
    F0R(i,n-1) {
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a-1].pb(b-1);
        graph[b-1].pb(a-1);
    }
    F0R(i,n) {
        if(graph[i].size() == 1) {
            leaf.pb(i);
			leafset.insert(i);
        }
    }
    F0R(i,n) {
        if(leafset.find(i) != leafset.end()) {
            cout << 1 << endl;
            continue;
        }
        visitedn.clear();
        visited.clear();
        visited.insert(i);
        dis[i] = 0;
        dfs(i);
        // First is current, Second is original leaf
        F0R(j,leaf.size()) {
            qu.push(mp(leaf[j],leaf[j]));
        }
        int ans = leaf.size();
        while(!qu.empty()) {
            pii temp = qu.front();
            qu.pop();
            int cur = temp.f;
            int le = temp.s;
            int rootdis = dis[cur];
            int leafdis = dis[le]-dis[cur];
            if(visitedn.find(cur) != visitedn.end()) {
                ans -= 1;
				if(ans == 1) break;
				continue;
            }
            else {
                if(rootdis > leafdis) {
                    visitedn.insert(cur);                        
                    int next = dir[cur];
                    qu.push(mp(next,le));
                }
                else if(rootdis == leafdis) {
                    visitedn.insert(cur);
                    continue;
                }
				else {
                    continue;
                }
            }
        }
        printf("%d\n", ans);
    }
}
