#include <bits/stdc++.h>
using namespace std;
bool play[3];
int main() {
    play[0] = true;
    play[1] = true;
    play[2] = false;
    int n;
    scanf("%d", &n);
    for(int i= 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if(play[temp-1] == false) {
            printf("NO");
            return 0;
        }
        for(int i = 0; i < 3; i++) {
            if(i == temp-1) {
                continue;
            }
            play[i] = play[i]? false:true;
        }
    }
    printf("YES");
    return 0;
}
