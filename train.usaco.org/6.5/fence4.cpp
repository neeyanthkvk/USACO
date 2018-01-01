/*
LANG: C++11
TASK: fence4
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <complex>
#include <functional>
using namespace std;

const double eps = 1e-7;
typedef complex<double> Point;

double crossProduct(const Point &a, const Point &b)
{
    return (a * conj(b)).imag();
}

double crossProduct(const Point &a, const Point &b, const Point &c)
{
    return crossProduct(c - a, b - a); 
}

bool isStrictlyIntersected(const Point &a, const Point &b, 
        const Point &c, const Point &d)
{
    return 
        crossProduct(a, b, c) * crossProduct(a, b, d) <= eps && 
        crossProduct(c, d, a) * crossProduct(c, d, b) <= eps;
}

bool isIntersected(const Point &a, const Point &b,
        const Point &c, const Point &d)
{
    return 
        crossProduct(a, b, c) * crossProduct(a, b, d) + eps < 0 && 
        crossProduct(c, d, a) * crossProduct(c, d, b) + eps < 0;
}



int main()
{
    ifstream fin("fence4.in");
    ofstream fout("fence4.out");

    int n;
    while (fin >> n)
    {
        vector<Point> a;
        double x, y;

        fin >> x >> y;
        Point viewer(x, y);

        for (int i = 0; i < n; i++)
        {
            fin >> x >> y;
            a.push_back(Point(x, y));
        }
        a.push_back(a[0]);

        bool is_legal = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n ; j++)
            {
                if (j + 1 == i || j == i || j == i + 1) continue;
                if (isIntersected(a[i], a[i + 1], a[j], a[j + 1]))
                    is_legal = false;
            }
        }

        if (!is_legal)
        {
            fout << "NOFENCE" << endl;
            clog << "NOFENCE" << endl;
            break;
        }

        function<bool(const Point &, const Point &, const Point &, int)> 
            isSeen = [&](const Point &l, const Point &r, const Point &view, int id)
        {
            if (norm(l - r) < eps) return false;

            bool is_left_seen, is_right_seen, is_seen = true;
            for (int i = 0; i < n; i++)
                if (i != id)
                {
                    is_left_seen = isStrictlyIntersected(a[i], a[i + 1], l, view);
                    is_right_seen = isStrictlyIntersected(a[i], a[i + 1], r, view);
                    if (is_left_seen && is_right_seen) return false;
                    if (is_left_seen || is_right_seen) is_seen = false;
                }
            if (is_seen) return true;

            Point mid = (l + r) * 0.5;
            return isSeen(l, mid, view, id) || isSeen(mid, r, view, id);

        };

        vector<pair<int, int> > ans_list;
        for (int i = 0; i < n; i++)
        {
            if (isSeen(a[i], a[i + 1], viewer, i))
            {
                int l = i, r = (i + 1) % n;
                if (l > r) swap(l, r);
                ans_list.push_back(make_pair(r, l));
            }
        }
        fout << ans_list.size() << endl;
        clog << ans_list.size() << endl;

        sort(ans_list.begin(), ans_list.end());
        for (auto & pr : ans_list)
        {
            int l = pr.second, r = pr.first; 
            fout << a[l].real() << " " << a[l].imag() << " " << 
                a[r].real() << " " << a[r].imag() << endl;
            clog << a[l].real() << " " << a[l].imag() << " " << 
                a[r].real() << " " << a[r].imag() << endl;
        }
    }

    return 0;
}