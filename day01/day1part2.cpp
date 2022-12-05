#include <string.h>

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::ifstream file("day1.txt");
  std::string line;
  int max1 = 0;
  int max2 = 0;
  int max3 = 0;
  while (getline(file, line)) {
    int sum = std::stoi(line);
    while (getline(file, line) && line.compare("") != 0) {
      sum += std::stoi(line);
    }
    if (sum > max1) {
      max3 = max2;
      max2 = max1;
      max1 = sum;
    } else if (sum > max2) {
      max3 = max2;
      max2 = sum;
    } else if (sum > max3) {
      max3 = sum;
    }
  }
  int total = max1 + max2 + max3;
  std::cout << total << "\n";
}