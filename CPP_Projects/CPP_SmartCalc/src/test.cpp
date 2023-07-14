#include <gtest/gtest.h>

#include <iostream>

#include "s21_matrix_oop.h"

TEST(CopyConstructor, first) {
  S21Matrix a;
  S21Matrix b(a);
  bool referense = true;
  bool result = a.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(CopyConstructor, second) {
  S21Matrix a;
  a.set_value_by_Index(0, 0, 0.46453);
  a.set_value_by_Index(0, 1, 2.46453);
  a.set_value_by_Index(1, 0, 13.46453);
  a.set_value_by_Index(1, 1, 33.453);
  S21Matrix b(a);
  bool referense = true;
  bool result = a.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(MoveConstructor, first) {
  S21Matrix a;
  S21Matrix b(a);
  S21Matrix c = std::move(a);
  bool referense = true;
  bool result = c.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(MoveConstructor, second) {
  S21Matrix a;
  a.set_value_by_Index(0, 0, 0.46453);
  a.set_value_by_Index(0, 1, 2.46453);
  a.set_value_by_Index(1, 0, 13.46453);
  a.set_value_by_Index(1, 1, 33.453);
  S21Matrix b(a);
  S21Matrix c = std::move(a);
  bool referense = true;
  bool result = c.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(Equal, eq1) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 1);
  a.set_value_by_Index(0, 0, 7.8765);
  b.set_value_by_Index(0, 0, 7.8765);
  bool referense = true;
  bool result = a.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(Equal, eq2) {
  S21Matrix a;
  S21Matrix b;
  bool referense = true;
  ASSERT_EQ(a == b, referense);
}

TEST(Equal, eq3) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 1);
  a.set_value_by_Index(0, 0, 7.8766);
  b.set_value_by_Index(0, 0, 7.8765);
  bool referense = false;
  bool result = a.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(Equal, eq4) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 2);
  a.set_value_by_Index(0, 0, 7.8766);
  b.set_value_by_Index(0, 0, 7.8765);
  b.set_value_by_Index(0, 1, 7.8765);
  bool referense = false;
  bool result = a.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(Sum, first) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 10);
  b.set_value_by_Index(0, 1, 2.31);
  b.set_value_by_Index(1, 0, -5);
  b.set_value_by_Index(1, 1, 8);

  c.set_value_by_Index(0, 0, 22);
  c.set_value_by_Index(0, 1, 10);
  c.set_value_by_Index(1, 0, -10);
  c.set_value_by_Index(1, 1, 10);
  a.sum_matrix(b);
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(Sum, second) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 10);
  b.set_value_by_Index(0, 1, 2.31);
  b.set_value_by_Index(1, 0, -5);
  b.set_value_by_Index(1, 1, 8);

  c.set_value_by_Index(0, 0, 22);
  c.set_value_by_Index(0, 1, 10);
  c.set_value_by_Index(1, 0, -10);
  c.set_value_by_Index(1, 1, 10);
  a = a + b;
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(Sum, third) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 10);
  b.set_value_by_Index(0, 1, 2.31);
  b.set_value_by_Index(1, 0, -5);
  b.set_value_by_Index(1, 1, 8);

  c.set_value_by_Index(0, 0, 22);
  c.set_value_by_Index(0, 1, 10);
  c.set_value_by_Index(1, 0, -10);
  c.set_value_by_Index(1, 1, 10);
  a += b;
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(Sum, fourth) {
  S21Matrix a(2, 2);
  S21Matrix b(1, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 10);
  b.set_value_by_Index(0, 1, 2.31);

  ASSERT_THROW(a.sum_matrix(b), std::runtime_error);
}

TEST(Sub, first) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 10);
  b.set_value_by_Index(0, 1, 7.69);
  b.set_value_by_Index(1, 0, -5);
  b.set_value_by_Index(1, 1, 8);

  c.set_value_by_Index(0, 0, 2);
  c.set_value_by_Index(0, 1, 0);
  c.set_value_by_Index(1, 0, 0);
  c.set_value_by_Index(1, 1, -6);
  a.sub_matrix(b);
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(Sub, second) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 10);
  b.set_value_by_Index(0, 1, 7.69);
  b.set_value_by_Index(1, 0, -5);
  b.set_value_by_Index(1, 1, 8);

  c.set_value_by_Index(0, 0, 2);
  c.set_value_by_Index(0, 1, 0);
  c.set_value_by_Index(1, 0, 0);
  c.set_value_by_Index(1, 1, -6);
  a = a - b;
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(Sub, third) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 10);
  b.set_value_by_Index(0, 1, 7.69);
  b.set_value_by_Index(1, 0, -5);
  b.set_value_by_Index(1, 1, 8);

  c.set_value_by_Index(0, 0, 2);
  c.set_value_by_Index(0, 1, 0);
  c.set_value_by_Index(1, 0, 0);
  c.set_value_by_Index(1, 1, -6);
  a -= b;
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(Sub, fourth) {
  S21Matrix a(2, 2);
  S21Matrix b(1, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 10);
  b.set_value_by_Index(0, 1, 2.31);

  ASSERT_THROW(a.sub_matrix(b), std::runtime_error);
}

TEST(MulNum, first) {
  S21Matrix a(2, 2);
  double mul = 10;
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  c.set_value_by_Index(0, 0, 120);
  c.set_value_by_Index(0, 1, 76.9);
  c.set_value_by_Index(1, 0, -50);
  c.set_value_by_Index(1, 1, 20);
  a.mul_number(mul);
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(MulNum, second) {
  S21Matrix a(2, 2);
  double mul = 10;
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  c.set_value_by_Index(0, 0, 120);
  c.set_value_by_Index(0, 1, 76.9);
  c.set_value_by_Index(1, 0, -50);
  c.set_value_by_Index(1, 1, 20);
  a = a * mul;
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(MulNum, third) {
  S21Matrix a(2, 2);
  double mul = 10;
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.69);
  a.set_value_by_Index(1, 0, -5);
  a.set_value_by_Index(1, 1, 2);

  c.set_value_by_Index(0, 0, 120);
  c.set_value_by_Index(0, 1, 76.9);
  c.set_value_by_Index(1, 0, -50);
  c.set_value_by_Index(1, 1, 20);
  a *= mul;
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(mul_matrix, first) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);
  a.set_value_by_Index(1, 0, 6.7);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 5);
  b.set_value_by_Index(0, 1, 7);
  b.set_value_by_Index(1, 0, 1);
  b.set_value_by_Index(1, 1, 0);

  c.set_value_by_Index(0, 0, 175);
  c.set_value_by_Index(0, 1, 238);
  c.set_value_by_Index(1, 0, 35.5);
  c.set_value_by_Index(1, 1, 46.9);
  a.mul_matrix(b);
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(mul_matrix, second) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);
  a.set_value_by_Index(1, 0, 6.7);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 5);
  b.set_value_by_Index(0, 1, 7);
  b.set_value_by_Index(1, 0, 1);
  b.set_value_by_Index(1, 1, 0);

  c.set_value_by_Index(0, 0, 175);
  c.set_value_by_Index(0, 1, 238);
  c.set_value_by_Index(1, 0, 35.5);
  c.set_value_by_Index(1, 1, 46.9);
  a = a * b;
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(mul_matrix, third) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);
  a.set_value_by_Index(1, 0, 6.7);
  a.set_value_by_Index(1, 1, 2);

  b.set_value_by_Index(0, 0, 5);
  b.set_value_by_Index(0, 1, 7);
  b.set_value_by_Index(1, 0, 1);
  b.set_value_by_Index(1, 1, 0);

  c.set_value_by_Index(0, 0, 175);
  c.set_value_by_Index(0, 1, 238);
  c.set_value_by_Index(1, 0, 35.5);
  c.set_value_by_Index(1, 1, 46.9);
  a *= b;
  bool referense = true;
  bool result = c.eq_matrix(a);
  ASSERT_EQ(result, referense);
}

TEST(mul_matrix, fourth) {
  S21Matrix a(2, 1);
  S21Matrix b(1, 2);

  a.set_value_by_Index(0, 0, 2);
  a.set_value_by_Index(1, 0, 2);

  b.set_value_by_Index(0, 0, 2);
  b.set_value_by_Index(0, 1, 2);

  a = a * b;

  ASSERT_EQ(a(0, 0), 4);
}

TEST(transpose, first) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);
  a.set_value_by_Index(1, 0, 6.7);
  a.set_value_by_Index(1, 1, 2);

  c.set_value_by_Index(0, 0, 34);
  c.set_value_by_Index(0, 1, 6.7);
  c.set_value_by_Index(1, 0, 5);
  c.set_value_by_Index(1, 1, 2);
  b = a.transpose();
  bool referense = true;
  bool result = c.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(Complements, first) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);
  a.set_value_by_Index(1, 0, 6.7);
  a.set_value_by_Index(1, 1, 2);

  c.set_value_by_Index(0, 0, 2);
  c.set_value_by_Index(0, 1, -6.7);
  c.set_value_by_Index(1, 0, -5);
  c.set_value_by_Index(1, 1, 34);
  b = a.calc_complements();
  bool referense = true;
  bool result = c.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(Complements, second) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 1);
  S21Matrix c(1, 1);

  a.set_value_by_Index(0, 0, 34);

  c.set_value_by_Index(0, 0, 34);
  b = a.calc_complements();
  bool referense = true;
  bool result = c.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(Complements, third) {
  S21Matrix a(1, 2);
  S21Matrix b(1, 2);

  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);

  ASSERT_THROW(a.calc_complements(), std::runtime_error);
}

TEST(determinant, first) {
  S21Matrix a(2, 2);
  double determ;
  double referense = 34.5;

  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);
  a.set_value_by_Index(1, 0, 6.7);
  a.set_value_by_Index(1, 1, 2);

  determ = a.determinant();
  ASSERT_EQ(determ, referense);
}

TEST(determinant, second) {
  S21Matrix a(3, 3);
  double determ;
  double referense = -3772.7;

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.9);
  a.set_value_by_Index(0, 2, 3);
  a.set_value_by_Index(1, 0, 37);
  a.set_value_by_Index(1, 1, 21);
  a.set_value_by_Index(1, 2, -6);
  a.set_value_by_Index(2, 0, 5);
  a.set_value_by_Index(2, 1, 2);
  a.set_value_by_Index(2, 2, 89);

  determ = a.determinant();
  ASSERT_DOUBLE_EQ(determ, referense);
}

TEST(determinant, third) {
  S21Matrix a(1, 2);

  a.set_value_by_Index(0, 0, 12);
  a.set_value_by_Index(0, 1, 7.9);

  ASSERT_THROW(a.determinant(), std::runtime_error);
}

TEST(Inverse, first) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);
  a.set_value_by_Index(1, 0, 6.7);
  a.set_value_by_Index(1, 1, 2);

  c.set_value_by_Index(0, 0, 4.0 / 69);
  c.set_value_by_Index(0, 1, -10.0 / 69);
  c.set_value_by_Index(1, 0, -67.0 / 345);
  c.set_value_by_Index(1, 1, 68.0 / 69);
  b = a.inverse_matrix();
  bool referense = true;
  bool result = c.eq_matrix(b);
  ASSERT_EQ(result, referense);
}

TEST(Inverse, second) {
  S21Matrix a(2, 2);
  ASSERT_THROW(a.inverse_matrix(), std::runtime_error);
}

TEST(GetValue, first) {
  S21Matrix a(2, 2);
  double check;
  a.set_value_by_Index(0, 0, 34);
  a.set_value_by_Index(0, 1, 5);
  a.set_value_by_Index(1, 0, 6.7);
  a.set_value_by_Index(1, 1, 2);
  check = a(0, 1);
  double referense = 5;
  ASSERT_EQ(check, referense);
}

TEST(SetValue, first) {
  S21Matrix a(1, 1);
  ASSERT_THROW(a.set_value_by_Index(5, 5, 5), std::runtime_error);
}

TEST(set_rows, first) {
  S21Matrix a(2, 2);
  a.set_rows(1);
  ASSERT_THROW(a.set_value_by_Index(1, 1, 5), std::runtime_error);
}

TEST(set_cols, first) {
  S21Matrix a(2, 2);
  a.set_cols(1);
  ASSERT_THROW(a.set_value_by_Index(1, 1, 5), std::runtime_error);
}

TEST(operator, first) {
  S21Matrix a(2, 2);
  ASSERT_EQ(a(1, 1), 0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
