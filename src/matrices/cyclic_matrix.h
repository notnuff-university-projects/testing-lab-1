#ifndef LAB1__CYCLIC_MATRIX_H_
#define LAB1__CYCLIC_MATRIX_H_

#include <vector>
#include <stdexcept>
#include <sstream>

#include "matrix.h"

template<typename ValueType>
class CyclicMatrix : public Matrix<ValueType> {
 public:
  CyclicMatrix()=default;
  virtual ~CyclicMatrix()=default;

  ValueType& SelectRef(unsigned int row, unsigned int column) override;

  ValueType& SelectRef(unsigned int element_number) override;
};

#include "cyclic_matrix.inl"

#endif //LAB1__CYCLIC_MATRIX_H_
