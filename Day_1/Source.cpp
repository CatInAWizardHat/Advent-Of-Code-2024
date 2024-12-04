#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int totalDist{};
  std::string filename{"input.txt"};
  std::ifstream file;
  file.open(filename);

  std::vector<int> lVec{};
  std::vector<int> rVec{};

  std::string line;
  while (std::getline(file, line)) {
    std::string token = line.substr(0, line.find(" "));
    int left = std::stoi(token);
    lVec.push_back(left);

    token = line.substr(line.find(" "));
    int right = std::stoi(token);
    rVec.push_back(right);
  }
  auto begin = rVec.begin();
  auto end = rVec.end();
  std::sort(begin, end);
  begin = lVec.begin();
  end = lVec.end();
  std::sort(begin, end);

  for (int i{0}; i < lVec.size(); i++) {
    totalDist += abs(rVec[i] - lVec[i]);
  }
  std::cout << totalDist << '\n';
}

int main() {
  solve();
  return 0;
}
