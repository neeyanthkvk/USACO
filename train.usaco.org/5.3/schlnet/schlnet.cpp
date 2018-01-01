/*
PROG: schlnet
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

bool x[MAXN][MAXN];
vector<int> y[MAXN];
int l[MAXN];
bool in[MAXN], out[MAXN];



int main() {
    freopen("schlnet.in", "r", stdin);
    freopen("schlnet.out", "w", stdout);
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        int j;
        while (cin >> j) {
            if (j == 0) break;
            x[i][j] = true;
            y[i].push_back(j);
        }
    }
    
    for (int k = 1; k <= n; ++k)
     for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
       if (x[i][k] && x[k][j]) x[i][j] = true;
       
    for (int i = 1; i <= n; ++i) 
     if (l[i] == 0) {
         ++l[0];
         l[i] = i;
         for (int j = i+1; j <= n; ++j)
          if (l[j] == 0 && x[i][j] && x[j][i]) l[j] = i;
     }
     
    int ans1 = l[0], ans2 = l[0];
    
    for (int i = 1; i <= n; ++i)
     for (int j = 0; j < y[i].size(); ++j) 
      if (l[i] != l[y[i][j]]) {
          if (!in[l[y[i][j]]]) --ans1;
          in[l[y[i][j]]] = true;
          if (!out[l[i]]) --ans2;
          out[l[i]] = true;
      }
     
    cout << ans1 << endl;
    if (l[0] == 1) 
        cout << 0 << endl;
    else
        cout << max(ans1, ans2) << endl;
        
    return 0;
}
