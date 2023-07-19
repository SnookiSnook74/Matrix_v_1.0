#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_status = 0;
  if (A->columns != B->rows) {
    error_status = 2;
  } else {
    error_status = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows && error_status == 0; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error_status;
}
