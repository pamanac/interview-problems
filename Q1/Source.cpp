#include <iostream>
#include <random>
#include <chrono>
using namespace std;
const int MATRIX_SIZE = 5;


void zeroMatrix(int**& matrix);
void printMatrix(int**& matrix);

int main(int argc, char* argv[]) {
	//Seed the number generator
	srand(time(NULL));

	//Create the matrix space
	int** myMatrix = new int* [MATRIX_SIZE];
	for (int row = 0; row < MATRIX_SIZE; row++)
		myMatrix[row] = new int[MATRIX_SIZE];

	//Fill with random numbers
	for (int row = 0; row < MATRIX_SIZE; row++) {
		for (int col = 0; col < MATRIX_SIZE; col++) {
			myMatrix[row][col] = rand() % 8;
		}
	}

	cout << "Initial matrix \n ";
	printMatrix(myMatrix);

	cout << "----------------- \n";

	cout << "Zero-d out matrix \n";
	zeroMatrix(myMatrix);
	printMatrix(myMatrix);

}

void zeroMatrix(int**& matrix) {
	struct deleteTuple {
		int row;
		int col;
	};
	deleteTuple* deleteList = new deleteTuple[MATRIX_SIZE * MATRIX_SIZE];
	int numOfDeletes = 0;
	for (int row = 0; row < MATRIX_SIZE; row++) {
		for (int col = 0; col < MATRIX_SIZE; col++) {
			if (matrix[row][col] == 0)
				deleteList[numOfDeletes++] = { row, col };
		}
	}
	for (int i = 0; i < numOfDeletes; i++) {
		int deleteRow = deleteList[i].row;
		int deleteColumn = deleteList[i].col;
		for (int index = 0; index < MATRIX_SIZE; index++) {
			matrix[deleteRow][index] = 0;
			matrix[index][deleteColumn] = 0;
		}


	}
}

void printMatrix(int**& matrix) {
	for (int row = 0; row < MATRIX_SIZE; row++) {
		for (int col = 0; col < MATRIX_SIZE; col++) {
			cout << "[" << matrix[row][col] << "] ";
		}
		cout << endl;
	}
}