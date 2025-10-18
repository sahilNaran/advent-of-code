#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("sample.txt");

  vector<string> grid;
  string line;
  while (getline(file, line)) {
    grid.push_back(line);
  }
  int H = grid.size();
  int W = grid[0].size();

  cout << "height: " << H << " width: " << W;

  file.close();
  return 0;
}
