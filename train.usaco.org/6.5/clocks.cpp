/*
PROG: clocks
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8

int clocks[9];
int tmp[9];
vector<int> current;
vector<int> best;

bool needed_answer() {
  for (int i = 0; i < 9; i++)
    if (tmp[i] != 12)
      return false;

  return true;
}

void update_clocks(int pos) {
  tmp[pos] = tmp[pos] + 3 > 12 ? (tmp[pos] + 3) % 12 : tmp[pos] + 3;
}

void make_move(int move) {
  switch(move) {
    case 1:
      update_clocks(A);
      update_clocks(B);
      update_clocks(D);
      update_clocks(E);
      break;
    case 2:
      update_clocks(A);
      update_clocks(B);
      update_clocks(C);
      break;
    case 3:
      update_clocks(B);
      update_clocks(C);
      update_clocks(E);
      update_clocks(F);
      break;
    case 4:
      update_clocks(A);
      update_clocks(D);
      update_clocks(G);
      break;
    case 5:
      update_clocks(B);
      update_clocks(D);
      update_clocks(E);
      update_clocks(F);
      update_clocks(H);
      break;
    case 6:
      update_clocks(C);
      update_clocks(F);
      update_clocks(I);
      break;
    case 7:
      update_clocks(D);
      update_clocks(E);
      update_clocks(G);
      update_clocks(H);
      break;
    case 8:
      update_clocks(G);
      update_clocks(H);
      update_clocks(I);
      break;
    case 9:
      update_clocks(E);
      update_clocks(F);
      update_clocks(H);
      update_clocks(I);
      break;
  }
}

void transform() {
  for (int i = 0, sz = current.size(); i < sz; i++) {
    make_move(current[i]);
  }
}

bool better_solution() {
  for (int i = 0, sz = current.size(); i < sz; i++) {
    if (current[i] > best[i])
      return false;
  }

  return true;
}

void solve(int depth) {
  if (depth == 10) {

    for (int i = 0; i < 9; i++)
      tmp[i] = clocks[i];

    transform();

    if (needed_answer()) {
      if (best.size() == 0) {
        for (int i = 0, sz = current.size(); i < sz; i++)
          best.push_back(current[i]);
      } else if (current.size() < best.size()) {
        best.clear();
        for (int i = 0, sz = current.size(); i < sz; i++)
          best.push_back(current[i]);
      } else if (current.size() == best.size()) {
        if (better_solution()) {
          best.clear();
          for (int i = 0, sz = current.size(); i < sz; i++)
            best.push_back(current[i]);
        }
      }
    }

    return;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < i; j++)
      current.push_back(depth);

    solve(depth + 1);

    for (int j = 0; j < i; j++)
      current.pop_back();
  }
}

int main() {
  ofstream fout("clocks.out");
  ifstream fin("clocks.in");

  for (int i = 0; i < 9; i++) {
    fin >> clocks[i];
  }

  for (int i = 0; i < 9; i++)
    tmp[i] = clocks[i];

  solve(1);

  for (int i = 0, sz = best.size(); i < sz; i++) {
    if (i > 0)
      fout << " ";
    fout << best[i];
  }
  fout << endl;

  return 0;
}