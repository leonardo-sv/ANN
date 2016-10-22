#ifndef OPEN_MATRIX_FILE_H
#define OPEN_MATRIX_FILE_H

#include "includeAll.h"

#define PATH "../data/precoCasa.txt"

#define NUM_COLUMNS 14
#define NUM_ROWS 506


double** createMatrix(int rows, int columns);
void readFileMatrix(double **file, int rows_file, int columns_file);
void freeMatrix(double **mat, int rows);
void printMatrix(double **mat, int rows, int columns);

#endif
