/*
  PROG: twofive
  LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <vector>

using namespace std;
const int EDGE = 5;
const int SIZE = EDGE * EDGE;
const char EMPTY = '_';
const char FIRST_LETTER = 'A';
const char LAST_LETTER = FIRST_LETTER + SIZE - 1;


map<vector<int>, int> completions;


bool possible(int index, vector<char> &grid) {

  for (int i = index - index % EDGE; i < index; ++i)
    if (grid[i] >= grid[index])
      return false;

  for (int i = index - EDGE; i >= 0; i -= EDGE)
    if (grid[i] >= grid[index])
      return false;

  for (int i = 0; i < index; i++)
    if (grid[i] == grid[index])
      return false;

  return true;
}


vector<int> signature(vector<char> &grid) {
  vector<int> t(EDGE, 0);
  for (int i = 0; i < SIZE; ++i)
    if (grid[i] != EMPTY)
      ++t[i / 5];
  return t;
}

void generate_signatures(vector<int> signature,
                         vector<vector<int> > &all_signatures) {
  int size = signature.size();
  if (size == EDGE) {
    all_signatures.push_back(signature);
    return;
  }
  for (int i = 0; i <= signature[size - 1]; ++i) {
    vector<int> next_signature = signature;
    next_signature.push_back(i);
    generate_signatures(next_signature, all_signatures);
  }
}


int compare_sums(vector<int> a, vector<int> b) {
  int s1 = 0, s2 = 0;
  for (int i = 0; i < EDGE; i++) {
    s1 += a[i];
    s2 += b[i];
  }
  return s1 > s2;
}

map<vector<char>, int> memo;
int count_completions(vector<char> grid) {

  map<vector<char>, int>::iterator it = memo.find(grid);
  if (it != memo.end())
    return it->second;

  set<char> letters;
  for (int i = 0; i < SIZE; ++i)
    if (grid[i] != EMPTY)
      letters.insert(grid[i]);
  char letter = FIRST_LETTER;
  for (; letters.find(letter) != letters.end() && letter <= LAST_LETTER;
       ++letter);


  if (letter >= *(letters.rbegin())) {
    memo[grid] = completions[signature(grid)];
    return memo[grid];
  }


  int sum = 0;
  for (int i = 0; i < SIZE; ++i) {
    if (grid[i] == EMPTY) {
      grid[i] = letter;
      if (possible(i, grid))
        sum += count_completions(grid);
      grid[i] = EMPTY;
    }
  }
  return memo[grid] = sum;
}

int main() {

  vector<vector<int> > signatures;
  for (int i = 0; i <= EDGE; ++i)
    generate_signatures(vector<int>(1, i), signatures);
  sort(signatures.begin(), signatures.end(), compare_sums);


  completions[signatures[0]] = 1;
  for (int i = 1; i < signatures.size(); ++i) {
    completions[signatures[i]] = 0;
    for (int j = 0; j < EDGE; ++j) {
      if (signatures[i][j] < EDGE && (j == 0 || signatures[i][j] <
                                      signatures[i][j - 1])) {

        vector<int> successor = signatures[i];
        ++successor[j];
        completions[signatures[i]] += completions[successor];
      }
    }
  }

  int skipped = 0; 
  vector<char> grid(SIZE, EMPTY);
  char mode;
  ifstream fin("twofive.in");
  fin >> mode;
  ofstream fout("twofive.out");
  if (mode == 'N') {
    int M;
    fin >> M;
    for (int i = 0; i < SIZE; ++i) {
      for (grid[i] = FIRST_LETTER; grid[i] <= LAST_LETTER; ++grid[i]) {
        if (possible(i, grid)) {
          int num_ways = count_completions(grid);
          if (skipped + num_ways >= M)
            break;
          skipped += num_ways;
        }
      }
    }
    for (int i = 0; i < 25; ++i)
      fout << grid[i];
  } else {
    string target;
    fin >> target;
    for (int i = 0; i < SIZE; ++i)
      for (grid[i] = 'A'; grid[i] < target[i]; ++grid[i])
        if (possible(i, grid))
          skipped += count_completions(grid);
    fout << skipped + 1;
  }
  fin.close();
  fout << endl;
  fout.close();
}