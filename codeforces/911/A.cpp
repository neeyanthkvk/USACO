#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[100000];
vector<int> occurences;
int main() {
    int N;
    cin >> N;
    int prevoccur = -1;
    int answer = 1000000;
    ll min = 1000000002;
    for(int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        if(temp < min) {
            prevoccur = i;
            min = temp;
            answer = 1000000;
        }
        else if(temp == min) {
            int distance = (i-prevoccur);
            if(answer > distance) {
                answer = distance;
            }
            prevoccur = i;
        }
    }
    cout << answer << endl;
}
