#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int addToSum(int cycleNum, int x) {
  if (cycleNum == 20 || cycleNum == 60 || cycleNum == 100 || cycleNum == 140 ||
      cycleNum == 180 || cycleNum == 220) {
    return cycleNum * x;
  } else {
    return 0;
  }
}

int main() {
  std::ifstream file("day10.txt");
  std::string line;
  int sum = 0;
  int x = 1;
  int cycleNum = 0;

  while (getline(file, line)) {
    if (line.compare("noop") == 0) {
      cycleNum++;
      sum += addToSum(cycleNum, x);
    } else {
      std::stringstream ss(line);
      std::string instruction;
      std::string numStr;
      std::getline(ss, instruction, ' ');
      std::getline(ss, numStr, '\n');
      cycleNum++;
      sum += addToSum(cycleNum, x);
      cycleNum++;
      sum += addToSum(cycleNum, x);
      if (numStr.at(0) == '-') {
        numStr.erase(0, 1);
        x -= stoi(numStr);
      } else {
        x += stoi(numStr);
      }
    }
  }

  std::cout << sum << "\n";
}