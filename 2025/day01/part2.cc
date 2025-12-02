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
      if (start == 0) {
        ans += amount / 100;
      } else if (amount >= start) {
        ans += 1 + (amount - start) / 100;
      }
      start -= amount;
    } else {
      ans += (start + amount) / 100;
      start += amount;
    }
    start = ((start % 100) + 100) % 100;
  }
  cout << ans;

  file.close();
  return 0;
}
