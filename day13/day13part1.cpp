#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "json.hpp"

// returns 1 if the values are in the RIGHT order
// returns 0 if the values are EQUAL
// returns -1 if the values are in the WRONG order
int compareValues(const nlohmann::json &json1, const nlohmann::json &json2) {
  std::string type1 = json1.type_name();
  std::string type2 = json2.type_name();

  if (type1.compare("array") == 0 && type2.compare("array") == 0) {
    // both are lists
    for (int i = 0; i < json1.size(); i++) {
      if (json2.size() <= i) {  // right list ran out of items
        return -1;
      } else if (compareValues(json1.at(i), json2.at(i)) == -1) {
        return -1;
      } else if (compareValues(json1.at(i), json2.at(i)) == 1) {
        return 1;
      }
    }
    if (json2.size() > json1.size()) {  //  check if left list ran out of items
      return 1;
    }

  } else if (type1.compare("array") == 0 && type2.compare("number") == 0) {
    // json1 is an array and json2 is a number
    std::vector<int> json2Vector;  // convert the integer to a list
    json2Vector.push_back(json2);
    return compareValues(json1, json2Vector);

  } else if (type1.compare("number") == 0 && type2.compare("array") == 0) {
    // json1 is a number and json2 is an array
    std::vector<int> json1Vector;  // convert the integer to a list
    json1Vector.push_back(json1);
    return compareValues(json1Vector, json2);

  } else if (type1.compare("number") == 0 && type2.compare("number") == 0) {
    // both are integers
    if (json1 > json2) {
      return -1;
    } else if (json1 < json2) {
      return 1;
    }
  }

  return 0;  // the values are equal
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

    if (compareValues(json1, json2) == 1) {
      sum += index;
    }

    index++;
  }

  std::cout << sum << "\n";
}
