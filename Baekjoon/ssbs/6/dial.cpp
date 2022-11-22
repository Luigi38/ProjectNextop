#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int elapsed = 2;
	int step = 1;
	int total = 0;
	vector<int> v = {
		3, 3, 3,
		4, 4, 4,
		5, 5, 5,
		6, 6, 6,
		7, 7, 7,
		8, 8, 8, 8,
		9, 9, 9,
		10, 10, 10, 10
	};
	string str;

	cin >> str;

	for (char ch : str) {
		total += v[ch - 'A'];
	}

	cout << total << '\n';
	return 0;
}