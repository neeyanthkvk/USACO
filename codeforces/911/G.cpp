#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

static void adjust(list<int> &X, list<int> &Y, int l, int r)
{
    auto it = X.begin();
    while (it != X.end())
    {
        auto nxt = next(it);
        if (*it >= l && *it < r)
            Y.splice(Y.begin(), X, it);
        it = nxt;
    }
}

int main()
{
    int N;
    cin >> N;
    int S = min(500, N);
    int M = (N + S - 1) / S;
    int H = 101;
    vector<vector<list<int>>> pos(H, vector<list<int>>(M));
    for (int i = 0; i < N; i++)
    {
        int s = i / S;
        int a;
        cin >> a;
        pos[a][s].push_back(i);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        l--;
        if (x == y)
            continue;
        int sl = l / S;
        int sr = (r - 1) / S;
        adjust(pos[x][sl], pos[y][sl], l, r);
        if (sl != sr)
            adjust(pos[x][sr], pos[y][sr], l, r);
        for (int i = sl + 1; i < sr; i++)
            pos[y][i].splice(pos[y][i].begin(), std::move(pos[x][i]));
    }

    vi a(N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < H; j++)
            for (int p : pos[j][i])
                a[p] = j;

    for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}