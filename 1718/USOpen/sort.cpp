#include <bits/stdc++.h>
using namespace std;
#define tab "\t"
int arr[100000];
int N;

vector<int> pivs(int l, int r) {
	//cout << 'a' << endl;
	multiset<int> s;
	vector<int> pivots;
	for(int i = l; i <= r; i++) s.insert(arr[i]);
	int curmax = 0;
	for(int i = l; i < r; i++) {
		curmax = max(curmax, arr[i]);
		s.erase(arr[i]);
		int curmin = *min_element(s.begin(), s.end());
		// cout << arr[i] << tab << curmax << tab << curmin << endl;
		if(curmax <= *min_element(s.begin(), s.end())) {
			pivots.push_back(i);
		}
	}
	//cout << 'A' << endl;
	return pivots;
}

void sortpass(int l, int r) {
	//	cout << 'b' << endl;
	for(int i = l; i < r; i++) {
		if(arr[i] > arr[i+1]) {
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	// cout << 'B' << endl;
}

int quickish(int l, int r) {
	// cout << 'c' << endl;
	if(l == r) return 0;
	int ans = (r-l)+1;
	sortpass(l,r);
	vector<int> pivots = pivs(l,r);
	// cout << pivots.size() << endl;
	ans += quickish(l, pivots[0]);
	for(int i = 0; i < pivots.size()-1; i++) {
		ans += quickish(pivots[i] + 1, pivots[i+1]);
	}
	ans += quickish(pivots[pivots.size()-1]+1, r);
	// cout << 'C' << endl;
	return ans;
}

int main() {
	freopen("sort.in","r",stdin);
	ofstream myfile;
	myfile.open ("sort.out");
	// cout << 'd' << endl;
	cin >> N;
	for(int i = 0; i < N; i++) {
		// cout << 'D' << endl;
		cin >> arr[i];
	}
	// cout << 'D' << endl;
	int ans = quickish(0,N-1);
	myfile << ans << endl;
	return 0;
}