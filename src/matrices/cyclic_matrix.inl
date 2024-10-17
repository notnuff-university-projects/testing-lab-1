#ifndef LAB1__CYCLIC_MATRIX_INL_
#define LAB1__CYCLIC_MATRIX_INL_

#include "cyclic_matrix.h"

template<typename ValueType>
ValueType& CyclicMatrix<ValueType>::SelectRef(unsigned int element_number) {
  element_number %= this->rows_ * this->cols_;
  return Matrix<ValueType>::SelectRef(element_number);
}

template<typename ValueType>
ValueType& CyclicMatrix<ValueType>::SelectRef(unsigned int row, unsigned int column) {
  row %= this->rows_;
  column %= this->columns_;
  return Matrix<ValueType>::SelectRef(row, column);
}

#endif //LAB1__CYCLIC_MATRIX_INL_
