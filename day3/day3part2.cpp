#include <fstream>
#include <iostream>
#include <string>
int main(int argc, char** argv) {
  std::ifstream file("day3.txt");
  std::string line;
  std::string line1;
  std::string line2;
  std::string line3;
  int sum = 0;
  while (getline(file, line1)) {
    getline(file, line2);
    getline(file, line3);
    char inall;
    char inboth;
    for (int i = 0; i < line1.length(); i++) {
      for (int j = 0; j < line2.length(); j++) {
        if (line1.at(i) == line2.at(j)) {
          inboth = line1.at(i);
          for (int k = 0; k < line3.length(); k++) {
            if (line3.at(k) == inboth) {
              inall = inboth;
            }
          }
        }
      }
    }
    int numtoadd;
    if (inall >= 65 && inall <= 90) {
      numtoadd = inall - 38;
    } else {
      numtoadd = inall - 96;
    }
    sum += numtoadd;
  }
  std::cout << sum << "\n";
}