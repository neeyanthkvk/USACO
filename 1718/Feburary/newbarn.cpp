#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vi graph[100000];

const int MOD = 1000000007;
int currBarns = 0;

int d[100000];

int query(int start) {
    memset(d,-1,sizeof(int) * currBarns);
    queue<int> q;
    int ans = 0;
    d[start] = 0;
    q.push(start);
    while(q.size() != 0) {
        int currIndex = q.front();
        int dis = d[currIndex];
        q.pop();
        ans = ans>dis?ans:dis;
        vi children = graph[currIndex];
        for(int i = 0; i < children.size(); i++) {
            int child = children[i];
            if(d[child] != -1) continue;
            q.push(child);
            d[child] = dis + 1;
        }
    }
    return ans;
}


int main() {
    freopen("newbarn.in","r",stdin);
    freopen("newbarn.out","w",stdout);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        char c;
        int a;
        cin >> c >> a;
        if(c == 'B') {
            if(a != -1) {
                a -= 1;
                graph[a].push_back(currBarns);
                graph[currBarns].push_back(a);
            }
            currBarns++;
        }
        else {
            int ans = query(a-1);
            cout << ans << "\n";
        }

    }
    return 0;
}

// read!read!read!read!read!read!read!
// ll vs. int!
