#include <bits/stdc++.h>
    
const int MAXN = 200000 + 10;
int N;
int degree[MAXN];
int cnt, ans1[MAXN], ans2[MAXN];
bool flag;

int main() {
	register int i, j;
	scanf( "%d", &N );
	for( i = 1; i <= N + 1; ++i )
		scanf( "%d", degree + i );
	flag = 1;
	for( i = 1; i <= N; ++i )
		flag &= !( degree[i] > 1 && degree[i + 1] > 1 );
	if( flag )
		return 0 * puts( "perfect" );
	puts( "ambiguous" );
	for( i = 1; i <= N + 1; ++i )
		if( degree[i - 1] > 1 && degree[i] > 1 ) {
			ans1[++cnt] = cnt - 1, ans2[cnt] = cnt - 1;
			for( j = 2; j <= degree[i]; ++j )
				ans1[++cnt] = cnt - j, ans2[cnt] = cnt - j - 1;
		}
		else
			for( j = 1; j <= degree[i]; ++j )
				ans1[++cnt] = cnt - j, ans2[cnt] = cnt - j;
	for( i = 1; i <= cnt; ++i )
		printf( i == cnt ? "%d\n" : "%d ", ans1[i] );
	for( i = 1; i <= cnt; ++i )
		printf( i == cnt ? "%d\n" : "%d ", ans2[i] );
	return 0;
}