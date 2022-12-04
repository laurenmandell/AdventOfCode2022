#include <fstream>
#include <iostream>
#include <string>
int main(int argc, char** argv) {
  std::ifstream file("day3.txt");
  std::string line;
  std::string firsthalf;
  std::string secondhalf;
  int sum = 0;
  while (getline(file, line)) {
    int length = line.length();
    firsthalf = line.substr(0, line.length()/2);
    secondhalf = line.substr(line.length() / 2, line.length());
    char inboth;
    for (int i = 0; i < firsthalf.length(); i++) {
      for (int j = 0; j < secondhalf.length(); j++) {
        if (firsthalf.at(i) == secondhalf.at(j)) {
          inboth = firsthalf.at(i);
        }
      }
    }
    int numtoadd;
    if(inboth >= 65 && inboth<=90) {
        numtoadd = inboth - 38;
    } else {
        numtoadd = inboth - 96;
    }
    sum += numtoadd;
  }
  std::cout << sum << "\n";
}