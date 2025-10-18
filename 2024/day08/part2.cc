#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

bool place(vector<string> &grid, int x, int y, int &difX, int &difY, int &H,
           int &W, set<pair<int, int>> &antinodes, int dir) {
  int x1 = (dir == 0) ? x + difX : x - difX;
  int y1 = (dir == 0) ? y + difY : y - difY;

  if (x1 < 0 || y1 < 0 || x1 >= H || y1 >= W) {
    return 1;
  }

  antinodes.insert({x1, y1});
  grid[x1][y1] = '#';

  return place(grid, x1, y1, difX, difY, H, W, antinodes, dir);
};

int main() {
  ifstream file("input.txt");

  vector<string> grid;
  string line;
  while (getline(file, line)) {
    grid.push_back(line);
  }
  int H = grid.size();
  int W = grid[0].size();

  unordered_map<char, vector<pair<int, int>>> antennas;

  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (grid[r][c] != '.') {
        antennas[grid[r][c]].push_back(make_pair(r, c));
      }
    }
  }

  set<pair<int, int>> antinodes;

  for (auto &[key, value] : antennas) {
    if (value.size() >= 2) {
      for (auto &pos : value) {
        antinodes.insert(pos);
      }
    }
  }

  for (auto &[key, value] : antennas) {
    for (int i = 0; i < value.size(); i++) {
      for (int j = i + 1; j < value.size(); j++) {

        pair<int, int> a = value[i];
        pair<int, int> b = value[j];

        int difX = (a.first - b.first);
        int difY = (a.second - b.second);

        place(grid, a.first, a.second, difX, difY, H, W, antinodes, 0);
        place(grid, a.first, a.second, difX, difY, H, W, antinodes, 1);
      }
    }
  }

  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      cout << grid[r][c];
    }
    cout << endl;
  }

  cout << antinodes.size();

  file.close();
  return 0;
}
