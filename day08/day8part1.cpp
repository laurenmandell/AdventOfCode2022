#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
int main(int argc, char** argv) {
  std::ifstream file("day8.txt");
  std::string line;
  std::vector<std::vector<int>> cols;
  while (std::getline(file, line)) {
    std::vector<int> row;
    int curNum;
    char curChar;
    for (int j = 0; j < line.length(); j++) {
      curChar = line.at(j);
      curNum = curChar - '0';
      row.push_back(curNum);
    }
    cols.push_back(row);
  }

  int count = 0;
  for (int i = 0; i < cols.size(); i++) {
    for (int j = 0; j < cols[i].size(); j++) {
      bool isVisible = false;
      int curHeight = cols[i][j];
      // check if it's an edge
      if (i == 0 || j == 0 || i == cols.size() - 1 || j == cols[i].size() - 1) {
        isVisible = true;
      } else {
        // check top
        for (int k = i - 1; k >= 0; k--) {
          if (curHeight <= cols[k][j]) {
            break;
          } else if (k == 0) {
            isVisible = true;
          }
        }
        // check bottom
        for (int k = i + 1; k < cols.size(); k++) {
          if (curHeight <= cols[k][j]) {
            break;
          } else if (k == cols.size() - 1) {
            isVisible = true;
          }
        }
        // check right
        for (int k = j + 1; k < cols.size(); k++) {
          if (curHeight <= cols[i][k]) {
            break;
          } else if (k == cols.size() - 1) {
            isVisible = true;
          }
        }
        // check left
        for (int k = j - 1; k >= 0; k--) {
          if (curHeight <= cols[i][k]) {
            break;
          } else if (k == 0) {
            isVisible = true;
          }
        }
      }
      if (isVisible == true) {
        count++;
      }
    }
  }

  std::cout << count << "\n";
}