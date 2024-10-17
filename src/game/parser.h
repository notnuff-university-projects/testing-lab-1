#ifndef LAB1_SRC_PARSER_PARSER_H_
#define LAB1_SRC_PARSER_PARSER_H_

#include "../matrices/matrix.h"
#include "cells_types.h"

class FileParser {
  Matrix<NCellType> ParseGameField(const std::string &filePath);
};

#endif //LAB1_SRC_PARSER_PARSER_H_
