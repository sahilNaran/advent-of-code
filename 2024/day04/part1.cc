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

  auto hasRight = [cols, allLines](int r, int c) {
    if (c + 4 > cols)
      return 0;
    if (allLines[r].substr(c, 4) == "XMAS")
      return 1;
    return 0;
  };

  auto hasLeft = [cols, allLines](int r, int c) {
    if (c - 3 < 0)
      return 0;
    if (allLines[r][c] == 'X' && allLines[r][c - 1] == 'M' &&
        allLines[r][c - 2] == 'A' && allLines[r][c - 3] == 'S')
      return 1;
    return 0;
  };

  auto hasTop = [rows, allLines](int r, int c) {
    if (r - 3 < 0)
      return 0;
    if (allLines[r][c] == 'X' && allLines[r - 1][c] == 'M' &&
        allLines[r - 2][c] == 'A' && allLines[r - 3][c] == 'S')
      return 1;
    return 0;
  };

  auto hasBottom = [rows, allLines](int r, int c) {
    if (r + 4 > rows)
      return 0;
    if (allLines[r][c] == 'X' && allLines[r + 1][c] == 'M' &&
        allLines[r + 2][c] == 'A' && allLines[r + 3][c] == 'S')
      return 1;
    return 0;
  };

  auto hasTopRight = [rows, cols, allLines](int r, int c) {
    if (r - 3 < 0 || c + 4 > cols)
      return 0;
    if (allLines[r][c] == 'X' && allLines[r - 1][c + 1] == 'M' &&
        allLines[r - 2][c + 2] == 'A' && allLines[r - 3][c + 3] == 'S') {
      return 1;
    }
    return 0;
  };

  auto hasBottomRight = [rows, cols, allLines](int r, int c) {
    if (r + 4 > rows || c + 4 > cols)
      return 0;
    if (allLines[r][c] == 'X' && allLines[r + 1][c + 1] == 'M' &&
        allLines[r + 2][c + 2] == 'A' && allLines[r + 3][c + 3] == 'S')
      return 1;
    return 0;
  };

  auto hasBottomLeft = [rows, cols, allLines](int r, int c) {
    if (r + 4 > rows || c - 3 < 0)
      return 0;
    if (allLines[r][c] == 'X' && allLines[r + 1][c - 1] == 'M' &&
        allLines[r + 2][c - 2] == 'A' && allLines[r + 3][c - 3] == 'S')
      return 1;
    return 0;
  };

  auto hasTopLeft = [rows, cols, allLines](int r, int c) {
    if (r - 3 < 0 || c - 3 < 0)
      return 0;
    if (allLines[r][c] == 'X' && allLines[r - 1][c - 1] == 'M' &&
        allLines[r - 2][c - 2] == 'A' && allLines[r - 3][c - 3] == 'S')
      return 1;
    return 0;
  };

  int count = 0;
  for (size_t r = 0; r < rows; r++) {
    for (size_t c = 0; c < cols; c++) {
      if (hasRight(r, c))
        count++;
      if (hasLeft(r, c))
        count++;
      if (hasTop(r, c))
        count++;
      if (hasBottom(r, c))
        count++;
      if (hasTopRight(r, c))
        count++;
      if (hasTopLeft(r, c))
        count++;
      if (hasBottomRight(r, c))
        count++;
      if (hasBottomLeft(r, c))
        count++;
    }
  }
  cout << count;
  file.close();
  return 0;
}
