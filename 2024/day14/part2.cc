#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");

  string line;
  int H = 103;
  int W = 101;

  vector<pair<pair<int, int>, pair<int, int>>> robotsAndPositions;
  while (getline(file, line)) {
    int px, py, vx, vy;
    sscanf(line.c_str(), "p=%d,%d v=%d,%d", &px, &py, &vx, &vy);

    robotsAndPositions.push_back({{px, py}, {vx, vy}});
  }

  file.close();

  auto print = [&](vector<pair<int, int>> robots, int time) {
    cout << "Time elapsed: " << time << endl;

    set<pair<int, int>> robotSet(robots.begin(), robots.end());

    for (int c = 0; c < H; c++) {
      for (int r = 0; r < W; r++) {
        if (robotSet.count({r, c})) {
          cout << "X";
        } else {
          cout << ".";
        }
      }
      cout << endl;
    }
    cout << endl;
  };

  auto calculateVariance = [&](int seconds) {
    vector<pair<int, int>> robots;

    for (auto robot : robotsAndPositions) {

      int newX =
          ((robot.first.first + robot.second.first * seconds) % W + W) % W;
      int newY =
          ((robot.first.second + robot.second.second * seconds) % H + H) % H;
      robots.push_back({newX, newY});
    }

    double meanX = 0, meanY = 0;

    for (auto robot : robots) {
      meanX += robot.first;
      meanY += robot.second;
    }
    meanX /= robots.size();
    meanY /= robots.size();

    double varianceX = 0, varianceY = 0;
    for (auto robot : robots) {
      double deltaX = robot.first - meanX;
      double deltaY = robot.second - meanY;
      varianceX += deltaX * deltaX;
      varianceY += deltaY * deltaY;
    }
    varianceX /= robots.size();
    varianceY /= robots.size();
    return make_pair(varianceX + varianceY, robots);
  };

  int secondsElapsed = 0;
  double minVariance = numeric_limits<double>::max();

  int range = 10000;
  for (int i = 0; i < range; i++) {
    auto [variance, robots] = calculateVariance(i);
    if (minVariance > variance) {
      minVariance = variance;
      secondsElapsed = i;
      cout << "new minimum at time elapsed: " << i << " variance, " << variance
           << endl;
      print(robots, i);
    }
  }

  return 0;
}
