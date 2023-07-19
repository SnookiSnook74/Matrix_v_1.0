#include "s21_matrix.h"

int s21_copy_matrix(matrix_t *A, matrix_t *B) {  // делает матрицу В равной А
  if (A->rows != B->rows || A->columns != B->columns) {
    return 1;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      B->matrix[i][j] = A->matrix[i][j];
    }
  }
  return 0;
}
// Функция для получения подматрицы путем исключения определенной строки и
// столбца из исходной матрицы
matrix_t *get_sub_matrix(matrix_t *A, int exclude_row, int exclude_col) {
  matrix_t *sub_matrix = malloc(sizeof(matrix_t));
  s21_create_matrix(A->rows - 1, A->columns - 1, sub_matrix);
  int sub_i = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == exclude_row) continue;
    int sub_j = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == exclude_col) continue;
      sub_matrix->matrix[sub_i][sub_j] = A->matrix[i][j];
      sub_j++;
    }
    sub_i++;
  }
  return sub_matrix;
}

double calculate_determinant(matrix_t *A) {
  if (A->rows != A->columns) {
    return NAN;
  }
  if (A->rows == 1) {
    return A->matrix[0][0];
  }
  if (A->rows == 2) {
    return A->matrix[0][0] * A->matrix[1][1] -
           A->matrix[0][1] * A->matrix[1][0];
  }
  double determinant = 0.0;
  for (int j = 0; j < A->columns; j++) {
    matrix_t *sub_matrix = get_sub_matrix(A, 0, j);
    double minor = calculate_determinant(sub_matrix);
    determinant += pow(-1, j) * A->matrix[0][j] * minor;
    s21_remove_matrix(sub_matrix);
    free(sub_matrix);
  }
  return determinant;
}

double get_minor(matrix_t *A, int row, int col) {
  matrix_t *sub_matrix = get_sub_matrix(A, row, col);
  double minor = calculate_determinant(sub_matrix);
  s21_remove_matrix(sub_matrix);
  free(sub_matrix);
  return minor;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A->rows != A->columns)
    return 2;  // Миноры и дополнения можно вычислить только для
               // квадратных матриц
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double minor = get_minor(A, i, j);
      result->matrix[i][j] =
          pow(-1, i + j) * minor;  // Алгебраическое дополнение
    }
  }
  return 0;
}
