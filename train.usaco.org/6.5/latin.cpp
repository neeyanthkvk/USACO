/*
LANG: C++11
TASK: latin
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <functional>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    ifstream fin("latin.in");
    ofstream fout("latin.out");

    int n;
    while (fin >> n)
    {
        vector<int> row, col;
        row.resize(n + 1, 0);
        col.resize(n + 1, 0);

        long long ans = 0;
        int all = ((1 << (n + 1)) - 2);
        int id;
        vector<int> line_two(n + 1);
    
        unordered_map<string, int> str_id;
        unordered_map<int, int> id_count;

        auto get_string_id = [&]() -> string
        {
            vector<bool> vis(n + 1, false);
            int u = 1, len = 0;
            string ret = "";

            for (int v = 1; v <= n; v++)
                if (!vis[v])
                {
                    u = v;
                    len = 0;
                    while (!vis[u])
                    {
                        len += 1;
                        vis[u] = true;
                        u = line_two[u];
                    }
                    ret += to_string(len);
                }
            sort(ret.begin(), ret.end());
            return ret;
        };

        function<void(int, int)> dfs = [&](int x, int y)
        {
            if (y == n + 1)
            {
                x += 1;
                y = 2;
            }

            if (x == n)
            {
                id_count[id] += 1;
                ans += 1;
                return ;
            }

            int msk = all ^ (row[x] | col[y]); 

            //clog << "x = " << x << ", y = " << y << endl;
            //for (int i = 0; i <= n + 1; i++) clog << ((msk >> i) & 1);  clog << endl;
            
            for (int val = msk & (-msk); val; val = msk & (-msk))
            {
                if (x == 2)
                {
                    for (int idx = 1; idx <= n; idx++)
                        if (val == (1 << idx))
                        {
                            //clog << row[x] << ", " << col[y] << ", msk : " << msk << endl;
                            line_two[y] = idx;
                            //clog << "idx = " << idx << ", val = " << val << endl;
                        }

                    if (y == n)
                    {
                        string str = get_string_id();
                        //clog << "line_two: ";
                        //for (int i = 1; i <= n; i++) clog << line_two[i] << ", "; clog << endl;
                        //clog << "id = " << str << endl;
                        if (str_id.count(str))
                        {
                            //clog << "past = " << id_count[str_id[str]] << endl;
                            ans += id_count[str_id[str]];
                            return ;
                        }
                        else
                        {
                            id = str_id.size();
                            //clog << "str = " << str << ", id = " << id << endl;
                            str_id[str] = id;
                            id_count[id] = 0;
                        }
                    }

                }

                row[x] ^= val;
                col[y] ^= val;

                dfs(x, y + 1);

                col[y] ^= val;
                row[x] ^= val;
                msk ^= val;
            }
        };

        for (int x = 1; x <= 1; x++)
            for (int y = 1; y <= n; y++)
            {
                row[x] ^= 1 << y, col[y] ^= 1 << y;
                if (y > 1)
                    row[y] ^= 1 << y, col[x] ^= 1 << y;
            }

        line_two[1] = 2;
        dfs(2, 2);

        for (int i = 1; i < n; i++) ans *= i;

        clog << ans << endl;
        fout << ans << endl;
    }

    return 0;
}