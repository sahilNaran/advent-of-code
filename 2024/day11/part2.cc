#include <chrono>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int numDigits(unsigned long long n) {
  if (n == 0) {
    return 1;
  }
  int count = 0;
  while (n > 0) {
    count++;
    n /= 10;
  }
  return count;
}

pair<unsigned long long, unsigned long long> splitNumber(unsigned long long n,
                                                         int numDig) {
  int mid = numDig / 2;

  unsigned long long divisor = 1;
  for (size_t i = 0; i < mid; i++) {
    divisor *= 10;
  }

  unsigned long long left = n / divisor;
  unsigned long long right = n % divisor;

  return {left, right};
}

int main() {

  ifstream file("input.txt");
  unordered_map<unsigned long long, unsigned long long> frequency;

  unsigned long long input;
  while (file >> input) {
    frequency[input]++;
  }

  file.close();

  int repeat = 75;
  while (repeat--) {

    auto startTime = chrono::high_resolution_clock::now();

    unordered_map<unsigned long long, unsigned long long> newFreq;

    for (const auto &[number, count] : frequency) {

      if (number == 0) {
        newFreq[1] += count;
      } else {
        int numDig = numDigits(number);
        if (numDig % 2 == 0) {
          auto [left, right] = splitNumber(number, numDig);
          newFreq[left] += count;
          newFreq[right] += count;
        } else {
          newFreq[number * 2024] += count;
        }
      }
    }
    frequency = std::move(newFreq);
    auto endTime = chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cout << "Progress: " << repeat << " Time: " << duration.count() << endl;
  }

  unsigned long long total = 0;

  for (const auto &[number, count] : frequency) {
    total += count;
  }

  cout << "Answer: " << total << endl;

  return 0;
}
