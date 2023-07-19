#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_status = 0;
  double determinant;
  matrix_t complement, transposed;
  // Проверка входных данных
  if (A == NULL || result == NULL || A->rows != A->columns) {
    error_status = 1;  // Ошибка, некорректная матрица
  }
  // Вычисление определителя
  if (error_status == 0 &&
      (s21_determinant(A, &determinant) != 0 || determinant == 0.0)) {
    error_status = 2;  // Ошибка вычисления
  }
  // Вычисление матрицы алгебраических дополнений
  if (error_status == 0 && s21_calc_complements(A, &complement) != 0) {
    error_status = 2;  // Ошибка вычисления
  }
  // Транспонирование матрицы алгебраических дополнений
  if (error_status == 0 && s21_transpose(&complement, &transposed) != 0) {
    error_status = 2;  // Ошибка вычисления
  }
  // Умножение транспонированной матрицы на 1/определитель
  if (error_status == 0) {
    for (int i = 0; i < transposed.rows; i++) {
      for (int j = 0; j < transposed.columns; j++) {
        transposed.matrix[i][j] *= 1 / determinant;
      }
    }
  }
  if (error_status == 0) {
    s21_create_matrix(transposed.rows, transposed.columns, result);
    if (s21_copy_matrix(&transposed, result) != 0) {
      error_status = 2;
    }
  }
  // Очистка памяти
  if (error_status == 0) {
    s21_remove_matrix(&complement);
    s21_remove_matrix(&transposed);
  }
  return error_status;
}
