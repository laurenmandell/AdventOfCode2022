#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string pixel(int cycleNum, int x) {
  if ((cycleNum - 1) % 40 == x || (cycleNum - 1) % 40 == x - 1 ||
      (cycleNum - 1) % 40 == x + 1) {
    return "#";
  } else {
    return ".";
  }
}
int main() {
  std::ifstream file("day10.txt");
  std::string line;
  int x = 1;
  int cycleNum = 0;
  std::vector<std::string> screen;

  while (getline(file, line)) {
    if (line.compare("noop") == 0) {
      cycleNum++;
      screen.push_back(pixel(cycleNum, x));
    } else {
      std::stringstream ss(line);
      std::string instruction;
      std::string numStr;
      std::getline(ss, instruction, ' ');
      std::getline(ss, numStr, '\n');
      cycleNum++;
      screen.push_back(pixel(cycleNum, x));
      cycleNum++;
      screen.push_back(pixel(cycleNum, x));
      if (numStr.at(0) == '-') {
        numStr.erase(0, 1);
        x -= stoi(numStr);
      } else {
        x += stoi(numStr);
      }
    }
  }

  int position = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 40; j++) {
      std::cout << screen.at(position);
      position++;
    }
    std::cout << "\n";
  }
}