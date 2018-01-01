#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    ll sum = 0;
    ll n, MOD;
    cin >> n >> MOD;
    for(int i = 1; i < 10; i++) {
        if(n == 0) {
            cout << sum;
            return 0;
        }
        sum += (ll) (11 % MOD)*i;
        sum %= MOD;
        n -= 1;
    }
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(n == 0) {
                cout << sum;
                return 0;
            }
            sum += (ll) (1001%MOD)*i + (110% MOD)*j;
            sum = sum % MOD;
            n -= 1;
        }       
    }
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                if(n == 0) {
                    cout << sum;
                    return 0;
                }
                sum += (ll) (100001 % MOD)* i + (10010% MOD)*j +(1100 % MOD)* k;
                sum = sum % MOD;
                n -= 1;
            }
        }
}   
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 10; l++) {
                    if(n == 0) {
                        cout << sum;
                        return 0;
                    }
                    sum += (ll) (10000001 % MOD) * i + (1000010 % MOD) * j + (100100 % MOD) * k + (11000 % MOD) * l;
                    sum = sum % MOD;
                    n -= 1;
                }
            }       
        }
    }

    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 10; l++) {
                    for(int a = 0; a < 10; a++) {
                        if(n == 0) {
                            cout << sum;
                            return 0;
                        }
                        sum += (ll) (1000000001 % MOD) * i + (100000010 % MOD) * j + (10000100 % MOD) * k + (1001000 % MOD) * l + (110000 % MOD) * a;
                        sum = sum % MOD;
                        n -= 1;
                    }
                }
            }
        }
    }
    
	for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 10; l++) {
                    for(int a = 0; a < 10; a++) {
						for(int b = 0; b < 10; b++) {
							if(n == 0) {
								cout << sum;
								return 0;
							}
							sum += (ll) (100000000001 % MOD) * i + (10000000010 % MOD) * j + (1000000100 % MOD) * k + (100001000 % MOD) * l + (10010000 % MOD) * a + (1100000 % MOD) * b;
							sum = sum % MOD;
							n -= 1;
						}
                    }
                }
            }
        }
    }
    
    return 0;
}
