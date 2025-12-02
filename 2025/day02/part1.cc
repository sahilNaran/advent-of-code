#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {

  ifstream file("input.txt");
  string line;
  getline(file, line);
  file.close();

  vector<string> ids;

  stringstream ss(line);
  string range;
  while (getline(ss, range, ',')) {
    long long first = 0;
    long long second = 0;
    sscanf(range.c_str(), "%lld-%lld", &first, &second);
    while (first <= second) {
      ids.emplace_back(to_string(first));
      first++;
    }
  }

  long long ans = 0;
  for (string s : ids) {
    string first = s.substr(0, s.length() / 2);
    string second = s.substr(s.length() / 2);
    if (first == second) {
      long long id = stoll(s);
      ans += id;
    }
  }
  cout << ans;

  return 0;
}
