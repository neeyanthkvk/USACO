#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char s[n];
    cin >> s;
    for(int i = 0; i < m; i++) {
        int start, end;
        char a, b;
        cin >> start >> end >> a >> b;
        for(int j = start-1; j <= end-1; j++) {
            if(s[j] == a) {
                s[j] = b;
            }
        }
    }
    cout << s << endl;


}
