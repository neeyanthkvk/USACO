#include <bits/stdc++.h>
using namespace std;
long double ex[100000];
long f[100002];




int main() {
//    freopen("balance.in","r",stdin);
//    freopen("balance.out","w",stdout);
    int N;
    cin >> N;
    f[0] = 0;
    for(int i = 0; i < N; i++) {
        cin >> f[i+1];
    }
    f[N+1] = 0;
    int curIndex = -1;
    for(int i = 1; i < N+1; i++) {
        long double curMax = f[i] * 100000;
        int fir = -1;
        int sec = -1;
        for(int j = i+1; j < N+2; j++) {
            for(int k = 0; k < i; k++) {
                long double newexp = ((j-i)*100000*f[k] + 100000 *(i-k)*f[j])/(j-k);
                if(curMax < newexp) {
                    fir = k;
                    sec = j;
                    curMax = newexp;
                }
            }
        }
        ex[i] = curMax;
        cout << fir << "\t" << sec << "\t" << (long long) curMax << endl;
    }
    for(int i = 1; i < N+1; i++) {
        //cout << (long long) ex[i] << endl;
    }
}
