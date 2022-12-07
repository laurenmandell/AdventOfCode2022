#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
int main(int argc, char** argv) {
  std::stack<char> stack1, stack2, stack3, stack4, stack5, stack6, stack7,
      stack8, stack9;
  std::vector<std::stack<char>> stacks = {
      stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9};
  std::vector<std::string> strings = {"DLVTMHF",  "HQGJCTNP", "RSDMPH",
                                      "LBVF",     "NHGLQ",    "WBDGRMP",
                                      "GMNRCHLQ", "CLW",      "RDLQJZMT"};
  for (int i = 0; i < strings.size(); i++) {
    for (int j = 0; j < strings.at(i).length(); j++) {
      stacks.at(i).push(strings.at(i).at(j));
    }
  }

  std::ifstream file("day5.txt");
  std::string line;
  while (getline(file, line)) {
    std::string numStr;
    std::string fromStackStr;
    std::string toStackStr;
    std::string garbage;
    std::stringstream ss(line);
    std::getline(ss, garbage, ' ');
    std::getline(ss, numStr, ' ');
    std::getline(ss, garbage, ' ');
    std::getline(ss, fromStackStr, ' ');
    std::getline(ss, garbage, ' ');
    std::getline(ss, toStackStr, '\n');
    int num = stoi(numStr);
    int fromStack = stoi(fromStackStr);
    int toStack = stoi(toStackStr);
    std::stack<char> tempStack;
    for (int i = 0; i < num; i++) {
      tempStack.push(stacks.at(fromStack - 1).top());
      stacks.at(fromStack - 1).pop();
    }
    for (int i = 0; i < num; i++) {
      stacks.at(toStack - 1).push(tempStack.top());
      tempStack.pop();
    }
  }
  for (int i = 0; i < stacks.size(); i++) {
    std::cout << stacks.at(i).top();
  }
  std::cout << "\n";
}