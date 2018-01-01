/*
LANG: C++11
TASK: betsy
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

inline int getState(int msk, int pos)
{
    return (msk >> (pos << 1)) & 3;
}

inline int setState(int msk, int pos, int val)
{
    assert(val != 3 && val < 4);
    msk &= ~(3 << (pos << 1));
    msk |= val << (pos << 1);
    return msk;
}

inline int setState(int msk, int pos, int val, int pval)
{
    assert(val != 3 && val < 4);
    assert(pval != 3 && pval < 4);
    msk &= ~(15 << (pos << 1));
    msk |= ((pval << 2) | val) << (pos << 1);
    return msk;
}

inline void printState(int msk, int n)
{
    //clog << "(" << msk << ", " << n << ") = ";
    //for (int i = 0; i <= n; i++) //clog << getState(msk, i);
    //clog << endl;
}

int main()
{
    ifstream fin("betsy.in");
    ofstream fout("betsy.out");

    int n;
    while (fin >> n)
    {
        if (n == 1) {fout << 1 << endl; continue;}
        const int _bound_state = 1 << ((n + 1) << 1);
        int f[2][n + 1][_bound_state];
        memset(f, 0, sizeof(f));
        f[0][n][setState(setState(0, 0, 1), n - 1, 2)] = 1;

        for (int y = 1; y <= n; y++)
        {
            int u = y & 1, v = ~y & 1;

            memset(f[u], 0, sizeof(f[u]));

            for (int s = 0; s < (_bound_state >> 2); s += 1)
                if (f[v][n][s])
                    f[u][0][s << 2] = f[v][n][s];
            
            for (int x = 1; x <= n; x++)
            {
                for (int s = 0; s < _bound_state; s++)
                    if (f[u][x - 1][s])
                    {
                        //clog << "x = " << x << ", y = " << y << endl;
                        printState(s, n);
                        int l = getState(s, x - 1), r = getState(s, x);
                        if (l && r)
                        {
                            if (l == 1 && r == 2)
                            {
                                continue;
                            }
                            else if (l == 2 && r == 1)
                            {
                                f[u][x][setState(s, x - 1, 0, 0)] += f[u][x - 1][s];
                            }
                            else if (l == 2 && r == 2)
                            {
                                int S = setState(s, x - 1, 0, 0), count = 0;
                                for (int z = x - 2; z >= 0; z--)
                                {
                                    count += getState(s, z) == 2;
                                    count -= getState(s, z) == 1;
                                    if (count < 0)
                                    {
                                        S = setState(S, z, 2);
                                        break;
                                    }
                                }
                                //clog << "pre : "; printState(s, n);
                                //clog << "aft : "; printState(S, n);

                                f[u][x][S] += f[u][x - 1][s];
                            }
                            else if (l == 1 && r == 1)
                            {
                                int S = setState(s, x - 1, 0, 0), count = 0;
                                for (int z = x + 1; z <= n; z++)
                                {
                                    count += getState(s, z) == 2;
                                    count -= getState(s, z) == 1;
                                    if (count > 0)
                                    {
                                        S = setState(S, z, 1);
                                        break;
                                    }
                                }
                                //clog << "pre : "; printState(s, n);
                                //clog << "aft : "; printState(S, n);
                                f[u][x][S] += f[u][x - 1][s];
                            }
                        }
                        else if (l || r)
                        {
                            f[u][x][setState(s, x - 1, l | r, 0)] += f[u][x - 1][s];
                            f[u][x][setState(s, x - 1, 0, l | r)] += f[u][x - 1][s];
                            //clog << "l || r = " <<  (l | r) << endl;
                            //clog << "aft : "; printState(setState(s, x - 1, l || r, 0), n);
                            //clog << "aft : "; printState(setState(s, x - 1, 0, l || r), n);
                        }
                        else 
                        {
                            f[u][x][setState(s, x - 1, 1, 2)] += f[u][x - 1][s];
                        }
                    }
            }
        }
        printState(setState(0, n - 1, 1, 2), n);
        int ans = f[n & 1][n - 1][setState(0, n - 1, 1, 2)];
        fout << ans << endl;
    }

    return 0;
}