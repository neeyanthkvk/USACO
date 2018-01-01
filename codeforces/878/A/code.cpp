#include <stdio.h>

/*
0 - False
1 - True
2 - Regular
3 - NOT of Regular
*/

int num[10];
int main() {
    for(int i = 0; i < 10; i++) {
        num[i] = 2;
    }
    
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        char c[2];
        int t;
        scanf("%s %d", &c, &t);
        if(c[0] == '|') {
            for(int i = 0; i < 10; i++) {
                if(t & (1 << i)) { // The ith number of t is 1
                    num[i] = 1;
                }
            }
        }
        else if (c[0] == '&') {
            for(int i = 0; i < 10; i++) {
                if(!(t & (1<<i))) { // The ith number of t is 0
                    num[i] = 0;
                }
            }
        }
        else {
            for(int i= 0; i < 10; i++) {
                if(t & (1 << i)) { // If true, then ith number of t is 1 - xor w/ 1, else ith number of t is 0 - do nothing
                    num[i] ^= 1;
                }
            }
        }
    }
    int v0=0, v1=0, v3=0;
    for(int i = 0; i < 10; i++) {
        if(num[i] == 0) {
            v0 |= (1 << i);
        }
        if(num[i] == 1) {
            v1 |= (1 << i);
        }
        if(num[i] == 3) {
            v3 |= (1 << i);
        }
    }

    printf("3\n");
    printf("| %d\n",v1);
    printf("& %d\n", 1023^v0);
    printf("^ %d\n", v3);
    return 0;
}
