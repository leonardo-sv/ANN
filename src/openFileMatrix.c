#include "../include/openMatrixFile.h"

double** createMatrix(int rows, int columns){

  int i,j;

  double **m = (double**)malloc(rows * sizeof(double*));

  for (i = 0; i < rows; i++){
       m[i] = (double*) malloc(columns * sizeof(double));
       for (j = 0; j < columns; j++){
            m[i][j] = 0;
       }
  }
  return m;
}

void freeMatrix(double **mat, int rows){
  int i;
  for(i = 0; i < rows; i++)
    free(mat[i]);
  free(mat);
}

void readFileMatrix(double **file, int rows_file, int columns_file){
  int i,j;
  double read_value;
  FILE *arq = fopen(PATH,"r");

  for( i= 0; i < rows_file ;i++){
    for(j = 0; j < columns_file;j++){
      fscanf(arq, "%lf",&read_value);
      file[i][j] = read_value;
    }
  }

}

void printMatrix(double **mat, int rows, int columns){
  int i, j;

  for( i= 0; i < rows ;i++){
    for(j = 0; j < columns;j++){
      printf("%.5f ", mat[i][j]);
    }
    printf("\n");
  }
}
