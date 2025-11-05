#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream file("input.txt");

  // sorry learning to type on this new keyboard :)

  auto determinate = [](int &aX, int &aY, int &bX, int &bY) {
    long long detA = aX * bY - bX * aY;
    return detA;
  };

  string line;
  int aX, aY, bX, bY, pX, pY = 0;

  long long ans = 0;
  while (getline(file, line)) {
    if (line.empty()) {
      long long detA = determinate(aX, aY, bX, bY);
      if (detA == 0) {
        aX = aY = bX = bY = pX = pY = 0;
        continue;
      }

      long long detAa = determinate(pX, pY, bX, bY);
      long long detAb = determinate(aX, aY, pX, pY);

      if (detAa % detA != 0 || detAb % detA != 0) {
        aX = aY = bX = bY = pX = pY = 0;
        continue;
      }

      long long aPresses = detAa / detA;
      long long bPresses = detAb / detA;

      if (!(aPresses > 0 && bPresses > 0)) {
        cout << aPresses;
        aX = aY = bX = bY = pX = pY = 0;
        continue;
      }

      ans += aPresses * 3 + bPresses;

      aX = aY = bX = bY = pX = pY = 0;
      continue;
    }
    sscanf(line.c_str(), "Button A: X+%d, Y+%d", &aX, &aY);
    sscanf(line.c_str(), "Button B: X+%d, Y+%d", &bX, &bY);
    sscanf(line.c_str(), "Prize: X=%d, Y=%d", &pX, &pY);
  }

  file.close();

  cout << ans;

  return 0;
}
