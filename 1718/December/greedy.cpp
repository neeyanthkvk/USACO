#include <bits/stdc++.h>

using namespace std;
int c[100000];
int start[100000];
// first is number skipped, second is starting index, third is sum
map<int,pair<int,int> > strk;
int main() {
    freopen("greedy.out","w",stdout);
    freopen("greedy.in","r",stdin);
    int n;
    cin >> n;
	int curanswer = 0;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        int temp = c[i];
        for(int num = 1; num <= n; num += 1) {
            if(strk.find(num) == strk.end()) {
                if(num <= temp) {
                    strk.insert(make_pair(num, make_pair(i,temp)));
                }
            }
            else {
                if(num <= temp) {
                    pair<int, int> info = strk[num];
                    int sum = info.second;
                    int index = info.first;
                    sum += temp;
                    if(sum >= n-1) {
                        bool able = true;
                        for(int in = 0; in < n-num; in++) {
                            if(c[(in+index)%n] < num) {
                                able = false;
                                break;
                            }
                        }
                        if(able) {
                            int tempans = num-index;
							if(curanswer < tempans) {
								curanswer = tempans;
							}
                        }
                    }
                    else {
                        strk[num] = make_pair(index, sum);
                    }
                }
                else {
                    strk.erase(num);
                }
            }
        }
    }
    cout << curanswer << endl;
    return 0;
}   
