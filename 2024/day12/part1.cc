#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void search(int H, int W, int r, int c, vector<string> &grid, char item,
            long long &area, long long &perimeter, vector<vector<bool>> &seen) {

  if (r < 0 || r >= H || c < 0 || c >= W || grid[r][c] != item) {
    perimeter++;
    return;
  }

  if (seen[r][c]) {
    return;
  }

  seen[r][c] = 1;
  area++;

  search(H, W, r + 1, c, grid, item, area, perimeter, seen);
  search(H, W, r - 1, c, grid, item, area, perimeter, seen);
  search(H, W, r, c + 1, grid, item, area, perimeter, seen);
  search(H, W, r, c - 1, grid, item, area, perimeter, seen);
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
      long long area = 0;
      long long perimeter = 0;
      search(H, W, r, c, grid, grid[r][c], area, perimeter, seen);
      totalCost += area * perimeter;
    }
  }

  cout << totalCost;
  return 0;
}
