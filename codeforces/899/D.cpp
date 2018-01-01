#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
ll cal(ll x){
	ll ret;
	if(n>=x)
		ret=(x-1)/2;
	else
		ret=((n-(x-n)+1)/2);
	return max(0ll,ret);
}
int main()
{
	ll i,j,k;
	cin>>n;
	for(i=9;i<=999999999;i=i*10+9)
		if(n+n-1<i)
			break;
	k=i/10;
	for(i=0;i<=9;i++){
		if((ll)i*(k+1)+k<=n+n-1)
			ans+=cal((ll)i*(k+1)+k);
		else
			break;
	}
	cout<<ans;
	return 0;
}