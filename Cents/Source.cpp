#include <iostream>
#include <map>

using namespace std;

class solverA {
private:
	int target;
	enum cents { QUARTER = 25, DIME = 10, NICKEL = 5, PENNY = 1 };
	map<int, int>* memo;

	int solveAUX(int t) {
		cout << "Solving " << t << endl;
		if (memo->find(t) != memo->end())
			return (*memo)[t];
		int sum = 0;
		for (int high = t - 1; high > 0; high--) {
			sum += solveAUX(high);
		}
		cout << "Solved " << t << " : " << sum << endl;
		(*memo)[t] = sum;
		return sum;
	}

public:
	solverA(int n) : target(n) {
		memo = new map<int, int>(); 
		(*memo)[PENNY] = 1; // 1 penny
		(*memo)[NICKEL] = 2; // 5 pennies, 1 nickel
		(*memo)[DIME] = 4; // 10 pennies, 2 nickels, 1 nickel and 5 pennies
		(*memo)[QUARTER] = 13;
		// 0 0 0 25, 0 0 1 20, 0 0 2 15, 0 0 3 10, 0 0 4 5, 0 0 5 0, 0 1 0 15, 0 2 0 5, 0 1 1 10, 0 1 2 5, 0 1 3 0, 0 2 1 0, 1 0 0 0
	}

	void setTarget(int n) {
		target = n;
	}

	int solve() {
		return solveAUX(target);
	}

	~solverA() {
		delete memo;
	}
};


class solverB {
private:
	int target;
	enum cents { QUARTER = 25, DIME = 10, NICKEL = 5, PENNY = 1 };
	int* denoms;
	map<int, int>* memo;

	int solveAUX(int t, int index) {
		if ((*memo).find(t) != (*memo).end())
			return (*memo)[t];
		if (index >= 4)
			return 1;
		int ways = 0;
		int valueUsed = denoms[index];
		for (int i = 0; i * valueUsed <= t; i++) {
			int remaining = t - i * valueUsed;
			ways += solveAUX(remaining, index + 1);
		}
		(*memo)[t] = ways;
		return ways;


	}

public:
	solverB(int target) {
		this->target = target;
		this->memo = new map<int, int>();
		//this->denoms = new int[] {PENNY, NICKEL, QUARTER, DIME};
		this->denoms = new int[4];
		denoms[0] = PENNY;
		denoms[1] = NICKEL;
		denoms[2] = QUARTER;
		denoms[3] = DIME;
	}

	int solve() {
		solveAUX(target, 0);
		return (*memo)[target];
	}

	~solverB() {
		delete memo;
	}
};


int main(int argc, char* argv[]) {
	//solverA test(100); solverA doesn't work :(
	//cout << "result : " << test.solve();

	solverB test(100);
	cout << "result : " << test.solve();
}