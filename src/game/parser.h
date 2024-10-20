#ifndef LAB1_SRC_PARSER_PARSER_H_
#define LAB1_SRC_PARSER_PARSER_H_

#include "../matrices/cyclic_matrix.h"
#include "cells_types.h"
#include "game.h"

class FileParser {
 public:
  using GenerationsAndField = std::pair<int, CyclicMatrix<NCellType>>;
  GenerationsAndField ParseGameInput(const std::string &filePath);
  bool WriteGameOutput(GameOfLife &game, const std::string &filePath);
};

#endif //LAB1_SRC_PARSER_PARSER_H_
