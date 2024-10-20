#ifndef LAB1_SRC_GAME_GAME_H_
#define LAB1_SRC_GAME_GAME_H_

#include <vector>
#include "../matrices/cyclic_matrix.h"
#include "cells_types.h"

class GameOfLife {
 public:
  CyclicMatrix<NCellType> GetNextState(const CyclicMatrix<NCellType>& currentState);
  void WriteState(const CyclicMatrix<NCellType>& state);

  const std::vector<CyclicMatrix<NCellType>>& History();

 protected:
  int GetNeighboursCount(int row, int column, const CyclicMatrix<NCellType>& gameField);

 protected:
  NCellType GetCellNextState(int row, int column, const CyclicMatrix<NCellType>& currentState);

 protected:
  std::vector<CyclicMatrix<NCellType>> history_;
};

#endif //LAB1_SRC_GAME_GAME_H_
