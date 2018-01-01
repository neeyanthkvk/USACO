#include <bits/stdc++.h>

using namespace std;

int main() {
    string temp;
    cin >> temp;
    const char *word = temp.c_str();
    int ans = 0;
      for(int i = 0; i < temp.length(); i++) {
        char t = word[i];
        if(t == '9' || t == '7' || t == '5' || t == '3' || t == '1' || t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') {
            ans += 1;
        }
    }
    cout << ans << endl;
}
