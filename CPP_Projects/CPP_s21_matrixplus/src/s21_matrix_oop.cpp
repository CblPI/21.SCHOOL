#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3) { new_matrix(rows_, cols_); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  new_matrix(rows_, cols_);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.get_rows()), cols_(other.get_cols()) {
  new_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++)
    std::memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.get_rows()), cols_(other.get_cols()) {
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  if (other.matrix_) del_matrix();
  other.rows_ = other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_) del_matrix();
  rows_ = cols_ = 0;
}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
  bool result = false;
  if (rows_ == other.get_rows() && cols_ == other.get_cols()) {
    result = true;
    for (int i = 0; i < get_rows() && result; i++) {
      for (int j = 0; j < get_cols() && result; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) result = false;
      }
    }
  }
  return result;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols())
    throw std::runtime_error("Error: sum_matrix! Wrong Matrix Size!");
  for (int i = 0; i < get_rows(); i++) {
    for (int j = 0; j < get_cols(); j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols())
    throw std::runtime_error("Error: sub_matrix! Wrong Matrix Size!");
  for (int i = 0; i < get_rows(); i++) {
    for (int j = 0; j < get_cols(); j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
  if (cols_ != other.get_rows())
    throw std::runtime_error("Error: mul_matrix! Wrong matrix");
  S21Matrix tmp = S21Matrix(rows_, other.get_cols());
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < other.get_cols(); j++) {
      double sum = 0.0;
      for (int k = 0; k < cols_; k++)
        sum += matrix_[i][k] * other.matrix_[k][j];
      tmp.matrix_[i][j] = sum;
    }
  new_matrix(rows_, other.get_cols());
  cols_ = other.get_cols();
  for (int i = 0; i < rows_; i++) {
    std::memcpy(matrix_[i], tmp.matrix_[i], cols_ * sizeof(double));
  }
}

S21Matrix S21Matrix::transpose() {
  S21Matrix result = S21Matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::calc_complements() {
  if (rows_ != cols_)
    throw std::runtime_error("Error: calc_complements! Only square matrix");
  S21Matrix result = S21Matrix(rows_, cols_);
  if (rows_ != 1) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix minor = minor_matrix(i, j);
        if (minor.determinant() == 0.) {
          result.matrix_[i][j] = 0;
        } else {
          result.matrix_[i][j] = minor.determinant() * pow(-1, i + j);
        }
      }
    }
  } else {
    result.matrix_[0][0] = matrix_[0][0];
  }
  return result;
}

double S21Matrix::determinant() {
  if (rows_ != cols_)
    throw std::runtime_error("Error: determinant! Only square matrix");
  double result = NAN;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    result = 0.0;
    S21Matrix tmp = calc_complements();
    for (int i = 0; i < cols_; i++) {
      result += matrix_[0][i] * tmp.matrix_[0][i];
    }
  }
  return result;
}

S21Matrix S21Matrix::inverse_matrix() {
  if (rows_ != cols_)
    throw std::runtime_error("Error: inverse_matrix!  Only square matrix");
  double det = determinant();
  if (det == 0.0)
    throw std::runtime_error("Error: inverse_matrix! determinant = 0");
  det = 1 / det;
  S21Matrix minor = calc_complements();
  S21Matrix trans = minor.transpose();
  trans.mul_number(det);
  return trans;
}

void S21Matrix::set_value_by_Index(int row, int col, double val) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0)
    throw std::runtime_error(
        "Error: set_value_by_Index! Index is out of range");
  matrix_[row][col] = val;
}

void S21Matrix::set_rows(int rows) {
  S21Matrix tmp = S21Matrix(rows, cols_);
  int r = 0;
  r = priority_rows(rows, r);
  for (int i = 0; i < r; i++)
    std::memcpy(tmp.matrix_[i], matrix_[i], cols_ * sizeof(double));
  new_matrix(rows, cols_);
  for (int i = 0; i < rows; i++)
    std::memcpy(matrix_[i], tmp.matrix_[i], cols_ * sizeof(double));
  rows_ = rows;
}

void S21Matrix::set_cols(int cols) {
  S21Matrix tmp = S21Matrix(rows_, cols);
  int c = 0;
  c = priority_cols(cols, c);
  for (int i = 0; i < rows_; i++)
    std::memcpy(tmp.matrix_[i], matrix_[i], c * sizeof(double));
  new_matrix(rows_, cols);
  for (int i = 0; i < rows_; i++)
    std::memcpy(matrix_[i], tmp.matrix_[i], c * sizeof(double));
  cols_ = cols;
}

void S21Matrix::del_matrix() {
  if (matrix_) {
    for (int count = 0; count < rows_; count++) delete[] matrix_[count];
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

void S21Matrix::new_matrix(int rows, int cols) {
  if (matrix_) del_matrix();
  matrix_ = new double*[rows];
  for (int count = 0; count < rows; count++)
    matrix_[count] = new double[cols]();
}

int S21Matrix::priority_rows(int rows, int flag) {
  if (rows_ > rows)
    flag = rows;
  else
    flag = rows_;
  return flag;
}

int S21Matrix::priority_cols(int cols, int flag) {
  if (cols_ > cols)
    flag = cols;
  else
    flag = cols_;
  return flag;
}

S21Matrix S21Matrix::minor_matrix(int row, int col) {
  S21Matrix minor = S21Matrix(rows_ - 1, cols_ - 1);
  for (int i = 0, g = 0; i < rows_; i++) {
    if (i != row) {
      for (int j = 0, h = 0; j < cols_; j++) {
        if (j != col) {
          minor.matrix_[g][h] = matrix_[i][j];
          h++;
        }
      }
      g++;
    }
  }
  return minor;
}

S21Matrix S21Matrix::operator+(S21Matrix right) {
  if (cols_ != right.get_cols() || rows_ != right.get_rows())
    throw std::out_of_range("Column or Row out of range!");
  S21Matrix result(rows_, cols_);
  result = *this;
  result.sum_matrix(right);
  return result;
}

S21Matrix S21Matrix::operator-(S21Matrix right) {
  if (cols_ != right.get_cols() || rows_ != right.get_rows())
    throw std::out_of_range("Column or Row out of range!");
  S21Matrix result(rows_, cols_);
  result.sum_matrix(*this);
  result.sub_matrix(right);
  return result;
}

S21Matrix S21Matrix::operator*(S21Matrix right) {
  S21Matrix result(rows_, cols_);
  result = *this;
  result.mul_matrix(right);
  return result;
}

S21Matrix S21Matrix::operator*(double right) {
  S21Matrix result(rows_, cols_);
  result = *this;
  result.mul_number(right);
  return result;
}

S21Matrix operator*(double left, S21Matrix right) { return right * left; }

bool S21Matrix::operator==(S21Matrix right) { return eq_matrix(right); }

S21Matrix S21Matrix::operator=(S21Matrix cpy) {
  if (this == &cpy) {
    return *this;
  }
  new_matrix(cpy.get_rows(), cpy.get_cols());
  rows_ = cpy.get_rows(), cols_ = cpy.get_cols();
  for (int i = 0; i < cpy.get_rows(); i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = cpy.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator+=(S21Matrix cpy) { return *this = *this + cpy; }

S21Matrix S21Matrix::operator-=(S21Matrix cpy) { return *this = *this - cpy; }

S21Matrix S21Matrix::operator*=(S21Matrix cpy) { return *this = *this * cpy; }

S21Matrix S21Matrix::operator*=(double cpy) { return *this = *this * cpy; }

double S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0)
    throw std::out_of_range("Column or Row out of range!");
  return matrix_[row][col];
}
