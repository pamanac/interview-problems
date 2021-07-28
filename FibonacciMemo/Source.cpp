#include <iostream>
#include <chrono>
#include <map>
using namespace std;

int fib(int n) {
	if (n < 3)
		return 1;
	return fib(n - 2) + fib(n - 1);
}

int fibB(int n, map<int, int>* dict) {
	if (dict->find(n) != dict->end())
		return (*dict)[n];
	if (n < 3)
		return 1;
	(*dict)[n] = fibB(n - 2, dict) + fibB(n - 1, dict);
	return (*dict)[n];
}

int main() {
	auto start = chrono::steady_clock::now();
	int result = fib(23);
	auto end = chrono::steady_clock::now();
	auto enlapsedN = chrono::duration<double, milli>(end - start).count();

	start = chrono::steady_clock::now();
	int result2 = fibB(23);
	end = chrono::steady_clock::now();
	auto enlapsed = chrono::duration<double, milli>(end - start).count();

	cout << "Result naive: " << result << endl;
	cout << "Result memo: " << result2 << endl;

	cout << " Enlapsed time naive: " << enlapsedN << " ms" << endl;
	cout << " Enlapsed time improved: " << enlapsed << " ms" << endl;
}