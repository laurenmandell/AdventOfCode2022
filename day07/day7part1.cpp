#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef std::pair<int, std::string> dirs;

int main() {
  std::ifstream file("day7.txt");
  std::string line;
  std::string garbage;
  int sum = 0;
  std::vector<dirs> curPath;

  while (getline(file, line)) {
    if (line.substr(0, 4).compare("$ cd") == 0) {
      std::string dirName;
      std::stringstream ss(line);
      std::getline(ss, garbage, ' ');
      std::getline(ss, garbage, ' ');
      std::getline(ss, dirName, '\n');
      if (dirName.compare("..") != 0) {
        curPath.push_back(std::make_pair(0, dirName));
      } else {
        if (curPath.back().first <= 100000) {
          sum += curPath.back().first;
        }
        curPath.pop_back();
      }
    } else if (line.at(0) != '$' && line.substr(0, 3).compare("dir") != 0) {
      std::string fileSizeStr;
      std::stringstream ss(line);
      std::getline(ss, fileSizeStr, ' ');
      std::getline(ss, garbage, '\n');
      for (int i = 0; i < curPath.size(); i++) {
        curPath.at(i).first += stoi(fileSizeStr);
      }
    }
  }

  for (int i = 0; i < curPath.size(); i++) {
    if (curPath.at(i).first <= 100000) {
      sum += curPath.at(i).first;
    }
  }

  std::cout << sum << "\n";
}