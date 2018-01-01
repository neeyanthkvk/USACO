/*
  PROG: window
  LANG: C++
*/

#include <algorithm>
#include <cstdio>
#include <list>
#include <utility>

using namespace std;
typedef pair<int, int> Range;

struct Window {
  char I;
  int x, y, X, Y;
};

void move(char I, list<Window>::iterator to, list<Window> &windows) {
  for (list<Window>::iterator from = windows.begin(); from != windows.end();
       from++) {
    if (from->I == I) {
      windows.splice(to, windows, from);
      break;
    }
  }
}

int main() {
  FILE *fin = fopen("window.in", "r");
  FILE *fout = fopen("window.out", "w");
  list<Window> windows;
  while (!feof(fin)) {
    char operation = fgetc(fin);
    char I;
    switch (operation) {
      case 'w':
      int x, y, X, Y;
      fscanf(fin, "(%c,%d,%d,%d,%d)\n", &I, &x, &y, &X, &Y);
      Window window;
      window.I = I;
      if (x <= X) {
        window.x = x;
        window.X = X;
      } else {
        window.x = X;
        window.X = x;
      }
      if (y <= Y) {
        window.y = y;
        window.Y = Y;
      } else {
        window.y = Y;
        window.Y = y;
      }
      windows.push_back(window);
      continue;
    default:
      fscanf(fin, "(%c)\n", &I);
    }
    switch (operation) {
    case 't':
      move(I, windows.end(), windows);
      break;
    case 'b':
      move(I, windows.begin(), windows);
      break;
    case 'd':
      for (list<Window>::iterator it = windows.begin(); it != windows.end();
           it++) {
        if (it->I == I) {
          windows.erase(it);
          break;
        }
      }
      break;
    default:
      for (list<Window>::iterator it = windows.begin(); it != windows.end();
           it++) {
        if (it->I == I) {
          list<Range> visible[it->X - it->x];
          for (int i = 0; i < it->X - it->x; i++)
            visible[i].push_back(make_pair(it->y, it->Y));
          list<Window>::iterator it2 = it;
          it2++;
          for (; it2 != windows.end(); it2++) {
            for (int i = max(it->x, it2->x) - it->x;
                 i < min(it->X, it2->X) - it->x; i++) {
              for (list<Range>::iterator it3 = visible[i].begin();
                   it3 != visible[i].end();) {
                if (it3->first < it2->y) {
                  if (it3->second > it2->Y) {
                    visible[i].insert(it3, make_pair(it3->first, it2->y));
                    it3->first = it2->Y;
                  } else if (it3->second > it2->y) {
                    it3->second = it2->y;
                  }
                } else if (it3->first < it2->Y) {
                  if (it3->second > it2->Y) {
                    it3->first = it2->Y;
                  } else {
                    it3 = visible[i].erase(it3);
                    continue;
                  }
                }
                it3++;
              }
            }
          }
          int visible_area = 0;
          for (int i = 0; i < it->X - it->x; i++) {
            for (list<Range>::iterator it3 = visible[i].begin();
                 it3 != visible[i].end(); it3++)
              visible_area += it3->second - it3->first;
          }
          fprintf(fout, "%.3f\n", 100.0 * visible_area /
                  ((it->X - it->x) * (it->Y - it->y)));
          break;
        }
      }
    }
  }
  fclose(fin);
  fclose(fout);
  return 0;
}