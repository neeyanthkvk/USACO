#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
ll size[40];
vector<pair<double, int> > abund;

int myMeth(int i) {
	int power = 1;
	for(int j = 0; j < i; j++) {
		power *= 2;
	}
	return power;
}
int main() {
    int n;
    ll L;
	ll sum = 0;
    cin >> n >> L;
    for(int i = 0; i < n; i++) {
        cin >> size[i];
		abund.push_back(make_pair(((double) myMeth(i)) / size[i] , i));
    }
	sort(abund.begin(), abund.end());
	reverse(abund.begin(), abund.end());
    ll minAns = 9223372036854775807;
	ll total = 0;
	for(int i = 0; i < n; i++) {
		int temp = abund[i].second;
		int siz = myMeth(temp);
		ll cost = size[temp];
		int amount = L / siz;
		total += amount*cost;
		if(minAns > total + cost) {
			minAns = total+cost;
		}
		L = L % siz;
	}
	if(minAns > total) {
		minAns = total;
	}
	cout << minAns << endl;
    

    
}
