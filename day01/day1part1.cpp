#include <string.h>

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::ifstream file("day1.txt");
  std::string line;
  int max = 0;
  while (getline(file, line)) {
    int sum = std::stoi(line);
    while (getline(file, line) && line.compare("") != 0) {
      sum += std::stoi(line);
    }
    if (sum > max) {
      max = sum;
    }
  }
  std::cout << max << "\n";
}