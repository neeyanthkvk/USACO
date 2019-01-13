#include <bits/stdc++.h>

using namespace std;
map<string, int> occur;
map<int,int> answers;
vector<string> strings;
int main() {
    freopen("standingout.in", "r",stdin);
    freopen("standingout.out","w",stdout);
    int N;
    cin >> N;
	for(int i = 0; i < N; i++) {
		answers.insert(make_pair(i,0));
	}
    int maxlength = 0;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
        maxlength = s.length()>maxlength?s.length():maxlength;
    }
    for(int len = 1; len <= maxlength; len++) {
        occur.clear();
        for(int ind = 0; ind < N; ind++) {
            string s = strings[ind];
            for(int start = 0; start < s.length()-(len-1); start += 1) {
				//cout << s << "\t" << len << "\t" << start << endl;
				if(start+len > s.length()) {
					break;
				}
                string temp = s.substr(start,len);
                if(occur.find(temp) != occur.end() && occur[temp] != ind) {
                    occur[temp] = -1;
                }
                if(occur.find(temp) == occur.end()) {
                    occur.insert(make_pair(temp,ind));
                }       
            }
        }
		
		for(int ind = 0; ind < N; ind++) {
            string s = strings[ind];
			set<string> visited;
            for(int start = 0; start < s.length()-(len-1); start += 1) {
				if(start+len > s.length()) {
					break;
				}
				string temp = s.substr(start,len);
				if(visited.find(temp) != visited.end()) {
					continue;
				}
                if(occur[temp] == ind) {
					answers[ind] += 1;
				}				
				visited.insert(temp);
            }
        }
    }
	for(int i = 0; i < N; i++) {
		cout << answers[i] << endl;
	}
}
