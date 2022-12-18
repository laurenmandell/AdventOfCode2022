#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "json.hpp"

bool comparePackets(const nlohmann::json &json1, const nlohmann::json &json2) {
  
}

int main() {
  std::ifstream file("day13.txt");
  std::string line1, line2, line3;
  int index = 1;
  int sum = 0;
  while (getline(file, line1)) {  // first packet
    getline(file, line2);         // second packet
    getline(file, line3);         // empty line
    nlohmann::json json1 = nlohmann::json::parse(line1);
    nlohmann::json json2 = nlohmann::json::parse(line2);
    if (comparePackets(json1, json2)) {
      sum += index;
    }
    index++;
  }
  std::cout << sum << "\n";
}