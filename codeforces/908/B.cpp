#include <bits/stdc++.h>

using namespace std;

pair<int,int> directions[4];
bool obs[50][50];
int main() {
    directions[0] = make_pair(1,0);
    directions[1] = make_pair(-1,0);
    directions[2] = make_pair(0,1);
    directions[3] = make_pair(0,-1);
    pair<int,int> start;
    pair<int,int> end;

    int l, w;
    cin >> l >> w;
    for(int i = 0; i < l; i++) {
        string temp;
        cin >> temp;
        const char* t = temp.c_str();
        for(int j = 0; j < w; j++) {
            obs[i][j] = (t[j] == '#');
            if(t[j] == 'S') {
                start = make_pair(i,j);
            }
            if(t[j] == 'E') {
                end = make_pair(i,j);
            }
        }
    }
    string temp2;
    cin >> temp2;
    const char* inst = temp2.c_str();
    int ans = 0;
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            for(int c = 0; c < 4; c++) {
                for(int d = 0; d < 4; d++) {
                    set<int> temp({a,b,c,d});
                    if(temp.size() != 4) continue;
                    if(a == b || a == c || a == d || b == c || b == d || c == d) continue;
                    // A - 0 B - 1 C - 2 D - 3
                    int curx = start.first;
                    int cury = start.second;
                    for(int i = 0; i < temp2.length(); i++) {
                        char t = inst[i];
                        pair<int,int> dir;
                        if(t == '0') dir = directions[a];
                        if(t == '1') dir = directions[b];
                        if(t == '2') dir = directions[c];
                        if(t == '3') dir = directions[d];
                        int newx = curx + dir.first;
                        int newy = cury + dir.second;
                        if(newx >= l || newx < 0 || newy >= w || newy < 0) break;
                        if(obs[newx][newy]) break;
                        curx = newx;
                        cury = newy;

                        if(curx == end.first && cury == end.second) {
                            ans += 1;
                            break;
                        }
                    }
                }

            }
        }
    }
    cout << ans << endl;

}
