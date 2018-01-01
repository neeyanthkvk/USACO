#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int read()
{
    int v = 0, f = 1;
    char c = getchar();
    while (c < 48 || 57 < c) {if (c == '-') f = -1; c = getchar();}
    while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
    return v * f;
}
const int N = 1001000;

const ll p1 = 998244353, p2 = 1986202501;
char ch[N];
ll mi1[N], mi2[N], a[N];
int n;

ll pw(ll a, ll b, ll c)
{
    ll re = 1;
    while (b)
    {
        if (b & 1)
            re = re * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return re;
}

bool print(int u, int v, int w)
{
    if (a[1] == 0 && u > 1 || a[u + 1] == 0 && v > 1 || a[u + v + 1] == 0 && w > 1) return 0;
    int cnt = 0;
    while (u--)
        printf("%c", ch[++cnt]);
    printf("+");
    while (v--)
        printf("%c", ch[++cnt]);
    printf("=");
    while (w--)
        printf("%c", ch[++cnt]);
    puts("");
    return 1;
}

ll cal(int l, int r)
{
    ll re = 0;
    for (int i = l; i <= r; i++)
        re = (re * 10 + a[i]) % p1;
    return re;
}

int main()
{
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    for (int i = 1; i <= n; i++) a[i] = ch[i] - '0';
    ll inv1 = pw(10, p1 - 2, p1);
    ll inv2 = pw(10, p2 - 2, p2);
    mi1[0] = 1;
    mi2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        mi1[i] = mi1[i - 1] * 10 % p1;
        mi2[i] = mi2[i - 1] * 10 % p2;
    }
    int l = n, r = 1;
    for (int i = n; i >= 1; i--)
    {
        int len = n - i + 1;
        if (len >= i - 1) continue;
        if (len < i - 1 - len) continue;
        l = min(l, i);
        r = max(r, i);
    }
    ll t1 = 0, t2 = 0, t3 = 0;
    ll s1 = 0, s2 = 0, s3 = 0;
    for (int i = r; i <= n; i++)
    {
        t3 = (t3 + mi1[n - i] * a[i]) % p1;
        s3 = (s3 + mi2[n - i] * a[i]) % p2;
    }
    for (int i = 1; i <= n - r + 1; i++)
    {
        t1 = (t1 + mi1[n - r + 1 - i] * a[i]) % p1;
        s1 = (s1 + mi2[n - r + 1 - i] * a[i]) % p2;
    }
    for (int i = n - r + 2; i <= r - 1; i++)
    {
        t2 = (t2 + mi1[r - 1 - i] * a[i]) % p1;
        s2 = (s2 + mi2[r - 1 - i] * a[i]) % p2;
    }
    for (int i = r; i >= l; i--)
    {
        if ((t1 + t2) % p1 == t3 && (s1 + s2) % p2 == s3)
            if (print(n - i + 1, n - (n - i + 1) * 2, n - i + 1)) return 0;
        t3 = (t3 + mi1[n - i + 1] * a[i - 1]) % p1;
        s3 = (s3 + mi2[n - i + 1] * a[i - 1]) % p2;
        t1 = (t1 * 10 % p1 + a[n - i + 2]) % p1;
        s1 = (s1 * 10 % p2 + a[n - i + 2]) % p2;
        t2 = (t2 - mi1[i - 1 - (n - i + 2)] * a[n - i + 2] % p1 + p1) % p1;
        t2 = (t2 - a[i - 1] + p1) % p1 * inv1 % p1;
        s2 = (s2 - mi2[i - 1 - (n - i + 2)] * a[n - i + 2] % p2 + p2) % p2;
        s2 = (s2 - a[i - 1] + p2) % p2 * inv2 % p2;
    }

    t1 = 0, t2 = 0, t3 = 0;
    s1 = 0, s2 = 0, s3 = 0;
    for (int i = r; i <= n; i++)
    {
        t3 = (t3 + mi1[n - i] * a[i]) % p1;
        s3 = (s3 + mi2[n - i] * a[i]) % p2;
    }
    for (int i = 1; i <= n - (n - r + 1) * 2; i++)
    {
        t1 = (t1 + mi1[n - (n - r + 1) * 2 - i] * a[i]) % p1;
        s1 = (s1 + mi2[n - (n - r + 1) * 2 - i] * a[i]) % p2;
    }
    for (int i = r - (n - r + 1); i <= r - 1; i++)
    {
        t2 = (t2 + mi1[r - 1 - i] * a[i]) % p1;
        s2 = (s2 + mi2[r - 1 - i] * a[i]) % p2;
    }
    for (int i = r; i >= l; i--)
    {
        if ((t1 + t2) % p1 == t3 && (s1 + s2) % p2 == s3)
            if (print(n - (n - i + 1) * 2, n - i + 1, n - i + 1)) return 0;
        t3 = (t3 + mi1[n - i + 1] * a[i - 1]) % p1;
        s3 = (s3 + mi2[n - i + 1] * a[i - 1]) % p2;
        t1 = (t1 - a[n - (n - i + 1) * 2] + p1) % p1 * inv1 % p1;
        t1 = (t1 - a[n - (n - i + 1) * 2 - 1] + p1) % p1 * inv1 % p1;
        s1 = (s1 - a[n - (n - i + 1) * 2] + p2) % p2 * inv2 % p2;
        s1 = (s1 - a[n - (n - i + 1) * 2 - 1] + p2) % p2 * inv2 % p2;
        t2 = (t2 + mi1[i - 1 - (n - (n - i + 1) * 2)] * a[n - (n - i + 1) * 2]) % p1;
        t2 = (t2 + mi1[i - 1 - (n - (n - i + 1) * 2 - 1)] * a[n - (n - i + 1) * 2 - 1]) % p1;
        t2 = (t2 - a[i - 1] + p1) % p1 * inv1 % p1;
        s2 = (s2 + mi2[i - 1 - (n - (n - i + 1) * 2)] * a[n - (n - i + 1) * 2]) % p2;
        s2 = (s2 + mi2[i - 1 - (n - (n - i + 1) * 2 - 1)] * a[n - (n - i + 1) * 2 - 1]) % p2;
        s2 = (s2 - a[i - 1] + p2) % p2 * inv2 % p2;
    }


    l = n, r = 1;
    for (int i = n; i >= 1; i--)
    {
        int len = n - i + 1;
        if (len - 1 >= i - 1) continue;
        if (len - 1 < i - len) continue;
        l = min(l, i);
        r = max(r, i);
    }
    t1 = 0, t2 = 0, t3 = 0;
    s1 = 0, s2 = 0, s3 = 0;
    for (int i = r; i <= n; i++)
    {
        t3 = (t3 + mi1[n - i] * a[i]) % p1;
        s3 = (s3 + mi2[n - i] * a[i]) % p2;
    }
    for (int i = 1; i <= n - r; i++)
    {
        t1 = (t1 + mi1[n - r - i] * a[i]) % p1;
        s1 = (s1 + mi2[n - r - i] * a[i]) % p2;
    }
    for (int i = n - r + 1; i <= r - 1; i++)
    {
        t2 = (t2 + mi1[r - 1 - i] * a[i]) % p1;
        s2 = (s2 + mi2[r - 1 - i] * a[i]) % p2;
    }
    for (int i = r; i >= l; i--)
    {
        if ((t1 + t2) % p1 == t3 && (s1 + s2) % p2 == s3)
            if (print(n - i, n - (n - i + 1) - (n - i), n - i + 1)) return 0;
        t3 = (t3 + mi1[n - i + 1] * a[i - 1]) % p1;
        s3 = (s3 + mi2[n - i + 1] * a[i - 1]) % p2;
        t1 = (t1 * 10 % p1 + a[n - i + 1]) % p1;
        s1 = (s1 * 10 % p2 + a[n - i + 1]) % p2;
        t2 = (t2 - mi1[i - 1 - (n - i + 1)] * a[n - i + 1] % p1 + p1) % p1;
        t2 = (t2 - a[i - 1] + p1) % p1 * inv1 % p1;
        s2 = (s2 - mi2[i - 1 - (n - i + 1)] * a[n - i + 1] % p2 + p2) % p2;
        s2 = (s2 - a[i - 1] + p2) % p2 * inv2 % p2;
    }

    t1 = 0, t2 = 0, t3 = 0;
    s1 = 0, s2 = 0, s3 = 0;
    for (int i = r; i <= n; i++)
    {
        t3 = (t3 + mi1[n - i] * a[i]) % p1;
        s3 = (s3 + mi2[n - i] * a[i]) % p2;
    }
    for (int i = 1; i <= n - (n - r + 1) - (n - r); i++)
    {
        t1 = (t1 + mi1[n - (n - r + 1) - (n - r) - i] * a[i]) % p1;
        s1 = (s1 + mi2[n - (n - r + 1) - (n - r) - i] * a[i]) % p2;
    }
    for (int i = r - (n - r); i <= r - 1; i++)
    {
        t2 = (t2 + mi1[r - 1 - i] * a[i]) % p1;
        s2 = (s2 + mi2[r - 1 - i] * a[i]) % p2;
    }
    for (int i = r; i >= l; i--)
    {
        if ((t1 + t2) % p1 == t3 && (s1 + s2) % p2 == s3)
            if (print(n - (n - i + 1) - (n - i), n - i, n - i + 1)) return 0;
        t3 = (t3 + mi1[n - i + 1] * a[i - 1]) % p1;
        s3 = (s3 + mi2[n - i + 1] * a[i - 1]) % p2;
        t1 = (t1 - a[n - (n - i + 1) - (n - i)] + p1) % p1 * inv1 % p1;
        t1 = (t1 - a[n - (n - i + 1) - (n - i) - 1] + p1) % p1 * inv1 % p1;
        s1 = (s1 - a[n - (n - i + 1) - (n - i)] + p2) % p2 * inv2 % p2;
        s1 = (s1 - a[n - (n - i + 1) - (n - i) - 1] + p2) % p2 * inv2 % p2;
        t2 = (t2 + mi1[i - 1 - (n - (n - i + 1) - (n - i))] * a[n - (n - i + 1) - (n - i)]) % p1;
        t2 = (t2 + mi1[i - 1 - (n - (n - i + 1) - (n - i) - 1)] * a[n - (n - i + 1) - (n - i) - 1]) % p1;
        t2 = (t2 - a[i - 1] + p1) % p1 * inv1 % p1;
        s2 = (s2 + mi2[i - 1 - (n - (n - i + 1) - (n - i))] * a[n - (n - i + 1) - (n - i)]) % p2;
        s2 = (s2 + mi2[i - 1 - (n - (n - i + 1) - (n - i) - 1)] * a[n - (n - i + 1) - (n - i) - 1]) % p2;
        s2 = (s2 - a[i - 1] + p2) % p2 * inv2 % p2;
    }
}