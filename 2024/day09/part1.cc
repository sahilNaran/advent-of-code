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

  vector<int> ans;

  int id = 0;
  for (int i = 0; i < content.size(); i++) {
    int insert = -1;
    if (i % 2 == 0) {
      insert = id;
      id++;
    }
    int num = content[i] - '0';
    while (num > 0) {
      ans.push_back(insert);
      num--;
    }
  }

  int left = 0;
  int right = ans.size() - 1;

  while (left < right) {
    if (ans[left] == -1) {
      if (ans[right] != -1) {
        ans[left] = ans[right];
        ans[right] = -1;
        left++;
        right--;
      } else {
        right--;
      }
    } else {
      left++;
    }
  }

  unsigned long long checksum = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == -1) {
      continue;
    }
    checksum = checksum + (i * ans[i]);
  }

  cout << checksum << endl;

  return 0;
}
