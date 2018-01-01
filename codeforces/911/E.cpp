#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    int out = 0;
    set<int> miss;
    for (int i = 0; i < N; i++)
        miss.insert(i);
    for (int i = 0; i < K; i++)
    {
        cin >> a[i];
        a[i]--;
        miss.erase(a[i]);
    }
    stack<int> s;
    for (int i = 0; i < K; i++)
    {
        while (!s.empty() && s.top() < a[i])
        {
            if (s.top() != out) {
                cout << -1 << endl;
                return 0;
            }
            s.pop();
            out++;
        }
        s.push(a[i]);
    }

    for (int i = K; i < N; i++)
    {
        while (!s.empty() && s.top() == out)
        {
            s.pop();
            out++;
        }
        int limit = s.empty() ? 1000000000 / 2 : s.top();
        auto it = prev(miss.lower_bound(limit));
        s.push(*it);
        a[i] = *it;
        miss.erase(it);
    }

    for (int i = 0; i < N; i++)
        cout << a[i] + 1 << ' ';
    cout << '\n';

    return 0;
}
