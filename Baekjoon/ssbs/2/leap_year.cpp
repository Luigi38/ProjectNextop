#include <iostream>
using namespace std;

int main() {
	int year;
	int whether = 0;

	cin >> year;

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) whether = 1;

	cout << whether << '\n';
	return 0;
}