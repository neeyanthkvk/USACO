#include <bits/stdc++.h>

using namespace std;

bool ans[1500][1500];
bool board[1500][1500];
int n, m, q;
set<pair<int, int> > visiteddfs;
set<pair<pair<int, int> ,pair<int,int> > > visitedans;


bool isInRange(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < m;
}

void dfs(int inr, int inc, int boxr, int boxc) {
    visiteddfs.insert(make_pair(inr, inc));
    if(isInRange(inr-1, inc) && visiteddfs.find(make_pair(inr-1,inc)) == visiteddfs.end()) {
        if(board[inr-1][inc] && (boxr != inr-1 || inc != boxc)) {
			dfs(inr-1, inc, boxr, boxc);
        }
    }
	if(isInRange(inr+1, inc) && visiteddfs.find(make_pair(inr+1,inc)) == visiteddfs.end()) {
        if(board[inr+1][inc] && (boxr != inr+1 || inc != boxc)) {
			dfs(inr+1, inc, boxr, boxc);
        }
    }
	if(isInRange(inr, inc-1) && visiteddfs.find(make_pair(inr,inc-1)) == visiteddfs.end()) {
        if(board[inr][inc-1] && (boxr != inr || inc-1 != boxc)) {
			dfs(inr, inc-1, boxr, boxc);
        }
    }
	if(isInRange(inr, inc+1) && visiteddfs.find(make_pair(inr,inc+1)) == visiteddfs.end()) {
        if(board[inr][inc+1] && (boxr != inr || inc+1 != boxc)) {
			dfs(inr, inc+1, boxr, boxc);
        }
    }
	return;
}
// rb and cb location of box, ra ca location of person;
void recur(int rb, int cb, int ra, int ca) {
    //Left
	if(visitedans.find(make_pair(make_pair(rb,cb),make_pair(ra,ca))) != visitedans.end()) {
		return;
	}
	visitedans.insert(make_pair(make_pair(rb,cb),make_pair(ra,ca)));
    int nr = rb;
    int nc = cb-1;
	dfs(ra, ca, rb, cb);
	bool one = false, two = false, three = false, four = false;
    if(isInRange(nr, nc) && !ans[nr][nc] && board[nr][nc]) {
		int gr = rb;
		int gc = cb+1;
		if(isInRange(gr, gc) && board[gr][gc]) {
			one = (visiteddfs.find(make_pair(gr,gc)) != visiteddfs.end());
		}
    }
	nr = rb;
    nc = cb+1;
    if(isInRange(nr, nc) && !ans[nr][nc] && board[nr][nc]) {
		int gr = rb;
		int gc = cb-1;
		if(isInRange(gr, gc) && board[gr][gc]) {
			two = (visiteddfs.find(make_pair(gr,gc)) != visiteddfs.end());
		}
    }
	nr = rb-1;
    nc = cb;
    if(isInRange(nr, nc) && !ans[nr][nc] && board[nr][nc]) {
		int gr = rb+1;
		int gc = cb;
		if(isInRange(gr, gc) && board[gr][gc]) {
			three = (visiteddfs.find(make_pair(gr,gc)) != visiteddfs.end());
		}
    }
	nr = rb+1;
    nc = cb;
    if(isInRange(nr, nc) && !ans[nr][nc] && board[nr][nc]) {
		int gr = rb-1;
		int gc = cb;
		if(isInRange(gr, gc) && board[gr][gc]) {
			four = (visiteddfs.find(make_pair(gr,gc)) != visiteddfs.end());
		}
    }
	visiteddfs.clear();
	if(one) {
		ans[rb][cb-1] = true;
		recur(rb, cb-1, rb, cb+1);
	}
	if(two) {
		ans[rb][cb+1] = true;
		recur(rb, cb+1, rb, cb-1);
	}
	if(three) {
		ans[rb-1][cb] = true;
		recur(rb-1, cb, rb+1, cb);
	}
	if(four) {
		ans[rb+1][cb] = true;
		recur(rb+1, cb, rb-1, cb);
	}
}


int main() {
    freopen("pushabox.in","r",stdin);
    freopen("pushabox.out","w",stdout);
    cin >> n >> m >> q;
	pair<int, int> a, b;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int j = 0;
		for(char&c : s) {
			ans[i][j] = false;
			if(c == '#') {
				board[i][j] = false;
			}
			else {
				board[i][j] = true;
			}
			j += 1;
			if(c == 'A') {
				a = make_pair(i,j);
			}
			if(c == 'B') {
				b = make_pair(i,j);
			}
		}
	}
	recur(b.first, b.second, a.first, a.second);
	
	for(int i = 0; i < q; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		temp1 -= 1;
		temp2 -= 1;
		if(ans[temp1][temp2]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
    
}
