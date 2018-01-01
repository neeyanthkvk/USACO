#include <bits/stdc++.h>

using namespace std;

int main() {
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector<int> moves;
    while(h2 > 0) {
        if(h2 <= a1) {
            moves.push_back(0);
            break;
        }
        if(h1 > a2) {
            moves.push_back(0);
            h1 -= a2;
            h2 -= a1;
        }
        else {
            moves.push_back(1);
            h1 -= a2;
            h1 += c1;
        }
    }
    cout << moves.size() << endl;
    for(int i= 0; i < moves.size(); i++) {
        if(moves[i] == 1) {
            cout << "HEAL" << endl;
        }
        else {
            cout << "STRIKE" << endl;
        }
    }
}
