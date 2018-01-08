#include<bits/stdc++.h>
using namespace std;
int N, H, M, P, i, A[100001], B[100001], C[100001];
void udt(int X) {
	if (X>N) {
		return;
	}
	B[X]++;
	udt(X+(X&(-X)));
}
int qry(int X) {
	if (X==0) {
		return 0;
	}
	return B[X]+qry(X-(X&(-X)));
}
void rst() {
	for (i=1;i<=N;i++) {
		B[i]=0;
	}
}
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N;
	for (i=1;i<=N;i++) {
		cin>>A[i];
		udt(A[i]);
		C[i]=min(2,i-qry(A[i]));
	}
	rst();
	M=-2;
	for (i=N;i>=1;i--) {
		P=qry(A[i])-(C[i]==0);
		if (P>M) {
			H=A[i];
			M=P;
		}
		else if (P==M) {
			H=min(H,A[i]);
		}
		if (C[i]==1) {
			udt(A[i]);
		}
	}
	cout<<H<<'\n';
	return 0;
}
