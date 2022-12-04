#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
int main(int argc, char** argv) {
  std::ifstream file("day4.txt");
  std::string line;
  int count = 0;
  while (getline(file, line)) {
    std::string num1str, num2str, num3str, num4str;
    std::stringstream ss(line);
    std::getline(ss, num1str, '-');
    std::getline(ss, num2str, ',');
    std::getline(ss, num3str, '-');
    std::getline(ss, num4str, '\n');

    int num1 = std::stoi(num1str);
    int num2 = std::stoi(num2str);
    int num3 = std::stoi(num3str);
    int num4 = std::stoi(num4str);

    if (num4 <= num2 && num3 >= num1) {
      count++;
    } else if (num2 <= num4 && num1 >= num3) {
      count++;
    }
  }
  std::cout << count << "\n";
}