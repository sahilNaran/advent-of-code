#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

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

  auto canPlace = [&](int &r, int &c) {
    if (r >= 0 && r < H && c >= 0 && c < W) {
      if (grid[r][c] != '#') {
        return 1;
      }
    }
    return 0;
  };

  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (grid[r][c] != '.') {
        antennas[grid[r][c]].push_back(make_pair(r, c));
      }
    }
  }

  int ans = 0;
  for (auto &[key, value] : antennas) {
    for (int i = 0; i < value.size(); i++) {
      for (int j = i + 1; j < value.size(); j++) {

        pair<int, int> a = value[i];
        pair<int, int> b = value[j];

        int difX = (a.first - b.first);
        int difY = (a.second - b.second);

        int x1 = a.first + difX;
        int y1 = a.second + difY;

        int x2 = b.first - difX;
        int y2 = b.second - difY;

        // cout << "Key: " << key << " difX: " << difX << " difY: " << difY
        //      << endl;
        // cout << "Key: " << key << " x1: " << x1 << " y1: " << y1 << endl;
        // cout << "Key: " << key << " x2: " << x2 << " y2: " << y2 << endl;

        if (canPlace(x1, y1)) {
          grid[x1][y1] = '#';
          ans++;
        }
        if (canPlace(x2, y2)) {
          grid[x2][y2] = '#';
          ans++;
        }
      }
    }
  }

  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      cout << grid[r][c];
    }
    cout << endl;
  }

  cout << ans;

  file.close();
  return 0;
}
