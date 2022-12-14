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
  int deleteDirSize = 0;
  int totalSpace = 70000000;
  int minDiff = totalSpace;
  int usedSpace = 41412830;
  // found usedSpace by reading first element in curPath from day7part1.cpp
  // this first element would be the outermost directory
  int needToFree = 30000000 - (totalSpace - usedSpace);
  // we need at least 30000000
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
        if (curPath.back().first >= needToFree &&
            curPath.back().first - needToFree < minDiff) {
          minDiff = curPath.back().first - needToFree;
          deleteDirSize = curPath.back().first;
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
    if (curPath.back().first >= needToFree &&
        curPath.back().first - needToFree < minDiff) {
      minDiff = curPath.back().first - needToFree;
      deleteDirSize = curPath.back().first;
    }
  }

  std::cout << deleteDirSize << "\n";
}