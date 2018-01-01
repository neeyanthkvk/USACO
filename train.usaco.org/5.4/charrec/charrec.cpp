/*
  PROG: charrec
  LANG: C++
*/

#include <fstream>
#include <limits>

using namespace std;
enum Corruption {Missing, None, Duplicated};
const int NUM_CHARS = 27, LENGTH = 20, NUM_CORRUPTIONS = 3,
  INFINITY = numeric_limits<int>::max();
const string CHARACTERS = " abcdefghijklmnopqrstuvwxyz";
string **font;
string *input;
int N, *num_corruptions;
char *guess;
Corruption *type;
int ***differences;

/* The number of lines for each type of line corruption. */
int size(Corruption corruption) {
  int s = LENGTH;
  if (corruption == Missing)
    s--;
  else if (corruption == Duplicated)
    s++;
  return s;
}

void find_best_char(int final_line, Corruption corruption,
                    int corrupted_line = -1) {
  if ((corruption == None && final_line < LENGTH - 1) ||
      (corruption == Duplicated && final_line < LENGTH))
    return;
  int previous_final_line = final_line - size(corruption);
  int previous_corruptions = 0;
  if (previous_final_line >= 0) {
    if (guess[previous_final_line] == '?')
      return;
    previous_corruptions = num_corruptions[previous_final_line];
  }
  for (int character = 0; character < NUM_CHARS; character++) {
    int corruptions = 0;
    int max_corruptions = 0;
    for (int line = 0, input_line = previous_final_line + 1;
         line < LENGTH; line++, input_line++) {
      // take care of missing and duplicated line cases
      if (corruption == Missing && line == corrupted_line) {
        input_line--;
        continue;
      }
      // check if we are visiting corrupted_line + 1 for the first time
      if (corruption == Duplicated && line == corrupted_line + 1 &&
          input_line - previous_final_line - 1 == corrupted_line + 1)
        line--;

      // caching for differences between lines
      if (differences[input_line][character][line] == -1) {
        differences[input_line][character][line] = 0;
        for (int column = 0; column < LENGTH; column++)
          if (input[input_line][column] != font[character][line][column])
            differences[input_line][character][line]++;
      }
      corruptions += differences[input_line][character][line];

      // we keep track of the bigger of the two difference numbers and subtract
      // it instead of only adding the smaller one
      if (corruption == Duplicated && line == corrupted_line &&
          differences[input_line][character][line] > max_corruptions)
        max_corruptions = differences[input_line][character][line];
    }
    corruptions -= max_corruptions;
    int total_corruptions = corruptions + previous_corruptions;
    if (total_corruptions < num_corruptions[final_line]) {
      num_corruptions[final_line] = total_corruptions;
      guess[final_line] = CHARACTERS[character];
      type[final_line] = corruption;
    }
  }
}

/* Recursively construct the final answer based on the DP arrays. */
string construct_string(int i) {
  if (i < LENGTH - 2)
    return "";
  return construct_string(i - size(type[i])) + guess[i];
}

int main() {
  // read into font[][]
  font = new string*[NUM_CHARS];
  ifstream font_file("font.in");
  font_file >> N;
  for (int i = 0; i < NUM_CHARS; i++) {
    font[i] = new string[LENGTH];
    for (int j = 0; j < LENGTH; j++)
      font_file >> font[i][j];
  }
  font_file.close();

  // read into input[] and N
  ifstream fin("charrec.in");
  fin >> N;
  input = new string[N];
  for (int i = 0; i < N; i++)
    fin >> input[i];
  fin.close();

  // fill in the arrays with default values
  num_corruptions = new int[N];
  guess = new char[N];
  type = new Corruption[N];
  differences = new int**[N];
  for (int i = 0; i < N; i++) {
    num_corruptions[i] = INFINITY;
    guess[i] = '?';
    type[i] = None;
    differences[i] = new int*[NUM_CHARS];
    for (int j = 0; j < NUM_CHARS; j++) {
      differences[i][j] = new int[LENGTH];
      for (int k = 0; k < LENGTH; k++)
        differences[i][j][k] = -1;
    }
  }

  for (int line = LENGTH - 2; line < N; line++) {
    find_best_char(line, None);
    for (int corrupted_line = 0; corrupted_line < LENGTH; corrupted_line++) {
      find_best_char(line, Missing, corrupted_line);
      find_best_char(line, Duplicated, corrupted_line);
    }
  }
  ofstream fout("charrec.out");
  fout << construct_string(N - 1) << endl;
  fout.close();
}