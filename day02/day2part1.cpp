#include <fstream>
#include <iostream>
#include <string>
int main(int argc, char** argv) {
  std::ifstream file("day2.txt");
  std::string line;
  int totalscore = 0;

  while (getline(file, line)) {
    int roundscore = 0;

    if (line.at(2) == 'X') {
      roundscore += 1;
    } else if (line.at(2) == 'Y') {
      roundscore += 2;
    } else if (line.at(2) == 'Z') {
      roundscore += 3;
    }

    if ((line.at(0) == 'A' && line.at(2) == 'Y') ||
        (line.at(0) == 'B' && line.at(2) == 'Z') ||
        (line.at(0) == 'C' && line.at(2) == 'X')) {
      roundscore += 6;
    } else if ((line.at(0) == 'A' && line.at(2) == 'X') ||
               (line.at(0) == 'B' && line.at(2) == 'Y') ||
               (line.at(0) == 'C' && line.at(2) == 'Z')) {
      roundscore += 3;
    }

    totalscore += roundscore;
  }
  std::cout << totalscore << "\n";
}