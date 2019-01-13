#include <bits/stdc++.h>

using namespace std;
map<string, int> occur;
vector<string> strings;
int main() {
    freopen("standingout.in", "r",stdin);
    freopen("standingout.out","w",stdout);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
        int slength = s.length();
        for(int j = 0; j < slength; j++) {
            for(int len = 1; len <= slength-j; len++) {
                string temp = s.substr(j, len);
                if(occur.find(temp) == occur.end()) {
                    occur.insert(make_pair(temp, i));
                }
                else if(occur[temp] != i) {
                    occur[temp] = -1;
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        string s = strings[i];
        set<string> alrd;
        int slength = s.length();
        int tot = 0;
        for(int j = 0; j < slength; j++) {
            for(int len = 1; len <= slength-j; len++) {
                string temp = s.substr(j,len);
                if(alrd.find(temp) == alrd.end()) {
                  if(occur[temp] == i) {
                      tot += 1;
                  }
                  alrd.insert(temp);
                }
            }
        }
        cout << tot << endl;
    }
}
