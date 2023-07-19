#include <check.h>
#include <limits.h>

#include "s21_matrix.h"

START_TEST(matrix_create_0) {
  matrix_t test;
  int result = s21_create_matrix(2, 2, &test);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(matrix_create_1) {
  matrix_t test;
  int result = s21_create_matrix(0, 0, &test);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(eq_matrix_test1) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  int result = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(eq_matrix_test2) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  int result = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(eq_matrix_test3) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 1.0000001;
  matrix2.matrix[0][0] = 1.0000002;
  int result = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(eq_matrix_test4) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = -2.0;
  matrix2.matrix[0][0] = 2.0;
  int result = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(eq_matrix_test5) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(2, 3, &matrix2);
  int result = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(sum_matrix_test1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;
  int error_status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 6, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 8, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 10, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 12, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_test2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  int error_status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);
  int error_status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = -2;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  int error_status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 0, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_test5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = 2.2;
  B.matrix[0][0] = 3.3;
  B.matrix[0][1] = 4.4;
  int error_status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 4.4, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 6.6, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_test1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 6;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 8;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int error_status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 4, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 4, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 4, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 4, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_test2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  int error_status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_test3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);
  int error_status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_test4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = -2;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  int error_status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], -2, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], -4, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_test5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0.0000001;
  A.matrix[0][1] = 0.0000002;
  B.matrix[0][0] = 0.0000001;
  B.matrix[0][1] = 0.0000002;
  int error_status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 0, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test1) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  int error_status = s21_mult_number(&A, 2, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 2, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 4, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 6, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 8, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test2) {
  matrix_t A;
  matrix_t result;
  A.rows = 0;
  A.columns = 0;
  int error_status = s21_mult_number(&A, 2, &result);
  ck_assert_int_eq(error_status, 1);
}
END_TEST

START_TEST(mult_number_test3) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = -4;
  int error_status = s21_mult_number(&A, -1, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 1, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 2, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 3, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 4, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test4) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  int error_status = s21_mult_number(&A, 0, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 0, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test5) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = 2.5;
  A.matrix[1][0] = 3.5;
  A.matrix[1][1] = 4.5;
  int error_status = s21_mult_number(&A, 1.5, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 2.25, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 3.75, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 5.25, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 6.75, EPSILON);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test1) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;
  matrix2.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 0;
  matrix2.matrix[1][0] = 1;
  matrix2.matrix[1][1] = 2;
  matrix_t result;
  int error_status = s21_mult_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 4.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 10.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 8.0, EPSILON);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test2) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(3, 2, &matrix2);
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix2.matrix[0][0] = 7;
  matrix2.matrix[0][1] = 8;
  matrix2.matrix[1][0] = 9;
  matrix2.matrix[1][1] = 10;
  matrix2.matrix[2][0] = 11;
  matrix2.matrix[2][1] = 12;
  matrix_t result;
  int error_status = s21_mult_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(error_status, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 58.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], 64.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], 139.0, EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], 154.0, EPSILON);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test3) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  matrix_t result;
  int error_status = s21_mult_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(error_status, 2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(transpose_test1) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 1.0;
  s21_transpose(&matrix1, &result);
  ck_assert_int_eq(result.rows, matrix1.columns);
  ck_assert_int_eq(result.columns, matrix1.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], matrix1.matrix[0][0], EPSILON);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_test2) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix1);
  matrix1.matrix[0][0] = 1.0;
  matrix1.matrix[0][1] = 2.0;
  matrix1.matrix[1][0] = 3.0;
  matrix1.matrix[1][1] = 4.0;
  s21_transpose(&matrix1, &result);
  ck_assert_int_eq(result.rows, matrix1.columns);
  ck_assert_int_eq(result.columns, matrix1.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], matrix1.matrix[0][0], EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], matrix1.matrix[0][1], EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], matrix1.matrix[1][0], EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], matrix1.matrix[1][1], EPSILON);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_test3) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(3, 2, &matrix1);
  matrix1.matrix[0][0] = 1.0;
  matrix1.matrix[0][1] = 2.0;
  matrix1.matrix[1][0] = 3.0;
  matrix1.matrix[1][1] = 4.0;
  matrix1.matrix[2][0] = 5.0;
  matrix1.matrix[2][1] = 6.0;
  s21_transpose(&matrix1, &result);
  ck_assert_int_eq(result.rows, matrix1.columns);
  ck_assert_int_eq(result.columns, matrix1.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], matrix1.matrix[0][0], EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], matrix1.matrix[1][0], EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][2], matrix1.matrix[2][0], EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], matrix1.matrix[0][1], EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][1], matrix1.matrix[1][1], EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][2], matrix1.matrix[2][1], EPSILON);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_test4) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(1, 3, &matrix1);
  matrix1.matrix[0][0] = 1.0;
  matrix1.matrix[0][1] = 2.0;
  matrix1.matrix[0][2] = 3.0;
  s21_transpose(&matrix1, &result);
  ck_assert_int_eq(result.rows, matrix1.columns);
  ck_assert_int_eq(result.columns, matrix1.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], matrix1.matrix[0][0], EPSILON);
  ck_assert_double_eq_tol(result.matrix[1][0], matrix1.matrix[0][1], EPSILON);
  ck_assert_double_eq_tol(result.matrix[2][0], matrix1.matrix[0][2], EPSILON);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_test5) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(3, 1, &matrix1);
  matrix1.matrix[0][0] = 1.0;
  matrix1.matrix[1][0] = 2.0;
  matrix1.matrix[2][0] = 3.0;
  s21_transpose(&matrix1, &result);
  ck_assert_int_eq(result.rows, matrix1.columns);
  ck_assert_int_eq(result.columns, matrix1.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], matrix1.matrix[0][0], EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][1], matrix1.matrix[1][0], EPSILON);
  ck_assert_double_eq_tol(result.matrix[0][2], matrix1.matrix[2][0], EPSILON);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_determinant_1x1) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;
  double result;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert(fabs(result - 5) < EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_2x2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  double result;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert(fabs(result - (-2)) < EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_3x3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  double result;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert(fabs(result - 0) < EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_non_square_matrix) {
  matrix_t A;
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  double result;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant4) {
  matrix_t m;
  s21_create_matrix(3, 3, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, EPSILON);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant5) {
  matrix_t m;
  s21_create_matrix(3, 3, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, EPSILON);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant6) {
  matrix_t A;
  double res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  int result = s21_determinant(&A, &res);
  ck_assert_int_eq(res, 5);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}

START_TEST(determinant7) {
  matrix_t A;
  double res;
  s21_create_matrix(2, 6, &A);
  int result = s21_determinant(&A, &res);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
}

START_TEST(test_normal) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &m);
  int code2 = s21_create_matrix(3, 3, &expected);
  if (!code1 && !code2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, 0);
    s21_remove_matrix(&m);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(s21_calc_compl_2) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t res = {0};
  s21_create_matrix(3, 3, &res);
  matrix_t m;
  res.matrix[0][0] = 0;
  res.matrix[0][1] = 10;
  res.matrix[0][2] = -20;
  res.matrix[1][0] = 4;
  res.matrix[1][1] = -14;
  res.matrix[1][2] = 8;
  res.matrix[2][0] = -8;
  res.matrix[2][1] = -2;
  res.matrix[2][2] = 4;

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 2;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 1;
  s21_calc_complements(&a, &m);
  ck_assert_int_eq(s21_eq_matrix(&res, &m), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_calc_compl_3) {
  matrix_t a = {0};
  s21_create_matrix(1, 3, &a);
  matrix_t res = {0};
  s21_create_matrix(1, 3, &res);
  int status = s21_calc_complements(&a, &res);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&res);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_inverse_matrix_null) {
  matrix_t *A = NULL;
  matrix_t *result = NULL;
  int ret = s21_inverse_matrix(A, result);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(test_inverse_matrix_non_square) {
  matrix_t A = {.rows = 3, .columns = 2};
  matrix_t result;
  int ret = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_inverse_1) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_transpose_error_handling) {
  matrix_t error_matrix;
  error_matrix.rows = 0;
  error_matrix.columns = 5;
  matrix_t result_matrix;
  int transpose_result = s21_transpose(&error_matrix, &result_matrix);
  ck_assert_int_eq(transpose_result, 1);
}
END_TEST

START_TEST(test_s21_inverse_matrix_error_handling) {
  // Создание некорректной матрицы (например, сингулярной, т.е. матрицы,
  // определитель которой равен 0)
  matrix_t singular_matrix;
  s21_create_matrix(2, 2, &singular_matrix);
  singular_matrix.matrix[0][0] = 1;
  singular_matrix.matrix[0][1] = 2;
  singular_matrix.matrix[1][0] = 2;
  singular_matrix.matrix[1][1] = 4;
  matrix_t result_matrix;
  int inverse_result = s21_inverse_matrix(&singular_matrix, &result_matrix);
  // Проверка, что результатом является ошибка вычисления
  ck_assert_int_eq(inverse_result, 2);
  s21_remove_matrix(&singular_matrix);
}
END_TEST

Suite *s21_decimal_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Core");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, matrix_create_0);
  tcase_add_test(tc_core, matrix_create_1);
  tcase_add_test(tc_core, eq_matrix_test1);
  tcase_add_test(tc_core, eq_matrix_test2);
  tcase_add_test(tc_core, eq_matrix_test3);
  tcase_add_test(tc_core, eq_matrix_test4);
  tcase_add_test(tc_core, eq_matrix_test5);

  tcase_add_test(tc_core, sum_matrix_test1);
  tcase_add_test(tc_core, sum_matrix_test2);
  tcase_add_test(tc_core, sum_matrix_test3);
  tcase_add_test(tc_core, sum_matrix_test4);
  tcase_add_test(tc_core, sum_matrix_test5);

  tcase_add_test(tc_core, sub_matrix_test1);
  tcase_add_test(tc_core, sub_matrix_test2);
  tcase_add_test(tc_core, sub_matrix_test3);
  tcase_add_test(tc_core, sub_matrix_test4);
  tcase_add_test(tc_core, sub_matrix_test5);

  tcase_add_test(tc_core, mult_number_test1);
  tcase_add_test(tc_core, mult_number_test2);
  tcase_add_test(tc_core, mult_number_test3);
  tcase_add_test(tc_core, mult_number_test4);
  tcase_add_test(tc_core, mult_number_test5);
  tcase_add_test(tc_core, mult_matrix_test1);
  tcase_add_test(tc_core, mult_matrix_test2);
  tcase_add_test(tc_core, mult_matrix_test3);

  tcase_add_test(tc_core, transpose_test1);
  tcase_add_test(tc_core, transpose_test2);
  tcase_add_test(tc_core, transpose_test3);
  tcase_add_test(tc_core, transpose_test4);
  tcase_add_test(tc_core, transpose_test5);

  tcase_add_test(tc_core, test_determinant_1x1);
  tcase_add_test(tc_core, test_determinant_2x2);
  tcase_add_test(tc_core, test_determinant_3x3);
  tcase_add_test(tc_core, test_determinant_non_square_matrix);
  tcase_add_test(tc_core, determinant4);
  tcase_add_test(tc_core, determinant5);
  tcase_add_test(tc_core, determinant6);
  tcase_add_test(tc_core, determinant7);

  tcase_add_test(tc_core, test_normal);
  tcase_add_test(tc_core, s21_calc_compl_2);
  tcase_add_test(tc_core, s21_calc_compl_3);

  tcase_add_test(tc_core, test_inverse_matrix_null);
  tcase_add_test(tc_core, test_inverse_matrix_non_square);
  tcase_add_test(tc_core, s21_inverse_1);

  tcase_add_test(tc_core, test_s21_transpose_error_handling);
  tcase_add_test(tc_core, test_s21_inverse_matrix_error_handling);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = s21_decimal_suite();
  sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}