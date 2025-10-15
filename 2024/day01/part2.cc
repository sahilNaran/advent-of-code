#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
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

  unordered_map<int, int> counts;

  for (int num : right) {
    counts[num]++;
  }

  int score = 0;

  for (int num : left) {
    score += num * counts[num];
  }

  cout << score;

  file.close();
}
