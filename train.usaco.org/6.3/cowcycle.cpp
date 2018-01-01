/*
PROG: cowcycle
LANG: C++
*/

#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>

int dcmp(const void *a, const void *b) {
    double x = *(const double *)(a);
    double y = *(const double *)(b);
    if (x < y) { return -1; }
    if (x > y) { return 1; }
    return 0;
}

struct Prob {
    FILE * fin;
    FILE * fout;

    int f, r;
    int f1, f2;
    int r1, r2;

    int fronts[5];
    int rears[10];

    int ansFronts[5];
    int ansRears[10];
    double minv;

    int ncase;
    int nvalid;
    int nfront;

    void pickFront(int i, int start) {
        if (i == f) {
            nfront++;
            pickRear(0, r1);
            return;
        }

        int nexti = i + 1;
        for (int pick = start; pick <= f2; pick++) {
            fronts[i] = pick;
            pickFront(nexti, pick + 1);
        }
    }

    void pickRear(int i, int start) {
        if (i == r) {
            calc();
            return;
        }

        int nexti = i + 1;
        for (int pick = start; pick <= r2; pick++) {
            rears[i] = pick;
            pickRear(nexti, pick + 1);
        }
    }

    double gears[50];
    double deltas[50];

    void calc() {
        ncase++;

        if (fronts[f-1] * rears[r-1] < 3 * fronts[0] * rears[0]) {
            return;
        }

        nvalid++;

        int p = 0;
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < r; j++) {
                double d = double(fronts[i]) / double(rears[j]);
                gears[p++] = d;
            }
        }
        assert(p == f * r);
        
        qsort(gears, p, sizeof(double), dcmp);

        double s = 0;
        for (int i = 0; i < p - 1; i++) {
            deltas[i] = gears[i + 1] - gears[i];
            s += deltas[i];
        }
        p--;

        double mean = s / double(p);
        double v = 0;
        for (int i = 0; i < p; i++) {
            double d = deltas[i] - mean;
            v += d * d;
        }
        
        if (minv < 0 || v < minv) {
            minv = v;

            memcpy(ansFronts, fronts, sizeof(int) * f);
            memcpy(ansRears, rears, sizeof(int) * r);
        }
    }

    void printPick() {
        for (int i = 0; i < f; i++) {
            printf("%d ", fronts[i]);
        }
        printf(" / ");

        for (int i = 0; i < r; i++) {
            printf("%d ", rears[i]);
        }
        printf("\n");
    }

    void solve() {
        ncase = 0;
        nfront = 0;
        minv = -1;
        pickFront(0, f1);
    }
    
    void readIn() {
        fin = fopen("cowcycle.in", "r"); assert(fin);
        int ret = fscanf(fin, "%d %d", &f, &r);
        assert(ret == 2);
        ret = fscanf(fin, "%d %d", &f1, &f2);
        assert(ret == 2);
        ret = fscanf(fin, "%d %d", &r1, &r2);

        fclose(fin);
    }

    void writeOut() {
        solve();
        
        printf("%d %d %d\n", nfront, ncase, nvalid);

        fout = fopen("cowcycle.out", "w"); assert(fout);

        for (int i = 0; i < f; i++) {
            if (i > 0) fprintf(fout, " ");
            fprintf(fout, "%d", ansFronts[i]);
        }
        fprintf(fout, "\n");

        for (int i = 0; i < r; i++) {
            if (i > 0) fprintf(fout, " ");
            fprintf(fout, "%d", ansRears[i]);
        }
        fprintf(fout, "\n");

        fclose(fout);
    }
};

Prob prob;

int main() {
    prob.readIn();
    prob.writeOut();
    return 0;
}