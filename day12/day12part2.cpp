#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

typedef std::pair<int, int> pairs;

class point {
 public:
  point(int x_, int y_, int distance_) {
    x = x_;
    y = y_;
    distance = distance_;
  }
  int getX() { return x; }
  int getY() { return y; }
  int getDistance() { return distance; }

 private:
  int x;
  int y;
  int distance;
};

// BFS algorithm
int findFewestSteps(std::vector<std::vector<char>>& map, point start) {
  std::queue<point> frontierQueue;
  std::set<pairs> discoveredSet;
  frontierQueue.push(start);

  while (!frontierQueue.empty()) {
    point p = frontierQueue.front();
    frontierQueue.pop();

    char elevation;
    if (map[p.getY()][p.getX()] == 'S') {  // starting point has elevation a
      elevation = 'a';
    } else {
      elevation = map[p.getY()][p.getX()];
    }

    std::vector<point> validSteps;

    int topX = p.getX();
    int topY = p.getY() + 1;
    // check if top point is a valid step
    if (topY < map.size()) {
      point top = point(topX, topY, p.getDistance() + 1);
      if (map[topY][topX] == 'E' && elevation >= 'y') {
        return top.getDistance();
      } else if (map[topY][topX] <= elevation + 1) {
        validSteps.push_back(top);
      }
    }

    int botX = p.getX();
    int botY = p.getY() - 1;
    // check if bottom point is a valid step
    if (botY >= 0) {
      point bot = point(botX, botY, p.getDistance() + 1);
      if (map[botY][botX] == 'E' && elevation >= 'y') {
        return bot.getDistance();
      } else if (map[botY][botX] <= elevation + 1) {
        validSteps.push_back(bot);
      }
    }

    int rightX = p.getX() + 1;
    int rightY = p.getY();
    // check if right point is a valid step
    if (rightX < map.at(0).size()) {
      point right = point(rightX, rightY, p.getDistance() + 1);
      if (map[rightY][rightX] == 'E' && elevation >= 'y') {
        return right.getDistance();
      } else if (map[rightY][rightX] <= elevation + 1) {
        validSteps.push_back(right);
      }
    }

    int leftX = p.getX() - 1;
    int leftY = p.getY();
    // check if left point is a valid step
    if (leftX >= 0) {
      point left = point(leftX, leftY, p.getDistance() + 1);
      if (map[leftY][leftX] == 'E' && elevation >= 'y') {
        return left.getDistance();
      } else if (map[leftY][leftX] <= elevation + 1) {
        validSteps.push_back(left);
      }
    }

    for (int i = 0; i < validSteps.size(); i++) {
      pairs position =
          std::make_pair(validSteps.at(i).getX(), validSteps.at(i).getY());
      if (discoveredSet.find(position) == discoveredSet.end()) {
        frontierQueue.push(validSteps.at(i));
        discoveredSet.insert(position);
      }
    }
  }

  return -1;
}

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

  // find the starting point
  int xStart, yStart;
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map.at(i).size(); j++) {
      if (map[i][j] == 'S') {
        xStart = j;
        yStart = i;
      }
    }
  }

  std::cout << findFewestSteps(map, point(xStart, yStart, 0)) << "\n";
}