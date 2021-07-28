#include <iostream>
int binarySearch(int* src, int size, int target) {
	int left = 0;
	int right = size - 1;
	while (left < right) {
		int pivot = floor((left + right) / 2);
		if (src[pivot] < target)
			left = pivot + 1;
		else if (src[pivot] > target)
			right = pivot - 1;
		else
			return pivot;
	}
	return NULL;
}

int main() {
	int* arr = new int[] {2, 3, 5, 7};
	std::cout << "index of solution(expected 2) : " << binarySearch(arr, 4, 5) << std::endl;
	return 0;
}