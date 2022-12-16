#include <fstream>
#include <iostream>
#include <vector>
int main() {
  std::ifstream file("day12.txt");
  std::string line;
  std::vector<std::vector<char>> map;
  while (getline(file, line)) {
    std::vector<char> chars;
    for (int i = 0; i < line.length(); i++) {
      chars.push_back(line.at(i));
    }
    map.push_back(chars);
  }
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map.at(i).size(); j++) {
      std::cout << map[i][j];
    }
    std::cout << "\n";
  }
}