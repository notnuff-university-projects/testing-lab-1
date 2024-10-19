#include <fstream>
#include "parser.h"

std::pair<int, CyclicMatrix<NCellType>> FileParser::ParseGameInput(const std::string &filePath) {
  std::ifstream file;
  file.open(filePath);
  std::string currentLine;

  std::getline(file, currentLine);
  std::istringstream iss(currentLine);
  int numOfGenerations;
  iss >> numOfGenerations;

  std::getline(file, currentLine);
  iss = std::istringstream(currentLine);

  int cols, rows;
  iss >> cols >> rows;

  // todo: normal Matrix class (circular)
  CyclicMatrix<NCellType> gameField(rows, cols);

  for(int i = 0; i < rows; ++i) {
    if( !std::getline(file, currentLine) ) break;
    for(int j = 0; j < currentLine.size(); ++j) {
      char currChar = currentLine[j];
      if(currChar == '.') {
        gameField[i][j] = NCellType::Dead;
      } else if(currChar == 'x') {
        gameField[i][j] = NCellType::Alive;
      } else {
        std::stringstream fmt;
        fmt << "Unknown character: " << currChar;
        throw std::invalid_argument(fmt.str());
      }
    }
  }

  return {numOfGenerations, gameField};
}
