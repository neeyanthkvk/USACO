#include <bits/stdc++.h>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int t[39],cnt=0;
int c[25],n;
void check(){
	for (int i=1;i<=36-n+1;i++)
	{int tag=0;
	for (int j=1;j<=n;j++)
	{if (t[i+j-1]!=c[j])
	{tag=1;break;}
	}
	if (!tag) {puts("YES");exit(0);}
	}
}
	
int main (){
	int i,j;
	scanf ("%d",&n);
	for (i=1;i<=n;i++){
		scanf ("%d",&c[i]);
	}
	cnt=0;
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	check();
	cnt=0;
	for (i=1;i<=12;i++) t[++cnt]=b[i];
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	check();
	cnt=0;
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	for (i=1;i<=12;i++) t[++cnt]=b[i];
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	check();
	cnt=0;
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	for (i=1;i<=12;i++) t[++cnt]=a[i];
	for (i=1;i<=12;i++) t[++cnt]=b[i];
	check();
	puts("NO");
	return 0;
}