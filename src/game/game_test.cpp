#include "game.h"
#include "../matrices/cyclic_matrix.h"
#include <gtest/gtest.h>

class GameOfLifeTest : public GameOfLife, public testing::Test {
 protected:
  void SetUp() override {
    {
      // 8 by 3 matrix with normal alive cells placement at center
      auto vec = std::vector<std::vector<NCellType>>{
          {NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Dead, NCellType::Alive, NCellType::Dead},
          {NCellType::Dead, NCellType::Alive, NCellType::Dead},
          {NCellType::Dead, NCellType::Alive, NCellType::Dead},
          {NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Dead, NCellType::Dead, NCellType::Dead},
      };
      testStateNormal = vec;
    }
    {
      // 7 by 4 matrix with alive cells placement at the left edge
      auto vec = std::vector<std::vector<NCellType>>{
          {NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
          {NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
      };
      testStateEdging = vec;
    }
  }

  CyclicMatrix<NCellType> testStateNormal;
  CyclicMatrix<NCellType> testStateEdging;
};

TEST_F(GameOfLifeTest, GetCellNextStateCasual) {
  EXPECT_EQ(NCellType::Alive, GetCellNextState(3, 0, testStateNormal)); // new live left
  EXPECT_EQ(NCellType::Alive, GetCellNextState(3, 2, testStateNormal)); // new live right
  EXPECT_EQ(NCellType::Alive, GetCellNextState(3, 1, testStateNormal)); // old life live center
  EXPECT_EQ(NCellType::Dead, GetCellNextState(2, 1, testStateNormal)); // old life die top
  EXPECT_EQ(NCellType::Dead, GetCellNextState(4, 1, testStateNormal)); // old life die bottom

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(NCellType::Dead, GetCellNextState(i, j, testStateNormal)); // random cells dont change state

      auto oppositeI = testStateNormal.Rows() - i;
      auto oppositeJ = testStateNormal.Columns() - j;

      EXPECT_EQ(NCellType::Dead, GetCellNextState(oppositeI, oppositeJ, testStateNormal)); // random cells dont change state
    }
  }

  EXPECT_EQ(NCellType::Dead, GetCellNextState(2, 0, testStateNormal)); // random cells dont change state
  EXPECT_EQ(NCellType::Dead, GetCellNextState(4, 2, testStateNormal)); // random cells dont change state
}

TEST_F(GameOfLifeTest, GetCellNextStateEdging) {
  EXPECT_EQ(NCellType::Alive, GetCellNextState(3, -1, testStateEdging)); // new live left (negative column)
  EXPECT_EQ(NCellType::Alive, GetCellNextState(3, 3, testStateEdging)); // new live left (positive column)
  EXPECT_EQ(NCellType::Alive, GetCellNextState(3, 0, testStateEdging)); // old life live center
  EXPECT_EQ(NCellType::Dead, GetCellNextState(2, 0, testStateEdging)); // old life die top
}