#define SIZE 10
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int two[SIZE] = {};

	int i;
	for (i = 0; i < SIZE; i++) {
		two[i] = (int)pow(2, i);
	}

	for (i = 0; i < SIZE; i++) {
		cout << two[i] << endl;
	}

	return 0;
}