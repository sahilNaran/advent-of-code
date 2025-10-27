#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void search(int H, int W, int r, int c, vector<string> &grid, char item,
            long long &area, vector<vector<bool>> &seen,
            vector<pair<int, int>> &region) {

  if (r < 0 || r >= H || c < 0 || c >= W || grid[r][c] != item) {
    return;
  }

  if (seen[r][c]) {
    return;
  }

  seen[r][c] = 1;
  area++;
  region.push_back({r, c});

  search(H, W, r + 1, c, grid, item, area, seen, region);
  search(H, W, r - 1, c, grid, item, area, seen, region);
  search(H, W, r, c + 1, grid, item, area, seen, region);
  search(H, W, r, c - 1, grid, item, area, seen, region);
}

int corners(vector<pair<int, int>> &region, vector<string> &grid, char item) {
  int count = 0;
  int H = grid.size();
  int W = grid[0].size();

  for (auto [r, c] : region) {
    bool up = (r > 0 && grid[r - 1][c] == item);
    bool down = (r < H - 1 && grid[r + 1][c] == item);
    bool left = (c > 0 && grid[r][c - 1] == item);
    bool right = (c < W - 1 && grid[r][c + 1] == item);

    bool upLeft = (r > 0 && c > 0 && grid[r - 1][c - 1] == item);
    bool upRight = (r > 0 && c < W - 1 && grid[r - 1][c + 1] == item);
    bool downLeft = (r < H - 1 && c > 0 && grid[r + 1][c - 1] == item);
    bool downRight = (r < H - 1 && c < W - 1 && grid[r + 1][c + 1] == item);

    if (!up && !left)
      count++;
    if (!up && !right)
      count++;
    if (!down && !left)
      count++;
    if (!down && !right)
      count++;

    if (up && left && !upLeft)
      count++;
    if (up && right && !upRight)
      count++;

    if (down && left && !downLeft)
      count++;
    if (down && right && !downRight)
      count++;
  }

  return count;
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
  long long totalCost = 0;

  vector<vector<bool>> seen;
  seen.assign(H, vector<bool>(W, false));

  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (!seen[r][c]) {
        long long area = 0;
        vector<pair<int, int>> region;

        search(H, W, r, c, grid, grid[r][c], area, seen, region);

        int numCorners = corners(region, grid, grid[r][c]);
        totalCost += area * numCorners;
      }
    }
  }

  cout << totalCost;
  return 0;
}
