/*
PROG: picture
LANG: C++
*/

#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>

struct Rect {
    int id;
    int x1, x2;
    int y1, y2;
};

int rcmpx(const void * x, const void * y) {
    Rect * r1 = (Rect *)(x);
    Rect * r2 = (Rect *)(y);
    if (r1->x1 < r2->x1) { return -1; }
    if (r1->x1 > r2->x1) { return 1; }
    if (r1->x2 > r2->x2) { return -1; }
    if (r1->x2 < r2->x2) { return 1; }
    if (r1->id < r2->id) { return -1; }
    if (r1->id > r2->id) { return 1; }
    return 0;
}

int rcmpy(const void * x, const void * y) {
    Rect * r1 = (Rect *)(x);
    Rect * r2 = (Rect *)(y);
    if (r1->y1 < r2->y1) { return -1; }
    if (r1->y1 > r2->y1) { return 1; }
    if (r1->y2 > r2->y2) { return -1; }
    if (r1->y2 < r2->y2) { return 1; }
    if (r1->id < r2->id) { return -1; }
    if (r1->id > r2->id) { return 1; }
    return 0;
}


struct Prob {
    FILE * fin;
    FILE * fout;

    int n;
    Rect rects[5000];
    
    void readIn() {
        fin = fopen("picture.in", "r"); assert(fin);
        int ret = fscanf(fin, "%d", &n); assert(ret == 1);
        
        for (int i = 0; i < n; i++) {
            Rect & r = rects[i];
            r.id = i;
            ret = fscanf(fin, "%d %d %d %d", 
                    &r.x1, &r.y1, &r.x2, &r.y2);
            assert(ret == 4);
            assert(r.y1 < r.y2);
            assert(r.x1 < r.x2);
        }

        fclose(fin);
    }

    int xscan(int y) {
        bool c = false;
        int till = 0;
        int ret = 0;

        for (int i = 0; i < n; i++) {
            Rect & r = rects[i];
            if (r.y1 > y || r.y2 <= y) { continue; }
            assert(r.y1 <= y && r.y2 > y);

            if (!c) {
                till = r.x2;
                c = true;
                ret++;  // enter
            } else {
                if (r.x1 > till) {
                    ret++;
                    till = r.x2;
                } else if (r.x2 > till) {
                    till = r.x2;
                }
            }
        }

        return ret*2;
    }

    int yscan(int x) {
        bool c = false;
        int till = 0;
        int ret = 0;

        for (int i = 0; i < n; i++) {
            Rect & r = rects[i];
            if (r.x1 > x || r.x2 <= x) { continue; }
            assert(r.x1 <= x && r.x2 > x);

            if (!c) {
                till = r.y2;
                c = true;
                ret++;  // enter
            } else {
                if (r.y1 > till) {
                    ret++; // exit and enter
                    till = r.y2;
                } else if (r.y2 > till) {
                    till = r.y2;
                }
            }
        }

        return ret*2;
    }

    void writeOut() {
        int sum = 0;

        qsort(&rects, n, sizeof(Rect), rcmpx);
        for (int i = -10000; i <= 10000; i++) {
            sum += xscan(i);
        }

        qsort(&rects, n, sizeof(Rect), rcmpy);
        for (int i = -10000; i <= 10000; i++) {
            sum += yscan(i);
        }

        fout = fopen("picture.out", "w"); assert(fout);

        fprintf(fout, "%d\n", sum);

        fclose(fout);
    }
};

Prob prob;

int main() {
    prob.readIn();
    prob.writeOut();
    return 0;
}
