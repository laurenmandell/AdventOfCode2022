#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
int main(int argc, char** argv) {
  std::ifstream file("day6.txt");
  std::string line;
  std::getline(file, line);
  int index = 3;
  std::string currSubstr = line.substr(0, 4);
  while (index < line.length()) {
    bool allDifferent = true;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i != j && currSubstr.at(i) == currSubstr.at(j)) {
          allDifferent = false;
        }
      }
    }
    if (allDifferent) {
      break;
    }
    index++;
    currSubstr = line.substr(index - 3, 4);
  }
  std::cout << index + 1 << "\n";
}