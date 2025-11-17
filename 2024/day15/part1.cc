#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> &operator+=(pair<int, int> &lhs, pair<int, int> rhs) {
  lhs.first += rhs.first;
  lhs.second += rhs.second;
  return lhs;
}

int main() {
  ifstream file("input.txt");

  vector<string> grid;
  string moves;
  bool foundBlankLine = 0;

  string line;
  while (getline(file, line)) {
    if (line.empty()) {
      foundBlankLine = 1;
      continue;
    }
    if (!foundBlankLine) {
      grid.push_back(line);
    } else {
      moves += line;
    }
  }
  file.close();

  auto getMove = [](char &c) {
    if (c == 'v')
      return make_pair(1, 0);
    if (c == '<')
      return make_pair(0, -1);
    if (c == '>')
      return make_pair(0, 1);
    return make_pair(-1, 0);
  };

  pair<int, int> me;
  for (int r = 0; r < grid.size(); r++) {
    for (int c = 0; c < grid[0].size(); c++) {
      if (grid[r][c] == '@') {
        me = {r, c};
      }
    }
  }

  for (char &c : moves) {
    pair<int, int> direction = getMove(c);
    pair<int, int> pos = me;
    bool emptySpace = 0;
    while (true) {
      pos += direction;
      if (grid[pos.first][pos.second] == '#')
        break;

      if (grid[pos.first][pos.second] == '.') {
        emptySpace = 1;
        break;
      }
    }

    if (!emptySpace)
      continue;

    while (pos.first != me.first || pos.second != me.second) {
      int prevR = pos.first - direction.first;
      int prevC = pos.second - direction.second;

      grid[pos.first][pos.second] = grid[prevR][prevC];
      pos = {prevR, prevC};
    }

    grid[me.first][me.second] = '.';
    me += direction;
  }

  for (string s : grid) {
    cout << s << endl;
  }

  int total = 0;

  for (int r = 0; r < grid.size(); r++) {
    for (int c = 0; c < grid[0].size(); c++) {
      if (grid[r][c] == 'O') {
        total += 100 * r + c;
      }
    }
  }

  cout << total;

  return 0;
}
