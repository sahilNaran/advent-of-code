#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> operator+(const pair<int, int> x, const pair<int, int> y) {
  return make_pair(x.first + y.first, x.second + y.second);
}

int main() {
  ifstream file("input.txt");

  pair<int, int> me{-1, -1};
  vector<pair<int, int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<string> lines;
  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  int H = lines.size();
  int W = lines[0].size();

  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (lines[r][c] == '^') {
        me = make_pair(r, c);
        lines[r][c] = '.';
      }
    }
  }

  int dirs = 0;
  vector<vector<bool>> grid(H, vector<bool>(W));
  while (true) {
    grid[me.first][me.second] = 1;
    pair<int, int> nextMe = me + dir[dirs];
    if (nextMe.second < 0 || nextMe.second >= W || nextMe.first < 0 ||
        nextMe.first >= H) {
      break;
    }
    if (lines[nextMe.first][nextMe.second] == '.') {
      me = me + dir[dirs];
    } else {
      dirs = (dirs + 1) % 4;
    }
  }
  int ans = 0;
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (grid[r][c]) {
        ans++;
      }
    }
  }

  cout << ans;
  file.close();
  return 0;
}
