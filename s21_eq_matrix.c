#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = FAILURE;
  if (A->rows == B->rows && A->columns == B->columns) {
    status = SUCCESS;
    for (int i = 0; i < A->rows && status == SUCCESS; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
          status = FAILURE;
          break;
        }
      }
    }
  }
  return status;
}
