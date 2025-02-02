#include <stdio.h>
#include <stdlib.h>
#define DIM_SIZE 10
int main() {
	int randomArray[DIM_SIZE][DIM_SIZE][DIM_SIZE];

	for (int outer = 0; outer < DIM_SIZE; outer++) {
		for (int middle = 0; middle < DIM_SIZE; middle++){
			for (int inner = 0; inner < DIM_SIZE; inner++) {
				randomArray[outer][middle][inner] = rand()%100;
			}
		}
	}

	for (int outer = 0; outer < DIM_SIZE; outer++) {
		printf("[");
		for (int middle = 0; middle < DIM_SIZE; middle++){
			printf("[");	
			for (int inner = 0; inner < DIM_SIZE; inner++) {
				printf("%i,", randomArray[outer][middle][inner]);
			}
			printf("]\n");
		}
		printf("]\n");
	}
}
