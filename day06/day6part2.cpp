#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
int main(int argc, char** argv) {
  std::ifstream file("day6.txt");
  std::string line;
  std::getline(file, line);
  int index = 13;
  std::string currSubstr = line.substr(0, 14);
  while (index < line.length()) {
    bool allDifferent = true;
    for (int i = 0; i < 14; i++) {
      for (int j = 0; j < 14; j++) {
        if (i != j && currSubstr.at(i) == currSubstr.at(j)) {
          allDifferent = false;
        }
      }
    }
    if (allDifferent) {
      break;
    }
    index++;
    currSubstr = line.substr(index - 13, 14);
  }
  std::cout << index + 1 << "\n";
}