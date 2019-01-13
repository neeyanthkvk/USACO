#include <bits/stdc++.h>
using namespace std;
#define tab "\t"
long double ex[100000];
long f[100002];

//#define DEBUG

int main() {
    freopen("balance.in","r",stdin);
    freopen("balance.out","w",stdout);
    int N;
    cin >> N;
    f[0] = 0;
    for(int i = 0; i < N; i++) {
        cin >> f[i+1];
    }
    f[N+1] = 0;
    int firIndex = 0;
    int curIndex = 1;
    // For the First one to setup indicies
    long double tempMax = f[1] * 100000;
    for(int i = 2; i < N+2; i++) {
        long double newexp = ((i-1)*ex[0] + 100000 * f[i])/(i);
		if(tempMax < newexp) {
			tempMax = newexp;
			curIndex = i;
		}
    }


    for(int i = 1; i < N+1; i++) {
        long double curMax = f[i] * 100000;
        if(i == curIndex) {
            ex[i] = curMax;
        }   
        else if(i < curIndex) {
            ex[i] = ((curIndex-i)*f[firIndex]*100000 + 100000*(i-firIndex)*f[curIndex])/(curIndex-firIndex);
        }
        else {
            int tindex = -1;
            for(int j = i+1; j < N+2; j++) {
                long double newexp = ((j-i)*f[curIndex]*100000 + 100000 * (i-curIndex) * f[j])/(j-curIndex);
                if(curMax < newexp) {
                    curMax = newexp;
                    tindex = j;
                }
            }
            firIndex = curIndex;
            if(tindex == -1) tindex = i;
            curIndex = tindex;
            ex[i] = curMax;
        }
#ifdef DEBUG
        cout << firIndex << tab << curIndex << tab << (long long) ex[i] << endl;
#endif
    }
    for(int i = 1; i < N+1; i++) {
        cout << (long long) ex[i] << endl;
    }
}
