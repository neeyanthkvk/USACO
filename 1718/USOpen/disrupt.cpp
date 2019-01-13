#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int N,M;
vector<int> graph[50000];
int par[50000];
pii edges[50000];
int depth[50000];
vector<pair<int,pii> > cons;
map<int,set<pair<int,pii> > > conmap;
int anc[100000][17];

int lca(int a, int b) {
	if(a == b) return a;
    if (depth[a] < depth[b]) swap(a,b);
    for(int i = 16; i >= 0; i--) if ((depth[a]-depth[b])&(1<<i)) a = anc[a][i];
    if (a == b) return a;
    for(int i = 16; i >= 0; i--) if (anc[a][i] != anc[b][i]) {
        a = anc[a][i];
        b = anc[b][i];
    }
    return anc[a][0];
}

void dfs(int cur, int p, int d) {
	depth[cur] = d;
	par[cur] = p;
	anc[0][0] = 0;
	anc[cur][0] = p;
	for(int i = 1; i < 17; i++) {
		anc[cur][i] = anc[anc[cur][i-1]][i-1];
	}
	for(int child:graph[cur]) {
		if(child == p) continue;
		dfs(child, cur, d+1);
	}
}

int main() {
	freopen("disrupt.in","r",stdin);
	freopen("disrupt.out","w",stdout);
	cin >> N >> M;
	for(int i = 0; i < N-1; i++) {
		int a,b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		edges[i] = make_pair(a-1,b-1);
	}
	dfs(0,-1,0);
	for(int i = 0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		pair<int, pii> > con = make_pair(c,make_pair(a,b))
		cons.push_back(con);
		if(conmap.find(a) == conmap.end()) {
			set<pair<int,pii> > l;
			conmap[a] = l;
		}
		conmap[a].insert(con);
		if(conmap.find(b) == conmap.end()) {
			set<pair<int, pii> > l;
			conmap[b] = l;
		}
		conmap[b].insert(con);
	}
	for(int i= 0; i < N-1; i++) {
		int s = edges[i].first;
		int e = edges[i].second;
		int dis = depth[s] > depth[e]? s:e;
		bool flag = 0;
		int curr = dis;
		while(true) {
			
			if(lca(b,dis) == dis && lca(a,dis) != dis && a != dis) {
				cout << w << "\n";
				flag = 1;
				break;
			}
			if(lca(a,dis) == dis && lca(b,dis) != dis && b != dis) {
				cout << w << "\n";
				flag = 1;
				break;
			}
		}
		if(!flag) cout << -1 << "\n";
	}	
}
