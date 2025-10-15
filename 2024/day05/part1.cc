#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");

  string line;
  map<int, vector<int>> paths;
  bool readPastRules = 0;

  int ans = 0;

  auto storeDigits = [](string &line, vector<int> &v) {
    for (int i = 0; i < line.size(); i++) {
      int x = 0;
      while (isdigit(line[i])) {
        x = 10 * x + (line[i] - '0');
        i++;
      }
      v.push_back(x);
    }
  };

  auto isOk = [](map<int, vector<int>> &a, vector<int> &b) {
    set<int> seen;
    bool ok = 1;
    for (int i = 0; i < b.size(); i++) {
      int x = b[i];
      for (int y : a[x]) {
        if (seen.count(y)) {
          ok = 0;
        }
      }
      seen.insert(x);
    }
    return ok;
  };

  auto fixOrder = [](map<int, vector<int>> &paths, vector<int> &v) {
    sort(v.begin(), v.end(), [&paths](int a, int b) {
      for (int x : paths[a]) {
        if (x == b)
          return 1;
      }
      for (int x : paths[b]) {
        if (x == a)
          return 0;
      }
      return 0;
    });
    return v;
  };

  while (getline(file, line)) {
    vector<int> v;
    if (line.size() == 0) {
      readPastRules = 1;
      continue;
    }
    if (!readPastRules) {
      storeDigits(line, v);
      paths[v[0]].push_back(v[1]);
    } else {
      storeDigits(line, v);
      if (!isOk(paths, v)) {
        vector<int> fixed = fixOrder(paths, v);
        ans += fixed[fixed.size() / 2];
      }
    }
  }
  cout << ans;
  file.close();
  return 0;
}
