#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");

  string line;
  int seconds = 100;
  int H = 103;
  int W = 101;

  vector<vector<int>> quadrant(2, vector<int>(2, 0));
  while (getline(file, line)) {
    int px, py, vx, vy;
    sscanf(line.c_str(), "p=%d,%d v=%d,%d", &px, &py, &vx, &vy);
    int newX = ((px + vx * seconds) % W + W) % W;
    int newY = ((py + vy * seconds) % H + H) % H;

    if (newX != W / 2 && newY != H / 2)
      quadrant[newX > W / 2][newY > H / 2]++;
  }

  cout << quadrant[0][0] * quadrant[0][1] * quadrant[1][0] * quadrant[1][1];
  file.close();
  return 0;
:
