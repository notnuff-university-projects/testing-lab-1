#include "game.h"
#include "../matrices/cyclic_matrix.h"

CyclicMatrix<NCellType> GameOfLife::GetNextState(const CyclicMatrix<NCellType>& currentState) {
  auto rows = currentState.Rows();
  auto cols = currentState.Columns();
  CyclicMatrix<NCellType> result(rows, cols);

  for(int i = 0; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      result[i][j] = GetCellNextState(i, j, currentState);
    }
  }

  return result;
}


void GameOfLife::WriteState(const CyclicMatrix<NCellType> &state) {
  history_.push_back(state);
}

NCellType GameOfLife::GetCellNextState(int row, int column, const CyclicMatrix<NCellType> &currentState) {
  auto neighboursCount = GetNeighboursCount(row, column, currentState);
  auto currentCellState = currentState[row][column];

  if(currentCellState == NCellType::Dead && neighboursCount == 3) {
    return NCellType::Alive;
  } else if(currentCellState == NCellType::Alive && neighboursCount != 2 && neighboursCount != 3) {
    return NCellType::Dead;
  }
  return currentCellState;
}

int GameOfLife::GetNeighboursCount(int row, int column, const CyclicMatrix<NCellType> &gameField) {
  static const std::vector<std::pair<int, int>> displacements= {
      {-1, -1},
      {-1, 0},
      {-1, 1},
      {0, 1},
      {1, 1},
      {1, 0},
      {1, -1},
      {0, -1},

  };
  int neighboursCount = 0;
  for(const auto& ds : displacements) {
    if(gameField[row + ds.first][column + ds.second] != NNCellType::Alive) continue;
    neighboursCount++;
  }
  return neighboursCount;
}
const std::vector<CyclicMatrix<NCellType>> &GameOfLife::History() {
  return history_;
}
