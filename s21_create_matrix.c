#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_status = 0;
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix =
        calloc(rows, sizeof(double *));  // выделение памяти под строки
    for (int i = 0; i < rows; i++) {
      result->matrix[i] =
          calloc(columns, sizeof(double));  // выделение памяти под столбцы
    }
  } else {
    error_status = 1;
  }
  return error_status;
}