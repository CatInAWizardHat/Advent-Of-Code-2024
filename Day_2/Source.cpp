#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool validate(const std::vector<int> &report) {
  bool safe{std::is_sorted(report.begin(), report.end()) ||
            std::is_sorted(report.begin(), report.end(), std::greater<int>())};
  bool isIncreasing = std::is_sorted(report.begin(), report.end());
  for (int i = 1; i < report.size(); i++) {
    int curr = report.at(i), prev = report.at(i - 1);
    if (isIncreasing && (curr <= prev)) {
      safe = false;
    } else if (!isIncreasing && (curr >= prev)) {
      safe = false;
    }
    if (abs(curr - prev) > 3) {
      safe = false;
    }
  }
  return safe;
}

void solve() {
  std::string filename{"input.txt"};
  std::ifstream file(filename);
  std::string line;
  std::stringstream ss;

  int count{0};

  while (std::getline(file, line)) {
    std::vector<int> report{};
    ss.str(line);
    std::string token;
    while (ss >> token) {
      report.push_back(stoi(token));
    }
    if (validate(report)) {
      count++;
    }
  }
  std::cout << count;
}
int main() {
  solve();
  return 0;
}
