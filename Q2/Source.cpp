#include <iostream>
#include <string>

using namespace std;

string compression(string input);

int main(int argc, char* argv) {
	string test1 = "aablcccccaaa";
	cout << compression(test1) << endl;
}

string compression(string input) {
	int size = input.length();
	string compressed = "";
	for (int index = 0; index < size; index++) {
		char read = input.at(index);
		int numRepeats = 1; // starts at 1 because it includes read character
		for (int runner = index + 1; runner < size; runner++) {
			if (input.at(runner) == read)
				numRepeats++;
			else {
				compressed += read;
				if (numRepeats > 1) {
					compressed.append(to_string(numRepeats));
				}
				index = runner-1;
				numRepeats = 1;
				break;
			}
			if (runner == size - 1) {
				compressed += read;
				if (numRepeats > 1)
					compressed.append(to_string(numRepeats));
				if (compressed.length() < size)
					return compressed;
				return input;
			}

		}
	}
}