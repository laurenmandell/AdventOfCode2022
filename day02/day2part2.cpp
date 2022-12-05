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
      if (line.at(0) == 'A') {
        roundscore += 3;
      } else if (line.at(0) == 'B') {
        roundscore += 1;
      } else if (line.at(0) == 'C') {
        roundscore += 2;
      }
    } else if (line.at(2) == 'Y') {
      if (line.at(0) == 'A') {
        roundscore += 4;
      } else if (line.at(0) == 'B') {
        roundscore += 5;
      } else if (line.at(0) == 'C') {
        roundscore += 6;
      }
    } else if (line.at(2) == 'Z') {
      if (line.at(0) == 'A') {
        roundscore += 8;
      } else if (line.at(0) == 'B') {
        roundscore += 9;
      } else if (line.at(0) == 'C') {
        roundscore += 7;
      }
    }

    totalscore += roundscore;
  }
  std::cout << totalscore << "\n";
}