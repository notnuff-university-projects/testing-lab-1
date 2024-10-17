#ifndef LAB1__MATRIX_H_
#define LAB1__MATRIX_H_

#include <vector>
#include <stdexcept>
#include <sstream>
#include <functional>

// the basic matrix class, providing easy two-dimensional array

// this Martix class is based onto single std::vector,
// so basically it should be faster than simple vector of vectors
// also, with this class, there is no need to
// worry about inconsistent sizes of vectors

// note - any resizing of already filled Matrix will invalidate its existing elements

// WARNING: don`t ever use bool as type for this matrix
// as it would fuck all up

template<typename ValueType>
class ProxyBracketHelper;

template<typename ValueType>
class Matrix {
 public:
  Matrix();
  Matrix(Matrix&& other) noexcept;
  Matrix& operator=(Matrix&& other) noexcept;

  Matrix(unsigned int rows, unsigned int columns);
  virtual ~Matrix()=default;

  void Rows(unsigned int count);
  unsigned int Rows();

  void Columns(unsigned int count);
  unsigned int Columns();

  ValueType Select(unsigned int row, unsigned int column);
  virtual ValueType& SelectRef(unsigned int row, unsigned int column);
  ValueType Select(unsigned int element_number);
  virtual ValueType& SelectRef(unsigned int element_number);

  bool IsOutOfBounds(unsigned int row, unsigned int column);

  ProxyBracketHelper<ValueType>& operator[] (unsigned int row);

 protected:
  void Recalculate();

  unsigned int rows_;
  unsigned int columns_;

  ProxyBracketHelper<ValueType> helper_;

  std::vector<ValueType> one_dimension_vector_;
};

template<typename ValueType>
class ProxyBracketHelper {
  public:
  ProxyBracketHelper()=delete;

  explicit ProxyBracketHelper(Matrix<ValueType>* matrix_p)
      : owner_matrix_(matrix_p), current_row_(0) {}

  void SetRow(const unsigned int row) {
    current_row_ = row;
  }

  ValueType& operator[] (const unsigned int column) {
    return owner_matrix_->SelectRef(current_row_, column);
  };

 protected:
  Matrix<ValueType>* owner_matrix_;
  unsigned int current_row_;
};

#include "matrix.inl"

#endif //LAB1__MATRIX_H_
