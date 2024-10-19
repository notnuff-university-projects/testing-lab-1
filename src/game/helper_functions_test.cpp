#include <gtest/gtest.h>
#include "helper_functions_test.h"

void CompareMatrices(CyclicMatrix<NCellType>& m1, CyclicMatrix<NCellType>& m2) {
  // first check dimensions
  ASSERT_EQ(m1.Columns(), m2.Columns());
  ASSERT_EQ(m1.Rows(), m2.Rows());

  for(int i = 0; i < m1.Rows(); ++i) {
    for(int j = 0; j < m1.Columns(); ++j) {
      EXPECT_EQ(m1[i][j], m2[i][j]) << "row: " << i << " column: " << j;
    }
  }
}
