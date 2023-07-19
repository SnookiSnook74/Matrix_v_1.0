#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error_status = 0;
  if (A->rows != A->columns) {
    error_status = 2;
  } else {
    *result = calculate_determinant(A);
    if (isnan(*result)) {
      error_status = 2;
    }
  }
  return error_status;
}
