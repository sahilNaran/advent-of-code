#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");

  string line;

  int safeCount = 0;

  while (getline(file, line)) {
    vector<int> levels;
    istringstream iss(line);
    int num;

    while (iss >> num) {
      levels.push_back(num);
    }

    if (levels.size() < 2) {
      continue;
    }

    bool isSafe = 1;
    bool isDecreasing = levels[0] > levels[1];
    for (size_t i = 0; i < levels.size() - 1; i++) {
      if (isDecreasing) {
        if (levels[i] - levels[i + 1] > 3 || levels[i] - levels[i + 1] <= 0) {
          isSafe = 0;
        }
        continue;
      }
      if (levels[i + 1] - levels[i] > 3 || levels[i + 1] - levels[i] <= 0) {
        isSafe = 0;
      }
    }
    if (isSafe) {
      safeCount++;
    }
  }

  cout << safeCount;

  file.close();
  return 0;
}
