#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream file("input.txt");

  string content((istreambuf_iterator<char>(file)),
                 istreambuf_iterator<char>());

  content += "--------------";

  auto getDigit = [&](int &i, string delim) {
    auto pos = content.substr(i, 4).find(delim);
    if (pos != string::npos) {
      int digit = stoi(content.substr(i, pos));
      i += pos;
      return digit;
    }
    return -1;
  };

  int ans = 0;
  bool enabled = 1;
  for (int i = 0; i < content.size(); i++) {
    if (content.substr(i, 4) == "do()") {
      enabled = 1;
      i += 4;
    }
    if (content.substr(i, 7) == "don't()") {
      enabled = 0;
      i += 7;
    }
    if (enabled && content.substr(i, 4) == "mul(") {
      i += 4;
      int x = getDigit(i, ",");
      if (x == -1) {
        continue;
      }
      i++;
      int y = getDigit(i, ")");
      if (y == -1) {
        continue;
      }
      ans += x * y;
    }
  }

  cout << ans;

  file.close();
  return 0;
}
