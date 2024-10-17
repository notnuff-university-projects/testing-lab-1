#ifndef LAB1__MATRIX_INL
#define LAB1__MATRIX_INL

#include <vector>
#include <stdexcept>
#include <sstream>

template<typename ValueType>
ProxyBracketHelper<ValueType> &Matrix<ValueType>::operator[](const unsigned int row) {
  helper_.SetRow(row);
  return helper_;
}


template<typename ValueType>
Matrix<ValueType>::Matrix()
    : helper_(ProxyBracketHelper(this)),
      rows_(0), columns_(0) {

      }


template<typename ValueType>
Matrix<ValueType> &Matrix<ValueType>::operator=(Matrix &&other) noexcept {
  if (this != &other) {
    rows_ = other.rows_;
    columns_ = other.columns_;
    one_dimension_vector_ = std::move(other.one_dimension_vector_);
    helper_ = std::move(other.helper_);

// Invalidate the other matrix
    other.rows_ = 0;
    other.columns_ = 0;
  }
  return *this;
}


template<typename ValueType>
Matrix<ValueType>::Matrix(Matrix &&other) noexcept
    : rows_(other.rows_), columns_(other.columns_),
      one_dimension_vector_(std::move(other.one_dimension_vector_)),
      helper_(std::move(other.helper_)) {

  // Invalidate the other matrix
  other.rows_ = 0;
  other.columns_ = 0;
}


template<typename ValueType>
ValueType Matrix<ValueType>::Select(unsigned int element_number) {
  return SelectRef(element_number);
}

template<typename ValueType>
ValueType& Matrix<ValueType>::SelectRef(unsigned int element_number) {
  if( one_dimension_vector_.size() <= element_number ) {
    std::stringstream err;
    err << "Elements in matrix: " << rows_ * columns_
        << "Tried to access element number: " << element_number;

    throw std::out_of_range( err.str() );
  }

  return one_dimension_vector_[element_number];
}

template<typename ValueType>
bool Matrix<ValueType>::IsOutOfBounds(unsigned int row, unsigned int column) {
  if(rows_ <= row || columns_ <= column) return true;
  return false;
}

template<typename ValueType>
ValueType Matrix<ValueType>::Select(unsigned int row, unsigned int column) {
  return SelectRef(row, column);
}

template<typename ValueType>
ValueType& Matrix<ValueType>::SelectRef(unsigned int row, unsigned int column) {
  if( IsOutOfBounds(row, column) ) {
    std::stringstream err;
    err << "Matrix dimensions:" << "\n"
        << "rows=" << rows_ << " "
        << "columns=" << columns_ << "\n"
        << "Tried to access:" << "\n"
        << "row=" << row << " "
        << "column=" << column << "\n";
    throw std::out_of_range( err.str() );
  }

  return one_dimension_vector_[row * columns_ + column];
}

template<typename ValueType>
void Matrix<ValueType>::Columns(unsigned int count) {
  columns_ = count;
}

template<typename ValueType>
unsigned int Matrix<ValueType>::Columns() {
  return columns_;
}

template<typename ValueType>
unsigned int Matrix<ValueType>::Rows() {
  return rows_;
}

template<typename ValueType>
void Matrix<ValueType>::Rows(unsigned int count) {
  rows_ = count;
}

template<typename ValueType>
Matrix<ValueType>::Matrix(
    unsigned int rows,
    unsigned int columns)
    : helper_(this),
      rows_(rows), columns_(columns) {
  Recalculate();
}

template<typename ValueType>
void Matrix<ValueType>::Recalculate() {
  one_dimension_vector_.resize(rows_ * columns_);
}


#endif //LAB1__MATRIX_INL
