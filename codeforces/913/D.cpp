#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

vpll time;
vpll easy;
map<pll,int> index;
int main() {
    int n;
    cin >> n;
    ll time;
    for(int i = 0; i < n; i++) {
        ll a,b;
        cin >> a >> b;
        index.insert(make_pair(a,b),i+1);
        easy.push_back(make_pair(a,b));
        time.push_back(make_pair(b,a));
    }
    vector<pll> problems;
    sort(easy.begin(),easy.end());
    sort(time.begin(),time.end());
    ll amount = 0;
    int itertime = 0;
    int itereasy = 0;
    for(itertime = 0; itertime < n; itertime++) {
        pll temp = time[itertime];
        if(temp.second <= problems.size()) continue;
        amount += temp.first;
        problems.push_back(temp);
        vector<pll> temp2;
        for(int i = 0; i < problems.size(); i++) {
            if(problems[i].second >= problems.size()) {
                temp2.push_back(problems[i])
            }
            else {
                amount -= problems[i].first;
            }
        }
        problems = temp2;
        if(amount > time) {
            amount -= temp.first;
            break;
        }
    }
    int score = problems.size();
    cout << score << endl;
    cout << score << endl;

}
