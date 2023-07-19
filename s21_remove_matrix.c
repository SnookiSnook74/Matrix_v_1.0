#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i] != NULL) {
          free(A->matrix[i]);  // удаляем память под строки
        }
      }
      free(A->matrix);
    }
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}
