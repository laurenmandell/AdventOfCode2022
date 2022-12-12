#include <bits/stdc++.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

typedef std::pair<int, int> pairs;

bool notTouching(pairs headPos, pairs tailPos) {
  if (abs(headPos.first - tailPos.first) > 1 ||
      abs(headPos.second - tailPos.second) > 1) {
    return true;
  }
  return false;
}

bool inLine(pairs headPos, pairs tailPos) {
  if (headPos.first == tailPos.first || headPos.second == tailPos.second) {
    return true;
  }
  return false;
}

int main() {
  std::ifstream file("day9.txt");
  pairs headPos = std::make_pair(0, 0);
  pairs tailPos = std::make_pair(0, 0);
  std::set<pairs> visited;
  visited.insert(tailPos);
  std::string line;

  while (getline(file, line)) {
    std::stringstream ss(line);
    std::string direction;
    std::string numStepsStr;
    std::getline(ss, direction, ' ');
    std::getline(ss, numStepsStr, '\n');
    int numSteps = stoi(numStepsStr);

    if (direction.compare("U") == 0) {
      for (int i = 0; i < numSteps; i++) {
        headPos.second++;
        if (inLine(headPos, tailPos) && headPos.second == tailPos.second + 2) {
          tailPos.second++;
          visited.insert(tailPos);
        } else if (notTouching(tailPos, headPos)) {
          tailPos.second = headPos.second - 1;
          tailPos.first = headPos.first;
          visited.insert(tailPos);
        }
      }
    } else if (direction.compare("D") == 0) {
      for (int i = 0; i < numSteps; i++) {
        headPos.second--;
        if (inLine(headPos, tailPos) && headPos.second == tailPos.second - 2) {
          tailPos.second--;
          visited.insert(tailPos);
        } else if (notTouching(headPos, tailPos)) {
          tailPos.second = headPos.second + 1;
          tailPos.first = headPos.first;
          visited.insert(tailPos);
        }
      }
    } else if (direction.compare("L") == 0) {
      for (int i = 0; i < numSteps; i++) {
        headPos.first--;
        if (inLine(headPos, tailPos) && headPos.first == tailPos.first - 2) {
          tailPos.first--;
          visited.insert(tailPos);
        } else if (notTouching(headPos, tailPos)) {
          tailPos.first = headPos.first + 1;
          tailPos.second = headPos.second;
          visited.insert(tailPos);
        }
      }
    } else if (direction.compare("R") == 0) {
      for (int i = 0; i < numSteps; i++) {
        headPos.first++;
        if (inLine(headPos, tailPos) && headPos.first == tailPos.first + 2) {
          tailPos.first++;
          visited.insert(tailPos);
        } else if (notTouching(headPos, tailPos)) {
          tailPos.first = headPos.first - 1;
          tailPos.second = headPos.second;
          visited.insert(tailPos);
        }
      }
    }
  }

  std::cout << visited.size() << "\n";
}