#include <bits/stdc++.h>
using namespace std;


char f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char f1a[] = "What are you doing while sending \"";
char f1b[] = "\"? Are you busy? Will you send \"";
char f1c[] = "\"?";

int lenf1a = strlen(f1a);
int lenf1b = strlen(f1b);
int lenf1c = strlen(f1c);


const int MAX_N = 100000;

long long Length[1 + MAX_N];

char query(int n, long long k) {
  if (k >= Length[n])
    return '.';
  else if (n == 0)
    return f0[k];
  else if (k < lenf1a)
    return f1a[k];
  k -= lenf1a;
  if (k < Length[n - 1])
    return query(n - 1, k);
  k -= Length[n - 1];
  if (k < lenf1b)
    return f1b[k];
  k -= lenf1b;
  if (k < Length[n - 1])
    return query(n - 1, k);
  k -= Length[n - 1];
  if (k < lenf1c)
    return f1c[k];
  else
    for(;;);
}

int main(void) {
  int q;
  scanf("%d", &q);
  Length[0] = strlen(f0);
  int len1 = strlen(f1a) + strlen(f1b) + strlen(f1c);
  for (int i = 1; i <= MAX_N; i++) {
    Length[i] = 2 * Length[i - 1] + len1;
    if (Length[i] > 1000000000000000000LL)
      Length[i] = 1000000000000000000LL;
  }
  for (int i = 0; i < q; i++) {
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    k--;
    printf("%c", query(n, k));
  }
  return 0;
}