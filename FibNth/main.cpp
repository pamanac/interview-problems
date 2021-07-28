#include <iostream>
#include <map>
using namespace std;

int fib(int n, map<int, int>& m) {
	if (n == 0)
		return 0;
	if (n <= 2)
		return 1;
	auto iterator = m.find(n);
	if (iterator == m.end())
		m.insert(pair<int, int>(n, fib(n - 2, m) + fib(n - 1, m)));
	return m[n];
}

int main() {
	map<int, int> memo;
	cout << "4th number (3)  =  " << fib(4, memo) << endl;
	cout << "6th number (8)  =  " << fib(6, memo) << endl;
	cout << "10th number (55)  = " << fib(10, memo) << endl;
	cout << "20th number (6765) = " << fib(20, memo) << endl;
	cout << "102334155  =  " << fib(40, memo) << endl;

}