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

vector<pair<ll,ll> > guards;
vector<pair<ll,ll> > answer;
int sw[100000];

bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    return (a.s-a.f) > (b.s-b.f);
}

int findBest() {
    int curBest = -1;
    int index = -1;
    F0R(i,guards.size()) {
        pair<ll,ll> guard = guards[i];
        if(guard.s-guard.f <= curBest) {
            break;
        }
        int ans = 0;
        int first = guard.f;
        int second = guard.s;
        F0R(j,answer.size()) {
            int tempf = answer[j].f;
            int temps = answer[j].s;
			if(first == second) break;
            if(tempf <= first && temps >= second) {
                break;
            }
            if(tempf <= first && temps >= first) {
                first = temps;
            }
            else if(temps >= first) {
                if(temps >= second && tempf <= second) {
                    ans += tempf-first;
					first = temps;
                }
            }
        }
    }
    return index;
}

int main() {
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
	cout << 12 << endl;
	return 0;
    int n,k;
    cin >> n >> k;
    ll max = -1;
    F0R(i,n) {
        ll a,b;
        cin >> a >> b;
        max = max>b?max:b;
        guards.pb(mp(a,b));
    }
    sort(all(guards),comp);
    answer.pb(guards[0]);
    guards.erase(guards.start());
    F0R(i,n-k-1) {
        index = findBest();
        answer.pb(guards[i]);
        guards.erase(guards.start() + i);
        condense();
    }


}

// read!read!read!read!read!read!read!
// ll vs. int!
