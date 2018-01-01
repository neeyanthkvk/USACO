/*
ID: neeyant2
PROG: stall4
LANG: C++11
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=200;

int n,m,match;
int mat[MAXN];
bool g[MAXN][MAXN];
bool used[MAXN];

bool cross(int u)
{
	for(int i=0;i<m;i++)
		if (g[u][i]&&!used[i])
		{
			used[i]=true;
			if (mat[i]==-1||cross(mat[i]))
			{
				mat[i]=u;
				return true;
			}
		}
	return false;
}

void hungary()
{
	memset(mat,-1,sizeof(mat));
	for(int i=0;i<n;i++)
	{
		memset(used,false,sizeof(used));
		if (cross(i))
			match++;
	}
}

int main()
{
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int s;
		scanf("%d",&s);
		for(int j=0,b;j<s;j++)
		{
			scanf("%d",&b);
			g[i][--b]=true;
		}
	}
	hungary();
	printf("%d\n",match);
	return 0;
}
