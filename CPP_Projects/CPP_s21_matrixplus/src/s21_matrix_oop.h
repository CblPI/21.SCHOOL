#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_
#include <cmath>
#include <cstring>
#include <exception>
#include <iostream>
class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_ = nullptr;
  S21Matrix minor_matrix(int row, int col);
  int priority_rows(int rows, int flag);
  int priority_cols(int cols, int flag);
  void del_matrix();
  void new_matrix(int rows, int cols);

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();
  bool eq_matrix(const S21Matrix& other);
  void sum_matrix(const S21Matrix& other);
  void sub_matrix(const S21Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& other);
  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

  S21Matrix operator+(S21Matrix right);
  S21Matrix operator-(S21Matrix right);
  S21Matrix operator*(S21Matrix right);
  S21Matrix operator*(double right);
  S21Matrix operator=(S21Matrix cpy);
  S21Matrix operator+=(S21Matrix cpy);
  S21Matrix operator-=(S21Matrix cpy);
  S21Matrix operator*=(S21Matrix cpy);
  S21Matrix operator*=(double cpy);
  double operator()(int row, int col);
  bool operator==(S21Matrix right);

  void set_value_by_Index(int row, int col, double val);

  int get_rows() const { return rows_; }
  int get_cols() const { return cols_; }

  void set_rows(int rows);
  void set_cols(int cols);
};

S21Matrix operator*(double left, S21Matrix right);

#endif  // SRC_S21_MATRIX_OOP_H_
