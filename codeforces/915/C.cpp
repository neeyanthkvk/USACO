#include <bits/stdc++.h>
using namespace std;

map<int, int>haveInt;
vector<int>need;
vector<int>answer;

void prnt() {
	for (auto x : answer)cout << x;
	exit(0);
}

void formAll() {
	while (!haveInt.empty()) {
		map<int, int>::iterator it = haveInt.end();
		it--;
		answer.push_back(it->first);
		it->second -= 1;
		if (it->second == 0)
			haveInt.erase(it);
	}
	prnt();
}

void tryNum(int a) {
	if (haveInt.size()==0)
		prnt();
	map<int, int>::iterator it = haveInt.lower_bound(need[a]);
	if (it != haveInt.end() && it->first == need[a]) {
		int x = it->first;
		it->second--;
		if (it->second == 0)
			haveInt.erase(it);
		answer.push_back(x);
		tryNum(a + 1);
		haveInt[x]++;
		answer.pop_back();
	}
	it = haveInt.lower_bound(need[a]);
	if (it == haveInt.begin())return;
	it--;
	answer.push_back(it->first);
	it->second--;
	if (it->second == 0)
		haveInt.erase(it);
	formAll();
}


int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	swap(s1, s2);
	for (auto x : s2)
		haveInt[x - '0']++;
	if (s2.length() < s1.length())
		formAll();
	for (auto x : s1)
		need.push_back(x - '0');
	tryNum(0);

	
	return 0;
}