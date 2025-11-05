#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream file("input.txt");

  // sorry learning to type on this new keyboard :)

  auto determinate = [](long long &aX, long long &aY, long long &bX,
                        long long &bY) { return aX * bY - bX * aY; };

  string line;
  long long aX = 0, aY = 0, bX = 0, bY = 0;
  long long pX = 0, pY = 0;
  unsigned long long ans = 0;

  auto processSet = [&]() {
    if (aX == 0 && aY == 0 && bX == 0 && bY == 0) {
      return;
    }

    pX += 10000000000000ll;
    pY += 10000000000000ll;
    long long detA = determinate(aX, aY, bX, bY);

    if (detA != 0) {
      long long detAa = determinate(pX, pY, bX, bY);
      long long detAb = determinate(aX, aY, pX, pY);
      if (detAa % detA == 0 && detAb % detA == 0) {

        long long aPresses = detAa / detA;
        long long bPresses = detAb / detA;

        if (aPresses >= 0 && bPresses >= 0) {
          ans += aPresses * 3 + bPresses;
        }
      }
    }
    aX = aY = bX = bY = pX = pY = 0;
  };

  while (getline(file, line)) {
    if (line.empty()) {
      processSet();
      continue;
    }
    sscanf(line.c_str(), "Button A: X+%lld, Y+%lld", &aX, &aY);
    sscanf(line.c_str(), "Button B: X+%lld, Y+%lld", &bX, &bY);
    sscanf(line.c_str(), "Prize: X=%lld, Y=%lld", &pX, &pY);
  }
  processSet();

  file.close();

  cout << ans;

  return 0;
}
