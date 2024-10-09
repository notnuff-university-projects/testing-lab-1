#include <gtest/gtest.h>
#include <fstream>

int main(int argc, char **argv) {

  // todo: normal parsing
  std::string testFile;

  if(argc > 1) {
    testFile = argv[1];
  } else {
    testFile = "./rsc/test-input.txt";
  }


  std::ifstream file;
  file.open(testFile);
  std::string currentLine;

  std::getline(file, currentLine);
  std::istringstream iss(currentLine);
  int numOfGenerations;
  iss >> numOfGenerations;

  std::getline(file, currentLine);
  iss = std::istringstream(currentLine);

  int cols, rows;
  iss >> cols >> rows;

  // todo: normal matrix class (circular)
  std::vector<std::vector<bool>> gameField(rows);
//  for(auto &row : gameField) row.resize(cols);


  auto currentRow = gameField.begin();
  while(std::getline(file, currentLine)) {
    for(const auto& currChar : currentLine) {
      // todo: some kind of map?
      if(currChar == '.') {
        currentRow->push_back(false);
      } else if(currChar == 'x') {
        currentRow->push_back(true);
      } else {
        std::stringstream fmt;
        fmt << "Unknown character: " << + currChar;
        throw std::invalid_argument(fmt.str());
      }
    }
    ++currentRow;
  }

  for(const auto& currRow : gameField) {
    for(const auto& currElement : currRow) {
      std::cout << std::setw(2) << currElement;
    }
    std::cout << '\n';
  }

  return 0;
}