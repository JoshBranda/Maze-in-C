#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <string.h>
#define MAXLINE 20

int main(int argc, char *argv[])
{
	FILE *file;
	char mystring[MAXLINE], orientation;
	char** matrix;
	int columns, rows, rowStart, columnStart, currentX, currentY, rowEnd, columnEnd;

	if (argc != 2)
	{
		printf("Invalid input");
		return 0;
	}

	else
	{
		int i, k;
		char* temp;

		file = fopen(argv[1], "r");

		fgets (mystring, MAXLINE, file); /* Get the dimensions */
		temp = strtok(mystring,",");
		columns = atoi (temp);
		temp = strtok(NULL,",");
		rows = atoi (temp);
		matrix = assignMatrix(rows,columns);

		fgets (mystring, MAXLINE, file); /* Get the starting point*/
		temp = strtok(mystring,",");
		columnStart = atoi (temp);
		temp = strtok(NULL,",");
		rowStart = atoi (temp);

		fgets (mystring, MAXLINE, file); /* Get the ending point*/
		temp = strtok(mystring,",");
		columnEnd = atoi (temp);
		temp = strtok(NULL,",");
		rowEnd = atoi (temp);

		for (i = 0; i < rows; i++){
			for (k = 0 ; k < columns; k++){
				matrix[i][k] = fgetc(file);
			}
			fgetc(file);
		}


		fclose (file);
	}

	if (rowStart == 0){
		orientation = 'S';
	}
	else if (rowStart == (rows - 1)){
		orientation = 'N';
	}
	else if (columnStart == 0){ 
		orientation = 'E';
	}
	else {
		orientation = 'W';
	}

	currentX = rowStart;
	currentY = columnStart;

	while ( (currentX != rowEnd) || (currentY != columnEnd)){
		if ( orientation == 'S'){
			if ( (currentY > 0) && (matrix[currentX][currentY - 1]  == '0' || matrix[currentX][currentY - 1]  == 'W')){
				matrix[currentX][currentY] = 'W';
				--currentY;
				orientation = 'W';
			}
			else if ( (currentX < (rows - 1)) && (matrix[currentX + 1][currentY] == '0' || matrix[currentX + 1][currentY] == 'W')){
				matrix[currentX][currentY] = 'W';
				++currentX;
				orientation = 'S';
			}
			else if ( (currentY < (columns - 1)) && (matrix[currentX][currentY + 1] == '0' || matrix[currentX][currentY + 1] == 'W')){
				matrix[currentX][currentY] = 'W';
				++currentY;
				orientation = 'E';
			}
			else {
				matrix[currentX][currentY] = 'W';
				--currentX;
				orientation = 'N';
			} 
		}

		else if ( orientation == 'N'){
			if ( (currentY < (columns - 1)) && (matrix[currentX][currentY + 1]  == '0' || matrix[currentX][currentY + 1]  == 'W')){
				matrix[currentX][currentY] = 'W';
				++currentY;
				orientation = 'E';
			}
			else if ( (currentX > 0) && (matrix[currentX - 1][currentY] == '0'|| matrix[currentX - 1][currentY] == 'W')){
				matrix[currentX][currentY] = 'W';
				--currentX;
				orientation = 'N';
			}
			else if ( (currentY > 0) && (matrix[currentX][currentY - 1] == '0' || matrix[currentX][currentY - 1] == 'W')){
				matrix[currentX][currentY] = 'W';
				--currentY;
				orientation = 'W';
			}
			else {
				matrix[currentX][currentY] = 'W';
				currentX++;
				orientation = 'S';
			} 
		}

		else if ( orientation == 'W'){
			if ( (currentX > 0) && (matrix[currentX - 1][currentY]  == '0' || matrix[currentX - 1][currentY]  == 'W')){
				matrix[currentX][currentY] = 'W';
				--currentX;
				orientation = 'N';
			}
			else if ( (currentY > 0) && (matrix[currentX][currentY - 1] == '0' || matrix[currentX][currentY - 1] =='W')){
				matrix[currentX][currentY] = 'W';
				--currentY;
				orientation = 'W';
			}
			else if ( (currentX < (rows - 1)) && (matrix[currentX + 1][currentY] == '0' || matrix[currentX + 1][currentY] =='W')){
				matrix[currentX][currentY] = 'W';
				++currentX;
				orientation = 'S';
			}
			else {
				matrix[currentX][currentY] = 'W';
				currentY++;
				orientation = 'E';
			} 
		}

		else {
			if ( (currentX < (rows - 1)) && (matrix[currentX + 1][currentY]  == '0' || matrix[currentX + 1][currentY]  =='W')){
				matrix[currentX][currentY] = 'W';
				++currentX;
				orientation = 'S';
			}
			else if ( (currentY < (columns - 1)) && (matrix[currentX][currentY + 1] == '0' || matrix[currentX][currentY + 1] =='W')){
				matrix[currentX][currentY] = 'W';
				++currentY;
				orientation = 'E';
			}
			else if ( (currentX > 0) && (matrix[currentX - 1][currentY] == '0' || matrix[currentX - 1][currentY] =='W')){
				matrix[currentX][currentY] = 'W';
				--currentX;
				orientation = 'N';
			}
			else {
				matrix[currentX][currentY] = 'W';
				currentY--;
				orientation = 'W';
			} 
		}
	} 
	matrix[currentX][currentY] = 'W';

	displayMatrix(matrix, rows, columns);

	freeMatrix(matrix, rows);

	return 0;
}

