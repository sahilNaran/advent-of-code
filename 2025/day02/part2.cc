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
    string doubled = s + s;
    if (doubled.substr(1, doubled.length() - 2).find(s) != std::string::npos) {
      long long id = stoll(s);
      ans += id;
    }
  }
  cout << ans;
  return 0;
}
