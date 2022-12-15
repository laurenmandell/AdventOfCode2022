#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Monkey {
 public:
  Monkey(std::vector<int> items_, char operation_, std::string operationNum_,
         int divisibleBy_, int trueThrow_, int falseThrow_) {
    items = items_;
    operation = operation_;
    operationNum = operationNum_;
    divisibleBy = divisibleBy_;
    trueThrow = trueThrow_;
    falseThrow = falseThrow_;
    numInspected = 0;
  }
  std::vector<int> getItems() { return items; }
  char getOperation() { return operation; }
  std::string getOperationNum() { return operationNum; }
  int getDivisibleBy() { return divisibleBy; }
  int getTrueThrow() { return trueThrow; }
  int getFalseThrow() { return falseThrow; }
  int getNumInspected() { return numInspected; }
  void incrementNumInspected() { numInspected++; }
  void addItem(int worryLevel) { items.push_back(worryLevel); }
  void removeItem() { items.erase(items.begin()); }

 private:
  std::vector<int> items;
  char operation;
  std::string operationNum;
  int divisibleBy;
  int trueThrow;
  int falseThrow;
  int numInspected;
};

int main() {
  std::ifstream file("day11.txt");
  std::string line;
  std::string garbage;
  std::vector<Monkey> monkeys;

  while (getline(file, line)) {
    if (line.substr(0, 6).compare("Monkey") == 0) {
      // get starting items
      getline(file, line);
      std::vector<int> curItems;
      line = line.substr(2, line.length() - 2);  // get rid of leading spaces
      std::stringstream ss1(line);
      getline(ss1, garbage, ' ');
      getline(ss1, garbage, ' ');
      std::string curItemStr;
      while (getline(ss1, curItemStr, ',') || getline(ss1, curItemStr, '\n')) {
        curItems.push_back(std::stoi(curItemStr));
      }
      // get operation
      getline(file, line);
      std::string curOperationStr;
      std::string curOperationNum;
      line = line.substr(2, line.length() - 2);  // get rid of leading spaces
      std::stringstream ss2(line);
      for (int i = 0; i < 4; i++) {
        getline(ss2, garbage, ' ');
      }
      getline(ss2, curOperationStr, ' ');
      getline(ss2, curOperationNum, '\n');
      char curOperation = curOperationStr.at(0);
      //  get test
      getline(file, line);
      std::string curDivisibleByStr;
      line = line.substr(2, line.length() - 2);  // get rid of leading spaces
      std::stringstream ss3(line);
      for (int i = 0; i < 3; i++) {
        getline(ss3, garbage, ' ');
      }
      getline(ss3, curDivisibleByStr, '\n');
      int curDivisibleBy = std::stoi(curDivisibleByStr);
      //  get if true
      getline(file, line);
      int curTrueThrow = line.at(line.length() - 1) - '0';
      //  get if false
      getline(file, line);
      int curFalseThrow = line.at(line.length() - 1) - '0';
      // make monkey object and push into vector of monkeys
      monkeys.push_back(Monkey(curItems, curOperation, curOperationNum,
                               curDivisibleBy, curTrueThrow, curFalseThrow));
    }
  }

  int numRounds = 20;
  for (int r = 0; r < numRounds; r++) {
    for (int m = 0; m < monkeys.size(); m++) {
      int curNumItems = monkeys.at(m).getItems().size();
      for (int i = 0; i < curNumItems; i++) {
        // monkey inspects item
        monkeys.at(m).incrementNumInspected();
        // get worry level
        int worryLevel = monkeys.at(m).getItems().front();
        // calculate new worry level
        if (monkeys.at(m).getOperation() == '+') {
          if (monkeys.at(m).getOperationNum().compare("old") != 0) {
            worryLevel += std::stoi(monkeys.at(m).getOperationNum());
          } else {
            worryLevel += worryLevel;
          }
        } else if (monkeys.at(m).getOperation() == '*') {
          if (monkeys.at(m).getOperationNum().compare("old") != 0) {
            worryLevel *= std::stoi(monkeys.at(m).getOperationNum());
          } else {
            worryLevel *= worryLevel;
          }
        }
        worryLevel = worryLevel / 3;
        // do test
        if (worryLevel % monkeys.at(m).getDivisibleBy() == 0) {
          monkeys.at(monkeys.at(m).getTrueThrow()).addItem(worryLevel);
        } else {
          monkeys.at(monkeys.at(m).getFalseThrow()).addItem(worryLevel);
        }
        monkeys.at(m).removeItem();
      }
    }
  }

  // find the two most active monkeys
  int mostInspected = 0;
  int secondMostInspected = 0;
  for (int i = 0; i < monkeys.size(); i++) {
    if (monkeys.at(i).getNumInspected() > mostInspected) {
      secondMostInspected = mostInspected;
      mostInspected = monkeys.at(i).getNumInspected();
    } else if (monkeys.at(i).getNumInspected() > secondMostInspected) {
      secondMostInspected = monkeys.at(i).getNumInspected();
    }
  }

  // print level of monkey business
  std::cout << mostInspected * secondMostInspected << "\n";
}