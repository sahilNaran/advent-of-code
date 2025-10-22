#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

pair<int, int> operator+(const pair<int, int> a, const pair<int, int> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

int search(vector<string> &grid, pair<int, int> me, pair<int, int> direction,
           int current) {

  pair<int, int> newPos = me + direction;
  int H = grid.size();
  int W = grid[0].size();

  if (newPos.first < 0 || newPos.first >= H || newPos.second < 0 ||
      newPos.second >= W) {
    return 0;
  }

  int nextLevel = current + 1;
  if (grid[newPos.first][newPos.second] != (nextLevel + '0')) {
    return 0;
  }

  if (nextLevel == 9) {
    return 1;
  }

  return transform_reduce(directions.begin(), directions.end(), 0, plus<>(),
                          [&grid, &newPos, &nextLevel](const auto &direction) {
                            return search(grid, newPos, direction, nextLevel);
                          });
}

int main() {
  ifstream file("input.txt");

  vector<string> grid;
  string line;
  while (getline(file, line)) {
    grid.push_back(line);
  }
  file.close();

  int H = grid.size();
  int W = grid[0].size();

  vector<pair<int, int>> locations;
  for (size_t r = 0; r < H; r++) {
    for (size_t c = 0; c < W; c++) {
      if (grid[r][c] == '0') {
        locations.push_back(make_pair(r, c));
      }
    }
  }

  int ans = 0;
  for (auto &loc : locations) {
    ans += transform_reduce(directions.begin(), directions.end(), 0, plus<>(),
                            [&grid, &loc](const auto &direction) {
                              return search(grid, loc, direction, 0);
                            });
  }

  cout << ans;

  return 0;
}
