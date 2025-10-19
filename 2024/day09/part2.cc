#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");

  string content((istreambuf_iterator<char>(file)),
                 istreambuf_iterator<char>());
  file.close();

  vector<vector<int>> ans;

  int id = 0;
  for (size_t i = 0; i < content.size(); i++) {
    int insert = -1;
    if (i % 2 == 0) {
      insert = id;
      id++;
    }
    int num = content[i] - '0';
    vector<int> temp;
    while (num > 0) {
      temp.push_back(insert);
      num--;
    }
    ans.push_back(temp);
  }

  int left = 0;
  int right = ans.size() - 1;

  while (left < right) {
    if (!ans[left].empty() && ans[left][0] == -1) {
      if (!ans[right].empty() && ans[right][0] != -1) {
        if (ans[right].size() <= ans[left].size()) {
          int dif = ans[left].size() - ans[right].size();
          ans[left] = ans[right];
          ans[right] = vector<int>(ans[right].size(), -1);
          if (dif > 0) {
            vector<int> blank(dif, -1);
            ans.insert(ans.begin() + left + 1, blank);
            right++;
          }
          right--;
          left = 0;
        } else {
          left++;
          if (left >= right) {
            right--;
            left = 0;
          }
        }
      } else {
        right--;
        left = 0;
      }
    } else {
      left++;
      if (left >= right) {
        right--;
        left = 0;
      }
    }
  }

  vector<int> flat;
  for (size_t i = 0; i < ans.size(); i++) {
    for (size_t j = 0; j < ans[i].size(); j++) {
      if (ans[i][j] == -1) {
        flat.push_back(-1);
        continue;
      }
      flat.push_back(ans[i][j]);
    }
  }

  unsigned long long checksum = 0;
  for (size_t i = 0; i < flat.size(); i++) {
    if (flat[i] == -1) {
      continue;
    }
    checksum = checksum + (i * flat[i]);
  }

  cout << checksum << endl;

  return 0;
}
