#include <bits/stdc++.h>

const int MAXN = 150 + 10;
int N;
int A[MAXN][2][MAXN];

int main() {
	register int i, j;
	scanf( "%d", &N );
	A[1][0][0] = 0;
	A[1][0][1] = 1;
	A[1][1][0] = 1;
	for( i = 2; i <= N; ++i )
		for( j = 0; j <= N; ++j ) {
			A[i][1][j] = A[i - 1][0][j];
			if( j != 0 )
				A[i][0][j] = A[i - 1][0][j - 1];
			A[i][0][j] += A[i - 1][1][j];
			if( A[i][0][j] == 2 || A[i][0][j] == -2 )
				A[i][0][j] = 0;
		}
	printf( "%d\n", N );
	for( i = 0; i <= N; ++i )
		printf( i == N ? "%d\n" : "%d ", A[N][0][i] );
	printf( "%d\n", N - 1 );
	for( i = 0; i < N; ++i )
		printf( i == N - 1 ? "%d\n" : "%d ", A[N][1][i] );
	return 0;
}