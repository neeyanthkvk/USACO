#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200010;
struct no{
	int x,l;
	no(int a=0,int b=0){x=a;l=b;}
	bool operator<(const no&b)const{return x!=b.x?x>b.x:l<b.l;}
}x;
set<int> o;set<int>::iterator y,z;
set<no> p;set<no>::iterator q;
int n,m,i,a[N],f[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	p.insert(no(0,0));
	p.insert(no(0,n+1));
	o.insert(0);o.insert(n+1);
	for(i=1;i<=n;i++){
		if(a[i]==a[i-1])f[i]=f[i-1]+1;else f[i]=1;
		if(a[i]!=a[i+1])p.insert(no(f[i],i)),o.insert(i);
	}
	while(1){
		q=p.begin();x=*q;
		if(x.x==0)break;
		m++;p.erase(q);
		y=z=o.find(x.l);
		y--;z++;
//		printf("%d %d\n",*y,*z);
		o.erase(o.find(x.l));
		if(a[*y]==a[*z]){
			p.erase(no(f[*z],*z));
			p.erase(no(f[*y],*y));
			f[*z]+=f[*y];
			p.insert(no(f[*z],*z));
			o.erase(y);
		}
	}
	printf("%d\n",m);
	return 0;
}
