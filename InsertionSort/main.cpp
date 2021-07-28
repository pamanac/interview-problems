#include <iostream>

void insertionSort(int* src, int size) {
	for (int i = 1; i < size; i++) {
		int read = 0;
		while (read<i) {
			if (src[read] > src[i]) {
				int temp = src[read];
				src[read] = src[i];
				src[i] = temp;
			}
			read++;
		}
	}
}

int main() {
	int* arr = new int[] {4, 2, 5, 1, 7, 2};
	insertionSort(arr, 6);
	for (int i = 0; i < 6; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}