#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>

char** assignMatrix(int rows, int columns)
{
	char** matrix;
	int i;

	matrix = (char**)malloc(sizeof(char*) * rows);

	for (i = 0; i < rows; i++){
		matrix[i] = (char*)malloc(sizeof(char) * columns);
	}

	return matrix;
}

