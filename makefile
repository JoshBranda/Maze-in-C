hm1:
	gcc -g -O0 -ansi -pedantic -Wall -o hm1 main.c matrix.c displayMatrix.c freeMatrix.c

clean:
	rm hm1
