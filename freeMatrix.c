#include "matrix.h"
#include "stdlib.h"

void freeMatrix(char** input, int rows)
{
	int i;

	for (i = 0; i < rows; i++){
		free (input[i]);
	}

	free(input);
}
