#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<pair<int, pii> > tract;
const int MOD = 1000000007;
int N,M;
int main() {
    freopen("slingshot.in","r",stdin);
    freopen("slingshot.out","w",stdout);
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        tract.push_back(make_pair(a,make_pair(b,c)));
    }
    for(int i = 0; i < M; i++) {
        int x,y;
        scanf("%d %d", &x,&y);
        int min = abs(x-y);
        for(int j = 0; j < N; j++) {
            pair<int, pii> curr = tract[j];
            int currdis = abs(curr.first-x) + curr.second.second + abs(curr.second.first-y);
            min = min > currdis?currdis:min;
        }
        cout << min << "\n";
    }
    return 0;

}

// read!read!read!read!read!read!read!
// ll vs. int!
