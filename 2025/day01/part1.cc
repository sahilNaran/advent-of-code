#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");

  string line;

  int start = 50;
  int ans = 0;
  while (getline(file, line)) {
    char dir;
    int amount;

    sscanf(line.c_str(), "%c%d", &dir, &amount);
    if (dir == 'L') {
      start -= amount;
    } else {
      start += amount;
    }
    start = ((start % 100) + 100) % 100;
    if (start == 0) {
      ans++;
    }
  }
  cout << ans;

  file.close();
  return 0;
}
