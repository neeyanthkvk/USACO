#include <bits/stdc++.h>
using namespace std;

int f[100002];
vector<int> stop;


int binSearch(int n) {
/*    int l = 0;
    int r = stop.size()-1;
    int m = (l+r)/2;
    while(!(stop[m] <= n && stop[m+1] >= n)) {
        if(stop[m] < n) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return m;
*/
    for(int i = 0; i < stop.size(); i++) {
        if(stop[i] > n) {
            return i-1;
        }       
    }
}
    

int main() {
    freopen("balance.in","r",stdin);
    freopen("balance.out","w",stdout);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> f[i+1];
    }
    f[0] = 0;
    f[N+1] = 0;
    stop.push_back(0);
    for(int i = 1; i < N+1; i++) {
        if(2*f[i] > f[i-1] + f[i+1]) {
            stop.push_back(i);
        }
    }
    stop.push_back(N+1);
    for(int i = 1; i < N+1; i++) {
        int p = binSearch(i);
        int lo = stop[p];
        int hi = stop[p+1];
        double prob1 = (hi-i+0.0)/(hi-lo+0.0);
        double prob2 = 1-prob1;
        int valu = 100000*(prob1*f[lo] + prob2 * f[hi]);
        cout << valu << endl;
    }
}
