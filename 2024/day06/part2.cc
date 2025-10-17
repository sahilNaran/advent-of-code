#include <fstream>
#include <iostream>
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

  pair<int, int> baseMe{-1, -1};
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
        baseMe = make_pair(r, c);
        lines[r][c] = '.';
      }
    }
  }

  auto placesToPutObect = [&]() {
    int dirs = 0;
    pair<int, int> me = baseMe;
    set<pair<int, int>> path;
    while (true) {
      path.insert(make_pair(me.first, me.second));
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
    return path;
  };

  auto solve = [&]() {
    int dirs = 0;
    pair<int, int> me = baseMe;
    vector<vector<vector<bool>>> grid(
        H, vector<vector<bool>>(W, vector<bool>(4, false)));
    while (true) {
      if (grid[me.first][me.second][dirs]) {
        return 1;
      }
      grid[me.first][me.second][dirs] = true;

      pair<int, int> nextMe = me + dir[dirs];
      if (nextMe.second < 0 || nextMe.second >= W || nextMe.first < 0 ||
          nextMe.first >= H) {
        return 0;
      }
      if (lines[nextMe.first][nextMe.second] == '.') {
        me = me + dir[dirs];
      } else {
        dirs = (dirs + 1) % 4;
      }
    }
    return 0;
  };

  int ans = 0;
  set<pair<int, int>> path = placesToPutObect();
  for (pair<int, int> i : path) {
    int r = i.first;
    int c = i.second;
    if (lines[r][c] == '#' || (r == baseMe.first && c == baseMe.second)) {
      continue;
    }
    char original = lines[r][c];
    lines[r][c] = '#';
    if (solve()) {
      ans++;
    }
    lines[r][c] = original;
  }

  cout << ans;
  file.close();
  return 0;
}
