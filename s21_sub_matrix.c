#include "s21_matrix.h"

int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int error_status = 0;
  if (A->columns == B->columns && A->rows == B->rows) {
    error_status = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && error_status == 0; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    error_status = 2;
  }
  return error_status;
}