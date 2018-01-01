/*
  ID: neeyant2
  PROG: snail
  LANG: C++
*/

#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

void mark_path(int x, int y, int dx, int dy, int steps, char c,
               string square[]) {
  for (; steps > 0; steps--, x -= dx, y -= dy) square[x][y] = c;
}

int dfs(int x, int y, int dx, int dy, int N, string square[]) {
  int steps = 0;
  for (x += dx, y += dy; x >= 0 && x < N && y >= 0 && y < N &&
         square[x][y] != '#'; x += dx, y += dy, steps++)
    if (square[x][y] == '-') return steps;
  if (steps == 0) return 0;
  x -= dx;
  y -= dy;
  mark_path(x, y, dx, dy, steps, '-', square);
  int m = max(dfs(x, y, dy, dx, N, square), dfs(x, y, -dy, -dx, N, square));
  mark_path(x, y, dx, dy, steps, '.', square);
  return steps + m;
}

int main() {
  int N, B;
  ifstream fin("snail.in");
  fin >> N >> B;
  string square[N];
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) square[i] += '.';
  for (int k = 0; k < B; k++) {
    string location;
    fin >> location;
    square[atoi(location.substr(1).c_str()) - 1][location[0] - 'A'] = '#';
  }
  fin.close();
  square[0][0] = '-';
  ofstream fout("snail.out");
  fout << max(dfs(0, 0, 1, 0, N, square), dfs(0, 0, 0, 1, N, square)) + 1
       << endl;
  fout.close();
  return 0;
}
