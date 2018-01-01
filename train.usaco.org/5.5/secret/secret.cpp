/*
  PROG: hidden
  LANG: C++
*/

#include <fstream>
#include <list>

using namespace std;

int main() {
  int L;
  string S = "";
  ifstream fin("hidden.in");
  fin >> L;
  while (fin.good()) {
    string line;
    fin >> line;
    S += line;
  }
  fin.close();

  list<int> starting_indices;
  char min_letter = 'z';
  for (int i = 0; i < L; ++i) {
    if (S[i] < min_letter) {
      min_letter = S[i];
      starting_indices.clear();
    }
    if (S[i] == min_letter)
      starting_indices.push_back(i);
  }

  for (int length = 1; starting_indices.size() > 1; length++) {
    for (list<int>::iterator it2 = starting_indices.begin(), it1 = it2++;
         it2 != starting_indices.end(); it1 = it2++) {
      if (*it2 == *it1 + length) {
        starting_indices.erase(it2++);
        if (it2 == starting_indices.end())
          break;
      }
    }

    char min_successor = 'z';
    for (list<int>::iterator it = starting_indices.begin();
         it != starting_indices.end(); ++it) {
      int index = (*it + length) % L;
      if (S[index] < min_successor)
        min_successor = S[index];
    }

    for (list<int>::iterator it = starting_indices.begin();
         it != starting_indices.end();) {
      if (S[(*it + length) % L] != min_successor)
        starting_indices.erase(it++);
      else
        ++it;
    }
  }
  
  ofstream fout("hidden.out");
  fout << starting_indices.front() << endl;
  fout.close();
}