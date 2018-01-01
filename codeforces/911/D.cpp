#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    int swap = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (a[i] > a[j])
                swap++;
    swap &= 1;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int l, r;
        cin >> l >> r;
        ll s = r - l + 1;
        ll c = s * (s - 1) / 2;
        swap ^= c & 1;
        cout << (swap ? "odd\n" : "even\n");
    }

    return 0;
}