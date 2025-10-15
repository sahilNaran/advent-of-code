#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");

  vector<string> allLines;
  string line;
  while (getline(file, line)) {
    allLines.push_back(line);
  }

  int rows = allLines.size();
  int cols = allLines[0].size();

  auto hasX = [rows, cols, allLines](int r, int c) {
    if (r - 1 < 0 || c - 1 < 0)
      return 0;
    if (r - 1 < 0 || c + 1 >= cols)
      return 0;
    if (r + 1 >= rows || c - 1 < 0)
      return 0;
    if (r + 1 >= rows || c + 1 >= cols)
      return 0;
    if (allLines[r][c] == 'A') {
      if (((allLines[r - 1][c - 1] == 'M' && allLines[r + 1][c + 1] == 'S') ||
           (allLines[r - 1][c - 1] == 'S' && allLines[r + 1][c + 1] == 'M'))

          &&
          ((allLines[r - 1][c + 1] == 'M' && allLines[r + 1][c - 1] == 'S') ||
           (allLines[r - 1][c + 1] == 'S' && allLines[r + 1][c - 1] == 'M'))) {
        return 1;
      }
    }
    return 0;
  };

  int count = 0;
  for (size_t r = 0; r < rows; r++) {
    for (size_t c = 0; c < cols; c++) {
      if (hasX(r, c))
        count++;
    }
  }
  cout << count;
  file.close();
  return 0;
}
