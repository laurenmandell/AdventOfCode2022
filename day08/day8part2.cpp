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

  int maxScore = 0;
  for (int i = 0; i < cols.size(); i++) {
    for (int j = 0; j < cols[i].size(); j++) {
      int curHeight = cols[i][j];
      // check top
      int topScore = 0;
      for (int k = i - 1; k >= 0; k--) {
        topScore++;
        if (curHeight <= cols[k][j]) {
          break;
        }
      }
      // check bottom
      int botScore = 0;
      for (int k = i + 1; k < cols.size(); k++) {
        botScore++;
        if (curHeight <= cols[k][j]) {
          break;
        }
      }
      // check right
      int rightScore = 0;
      for (int k = j + 1; k < cols.size(); k++) {
        rightScore++;
        if (curHeight <= cols[i][k]) {
          break;
        }
      }
      // check left
      int leftScore = 0;
      for (int k = j - 1; k >= 0; k--) {
        leftScore++;
        if (curHeight <= cols[i][k]) {
          break;
        }
      }
      int curScore = topScore * botScore * rightScore * leftScore;
      if (curScore > maxScore) {
        maxScore = curScore;
      }
    }
  }

  std::cout << maxScore << "\n";
}