#include <bits/stdc++.h>

const int MAXN = 30000 + 10;
int N;
int cnt = 0, head[MAXN], next[MAXN], to[MAXN];
int color[MAXN];
int ans;

inline void insert( int x, int y ) {
	next[++cnt] = head[x], to[cnt] = y, head[x] = cnt;
}

int main() {
	register int i, j;
	int x;
	scanf( "%d", &N );
	for( i = 2; i <= N; ++i )
		scanf( "%d", &x ), insert( x, i );
	for( i = 1; i <= N; ++i )
		scanf( "%d", color + i );
	for( i = 1; i <= N; ++i )
		for( j = head[i]; j; j = next[j] )
			if( color[i] != color[to[j]] )
				++ans;
	printf( "%d\n", ans + 1 );
	return 0;
}