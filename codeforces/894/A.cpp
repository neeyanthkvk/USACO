#include <bits/stdc++.h>
using namespace std;
int num[100];


int main() {
    int rn = 0;
    string line;
    getline(cin, line);

    int totQ = 0;
    int sizeS = line.size();
    for(int i = 0; i < sizeS; i++) {
        if(line.at(i) == 'Q') {
            totQ += 1;
        }
        num[i] = totQ;
    }
    int answer = 0;
    for(int i = 0; i < sizeS; i++) {
        if(line.at(i) == 'A') {
            answer += num[i] * (totQ-num[i]);
        }
    }
    cout << answer << endl;

}
