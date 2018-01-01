/*
ID: neeyant2
LANG: C++
PROG: nuggets
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,a[11],ans;
int f[256]={0};
int mini=300,maxx=0;
int main()
{
    freopen("nuggets.in","r",stdin);
    freopen("nuggets.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]<mini) mini=a[i];
        if(a[i]>maxx) maxx=a[i];
    }
    for(int i=2;i<=mini;++i)
    {
        int ff=1;
        for(int j=1;j<=n;++j) if(a[j]%i) {ff=0;break;}
        if(ff) {cout<<0<<endl;return 0;}
    }
    int tot=1,cur=0;f[0]=1;
    while(tot<mini)
    {
        ++cur;
        int can=0;
        for(int i=1;i<=n;++i)
            if(f[(cur-a[i]+maxx)%maxx]) {can=1;break;}
        if(can) {f[cur%maxx]=1;++tot;}
        else {ans=cur;tot=0;}
    }
    cout<<ans<<endl;
    return 0;
}
