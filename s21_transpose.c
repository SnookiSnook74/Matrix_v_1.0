#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_status = 0;
  if (A->rows < 1 || A->columns < 1) {
    error_status = 1;
  } else {
    error_status = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows && error_status == 0; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return error_status;
}
