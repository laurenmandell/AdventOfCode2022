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

void moveKnots(std::vector<pairs>& knots) {
  for (int i = 0; i < 9; i++) {
    if (inLine(knots.at(i), knots.at(i + 1))) {
      if (knots.at(i).second == knots.at(i + 1).second + 2) {
        knots.at(i + 1).second++;
      } else if (knots.at(i).second == knots.at(i + 1).second - 2) {
        knots.at(i + 1).second--;
      } else if (knots.at(i).first == knots.at(i + 1).first - 2) {
        knots.at(i + 1).first--;
      } else if (knots.at(i).first == knots.at(i + 1).first + 2) {
        knots.at(i + 1).first++;
      }
    } else if (notTouching(knots.at(i), knots.at(i + 1))) {
      if (knots.at(i + 1).first < knots.at(i).first) {
        knots.at(i + 1).first++;
        if (knots.at(i + 1).second < knots.at(i).second) {
          knots.at(i + 1).second++;
        } else {
          knots.at(i + 1).second--;
        }
      } else if (knots.at(i + 1).second < knots.at(i).second) {
        knots.at(i + 1).second++;
        if (knots.at(i + 1).first < knots.at(i).first) {
          knots.at(i + 1).first++;
        } else {
          knots.at(i + 1).first--;
        }
      } else if (knots.at(i + 1).first > knots.at(i).first) {
        knots.at(i + 1).first--;
        if (knots.at(i + 1).second < knots.at(i).second) {
          knots.at(i + 1).second++;
        } else {
          knots.at(i + 1).second--;
        }
      } else if (knots.at(i + 1).second > knots.at(i).second) {
        knots.at(i + 1).second--;
        if (knots.at(i + 1).first < knots.at(i).first) {
          knots.at(i + 1).first++;
        } else {
          knots.at(i + 1).first--;
        }
      }
    }
  }
}

int main() {
  std::ifstream file("day9.txt");
  std::vector<pairs> knots;
  for (int i = 0; i < 10; i++) {
    knots.push_back(std::make_pair(0, 0));
  }
  std::set<pairs> visited;
  visited.insert(knots.at(9));
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
        knots.at(0).second++;
        moveKnots(knots);
        visited.insert(knots.at(9));
      }
    } else if (direction.compare("D") == 0) {
      for (int i = 0; i < numSteps; i++) {
        knots.at(0).second--;
        moveKnots(knots);
        visited.insert(knots.at(9));
      }
    } else if (direction.compare("L") == 0) {
      for (int i = 0; i < numSteps; i++) {
        knots.at(0).first--;
        moveKnots(knots);
        visited.insert(knots.at(9));
      }
    } else if (direction.compare("R") == 0) {
      for (int i = 0; i < numSteps; i++) {
        knots.at(0).first++;
        moveKnots(knots);
        visited.insert(knots.at(9));
      }
    }
  }
  std::cout << visited.size() << "\n";
}