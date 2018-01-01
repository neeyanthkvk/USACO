#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

static int N;
static vector<vi> edges;
static vi parent;
static vi depth;
static vector<pii> dist;
static vector<bool> diam;
static int D, root, bot;
static vector<pii> cuts;

static void dfs(int cur, int p, int d)
{
    parent[cur] = p;
    depth[cur] = d;
    for (int v : edges[cur])
        if (v != p)
            dfs(v, cur, d + 1);
}

static pii get_dist(int cur)
{
    if (dist[cur].first == -1)
    {
        if (diam[cur])
        {
            if (depth[cur] > D - depth[cur])
                dist[cur] = pii(depth[cur], root);
            else
                dist[cur] = pii(D - depth[cur], bot);
        }
        else
        {
            auto sub = get_dist(parent[cur]);
            sub.first++;
            cuts.emplace_back(sub.second, cur);
            dist[cur] = sub;
        }
    }
    return dist[cur];
}

int main(int argc, const char **argv)
{
    cin >> N;
    edges.resize(N);
    parent.resize(N);
    depth.resize(N);
    diam.resize(N);
    dist.resize(N, pii(-1, -1));
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1, 0);
    root = max_element(depth.begin(), depth.end()) - depth.begin();
    dfs(root, -1, 0);
    bot = max_element(depth.begin(), depth.end()) - depth.begin();
    D = depth[bot];
    for (int i = bot; i != -1; i = parent[i])
        diam[i] = true;
    ll score = ll(D) * ll(D + 1) / 2;
    for (int i = 0; i < N; i++)
        if (!diam[i])
        {
            auto sub = get_dist(i);
            score += sub.first;
        }
    reverse(cuts.begin(), cuts.end());
    for (int i = bot; i != root; i = parent[i])
        cuts.emplace_back(root, i);
    cout << score << '\n';
    for (const auto &c : cuts)
        cout << c.first + 1 << ' ' << c.second + 1 << ' ' << c.second + 1 << '\n';

    return 0;
}