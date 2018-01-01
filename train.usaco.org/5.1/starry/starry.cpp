/*
ID: neeyant2
PROG: starry
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const int MX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int MY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, nn;
int x[MAXN][MAXN];
bool y[MAXN][MAXN];
bool z[26][MAXN][MAXN];
pair<int, int> size[26];

bool check(pair<int, int> tmp, int k) {
    int a = tmp.first + MX[k];
    int b = tmp.second + MY[k];
    if (a < 0 || a >= n) return false;
    if (b < 0 || b >= m) return false;
    if (y[a][b] || x[a][b] != 1) return false;
    y[a][b] = true;
    return true;
}

bool same(int t, int a, int b) {
    if (size[t].first == a && size[t].second == b) {
        // Original
        bool flag = true;
        for (int i = 0; i <= a; ++i)
         for (int j = 0; j <= b; ++j) flag &= (z[t][i][j] == y[i][j]);
        if (flag) return true;
        
        // Upside down
        flag = true;
        for (int i = 0; i <= a; ++i)
         for (int j = 0; j <= b; ++j) flag &= (z[t][i][j] == y[a-i][j]);
        if (flag) return true;
        
        // Left-right change
        flag = true;
        for (int i = 0; i <= a; ++i)
         for (int j = 0; j <= b; ++j) flag &= (z[t][i][j] == y[i][b-j]);
        if (flag) return true;
        
        // Left-right change and upside down
        flag = true;
        for (int i = 0; i <= a; ++i)
         for (int j = 0; j <= b; ++j) flag &= (z[t][i][j] == y[a-i][b-j]);
        if (flag) return true;
    }
    if (size[t].first == b && size[t].second == a) {
        // Rotate 90 degree clockwise, original
        bool flag = true;
        for (int i = 0; i <= b; ++i)
         for (int j = 0; j <= a; ++j) flag &= (z[t][i][j] == y[j][i]);
        if (flag) return true;
        
        // Change 1
        flag = true;
        for (int i = 0; i <= b; ++i)
         for (int j = 0; j <= a; ++j) flag &= (z[t][i][j] == y[a-j][i]);
        if (flag) return true;
        
        // Change 2
        flag = true;
        for (int i = 0; i <= b; ++i)
         for (int j = 0; j <= a; ++j) flag &= (z[t][i][j] == y[j][b-i]);
        if (flag) return true;
        
        // Change 3
        flag = true;
        for (int i = 0; i <= b; ++i)
         for (int j = 0; j <= a; ++j) flag &= (z[t][i][j] == y[a-j][b-i]);
        if (flag) return true;
    }
    return false;
}


int main() {
    freopen("starry.in", "r", stdin);
    freopen("starry.out", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
     for (int j = 0; j < m; ++j) {
         char p;
         cin >> p;
         x[i][j] = p - '0';
     }
     
    for (int i = 0; i < n; ++i)
     for (int j = 0; j < m; ++j) 
      if (x[i][j] == 1) {
          memset(y, 0, sizeof(y));
          int a = m, b = 0, c = n, d = 0;
          queue<pair<int, int> > que;
          que.push(make_pair(i, j));
          y[i][j] = true;
          while (!que.empty()) {
              pair<int, int> tmp = que.front();
              que.pop();
              a = min(a, tmp.second);
              b = max(b, tmp.second);
              c = min(c, tmp.first);
              d = max(d, tmp.first);
              for (int k = 0; k < 8; ++k)
               if (check(tmp, k))
                que.push(make_pair(tmp.first + MX[k], tmp.second + MY[k]));
          }
          
          for (int k = 0; k <= d - c; ++k)
           for (int l = 0; l <= b - a; ++l) y[k][l] = y[k+c][l+a];
          
          int t;
          for (t = 0; t < nn; ++t) 
           if (same(t, d-c, b-a)) break;
          
          if (t == nn) {
              ++nn;
              for (int k = 0; k <= d - c; ++k)
               for (int l = 0; l <= b - a; ++l) 
                if (y[k][l]) z[t][k][l] = y[k][l];
              size[t] = make_pair(d-c, b-a);
          }
          
          for (int k = 0; k <= d - c; ++k)
           for (int l = 0; l <= b - a; ++l) 
            if (y[k][l]) x[k+c][l+a] = t + 2;
      }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
         if (x[i][j] > 0) 
             cout << (char)(x[i][j] - 2 + 'a');
         else
             cout << 0;
        cout << endl;
    }
    
    
    return 0;
}