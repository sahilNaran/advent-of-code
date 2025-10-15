#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");
  vector<int> left, right;

  int l, r;
  while (file >> l >> r) {
    // Process input here
    left.push_back(l);
    right.push_back(r);
  }

  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  int sum = 0;

  for (size_t i = 0; i < left.size(); i++) {
    sum += abs(left[i] - right[i]);
  }

  cout << sum;

  file.close();
  return 0;
}
