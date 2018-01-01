#include <stdio.h>
#include <functional>
#include <queue>
#include<vector>

using namespace std;

typedef long long ll;
int main() {
   priority_queue<ll, vector<ll>> pqueue;
   int N;
   scanf("%d",&N);
   for(int i = 0; i < N; i++) {
        ll t;
        scanf("%lld", &t);
        pqueue.push(t);
   }
   ll answer = 0;
   if(N % 2 == 0) {
        ll a = pqueue.top();
        pqueue.pop();
        ll b = pqueue.top();
        pqueue.pop();
        answer += a + b;
        pqueue.push(a+b);
   }
   while(pqueue.size() >= 3) {
        ll a = pqueue.top();
        pqueue.pop();
        ll b = pqueue.top();
        pqueue.pop();
        ll c = pqueue.top();
        pqueue.pop();
        answer += a+b+c;
        pqueue.push(a+b+c);
   }
   printf("%lld\n", answer);
}
