#include <bits/stdc++.h>

using namespace std;

int possibility[26];
// 0 means nothing, 1 means could be, 2 means definately NOT

char x(int a) {
    return (char) ((int) 'a' + a);
}

int main() {
    int n;
    cin >> n;
    int first = -1;
    int index = -1;
    for(int i = 0; i < n; i++) {
        char com;
        string word;
        cin >> com >> word;
        if(com != '?') {
            const char* wchar = word.c_str();
            set<char> wset;
            for(int j = 0; j < word.length(); j++) {
                wset.insert(wchar[j]);
            }
            if(com == '.') {
                for(int j = 0; j < 26; j++) {
                    if(wset.find(x(j)) != wset.end()) {
                        possibility[j] = 2;
                    }
                }
            }
            else {
                for(int j = 0; j < 26; j++) {
                    if(wset.find(x(j)) == wset.end()) {
                        possibility[j] = 2;
                    }
                    else {
                        if(possibility[j] == 0) {
                            possibility[j] = 1;
                        }
                    }
                }
            }
        }
        else {
            const char* wchar = word.c_str();
            char guess = wchar[0];
            if(i != n-1) {
                int index = (int) guess - (int) 'a';
                possibility[index] = 2;
            }
        }
        for(int j = 0; j < 26; j++) {
            if(possibility[j] != 2) {
                if(first != -1) {
                    first = -1;
                    break;
                }
                first = j;
            }
        }
        if(first != -1) {
            index = i;
            break;
        }
        
    }
    if(first == -1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = index+1; i < n-1; i++) {
        char com;
        string word;
        cin >> com >> word;
        if(com != '.') ans += 1; 
    }
    cout << ans << endl;

}
