#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    const char* ac = a.c_str();
    const char* bc = b.c_str();
    char comp = bc[0];
    cout << ac[0];
    for(int i = 1; i < a.length(); i++) {
        char temp = ac[i];
        if(temp < comp) {
            cout << temp;
        }
        else {
            cout << comp;
            return 0;
        }
    }
    cout << bc[0];
}
