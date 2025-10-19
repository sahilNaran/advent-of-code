#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

pair<int, int> operator+(const pair<int, int> a, const pair<int, int> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

void search(vector<string> &grid, pair<int, int> me, int current,
            set<pair<int, int>> &endpoints) {

  if (current == 9) {
    endpoints.insert(me);
    return;
  }

  int H = grid.size();
  int W = grid[0].size();

  for (const auto &direction : directions) {
    pair<int, int> newPos = me + direction;

    if (newPos.first < 0 || newPos.first >= H || newPos.second < 0 ||
        newPos.second >= W) {
      continue;
    }

    int nextLevel = current + 1;
    if (grid[newPos.first][newPos.second] == (nextLevel + '0')) {
      search(grid, newPos, nextLevel, endpoints);
    }
  }
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
    set<pair<int, int>> endpoints;
    search(grid, loc, 0, endpoints);
    ans += endpoints.size();
  }

  cout << ans;

  return 0;
}
