#include "matrix.h"
#include "stdio.h"

void displayMatrix(char** input, int rows, int columns)
{
	int i, k;

	for (i = 0; i < rows; i++){
		for (k = 0; k < columns; k++){
			printf ("%c", input[i][k]);
		}
		printf ("\n");
	}
}
