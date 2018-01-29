#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tree[2000000];
int trstp = 1;

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

void query(int root, int u, int v, int x, int s, int e, int& ans) {
  if (e < s || v < u || e < u || v < s) {
    return;
  } else if (u <= s && e <= v) {
    if (tree[root] % x == 0) {
      return;
    } else {
      while (root < trstp) {
        if (tree[2*root] % x != 0) {
          if (tree[2*root + 1] % x != 0) {
            ans += 2;
            return;
          }
          root = 2*root;
        } else {
          root = 2*root + 1;
        }
      }
      ans++;
      return;
    }
  }
  int mid = (s + e)/2;
  query(2*root, u, v, x, s, mid, ans);
  if (ans > 1) {
    return;
  }
  query(2*root + 1, u, v, x, mid + 1, e, ans);
}

void update(int p, int x) {
  p += trstp - 1;
  tree[p] = x;

  p /= 2;
  while (p > 0) {
    tree[p] = gcd(tree[2*p], tree[2*p + 1]);
    p /= 2;
  }
}

int main() {
  int n;
  cin >> n;
  while (trstp < n) {
    trstp *= 2;
  }

  for (int i = trstp; i < trstp + n; i++) {
    cin >> tree[i];
  }
  for (int i = trstp - 1; i >= 1; i--) {
    tree[i] = gcd(tree[2*i], tree[2*i + 1]);
  }

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      int x;
      cin >> l >> r >> x;
      int ans = 0;
      query(1, l, r, x, 1, trstp, ans);
      cout << (ans <= 1 ? "YES\n" : "NO\n");
    } else {
      int i;
      int y;
      cin >> i >> y;
      update(i, y);
    }
  }

  return 0;
}