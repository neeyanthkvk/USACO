/*
  PROG: tour
  LANG: C++
*/

#include <fstream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int find_index(string name, int N, string names[]) {
  for (int i = 0; i < N; i++) if (names[i] == name) return i;
  return -1;
}

void search(int pos1, int pos2, int moves, int N, vector<bool> matrix[],
            int &best, map<pair<int, int>, int> &record) {
  if (pos1 == N - 1) {
    if (moves > best) best = moves;
    return;
  }

  // pruning the branch if it cannot be as good as the best found result
  if (moves + N - pos1 - 1 <= best) return;
  // pruning the branch if the path we took to get to this state is suboptimal
  pair<int, int> state(pos1, pos2);
  map<pair<int, int>, int>::iterator it = record.find(state);
  if (it != record.end()) {
    if (moves < it->second) return;
    it->second = moves;
  } else {
    record[state] = moves;
  }

  for (int i = pos1 + 1; i < N; i++) {
    if ((i != pos2 || i == N - 1) && matrix[pos1][i]) {
      if (i < pos2) {
        search(i, pos2, moves + 1, N, matrix, best, record);
      } else {
        search(pos2, i, moves + 1, N, matrix, best, record);        
      }
    }
  }
}

int main() {
  int N, V;
  ifstream fin("tour.in");
  fin >> N >> V;
  string name[N];
  for (int i = 0; i < N; i++) fin >> name[i];
  vector<bool> matrix[N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) matrix[i].push_back(false);
  for (int i = 0; i < V; i++) {
    string name1, name2;
    fin >> name1 >> name2;
    int j = find_index(name1, N, name);
    int k = find_index(name2, N, name);
    matrix[j][k] = matrix[k][j] = true;
  }
  fin.close();
  int best = 1;
  map<pair<int, int>, int> record;
  search(0, 0, 0, N, matrix, best, record);
  ofstream fout("tour.out");
  fout << best << endl;
  fout.close();
  return 0;
}