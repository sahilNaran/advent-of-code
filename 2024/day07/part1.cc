#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dfs(long long target, vector<int> &nums, int index, bool op,
         long long total) {
  int x = nums[index];
  if (op) {
    total += x;
  } else {
    total *= x;
  }
  if (index == nums.size() - 1) {
    return target == total;
  }
  return dfs(target, nums, index + 1, 1, total) ||
         dfs(target, nums, index + 1, 0, total);
}

int main() {
  ifstream file("input.txt");
  string line;

  long long ans = 0;
  while (getline(file, line)) {
    long long x = 0;
    bool colon = 0;
    long long target = 0;
    vector<int> nums;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ':') {
        colon = 1;
        continue;
      }
      if (isdigit(line[i])) {
        long long x = 0;
        while (i < line.size() && isdigit(line[i])) {
          x = 10 * x + (line[i] - '0');
          i++;
        }
        i--;
        if (!colon) {
          target = x;
        } else {
          nums.push_back(x);
        }
      }
    }
    if (dfs(target, nums, 0, 1, 0) || dfs(target, nums, 0, 1, 0)) {
      ans += target;
    }
  }

  cout << ans;
  file.close();
  return 0;
}
