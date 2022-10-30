#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> remainders(42, 0);
	vector<int> v;
	int count = 0;
	
	for (int i = 0; i < 10; i++) {
		int value;

		cin >> value;
		v.push_back(value);
	}

	for (int i = 0; i < 10; i++) remainders[v[i] % 42]++;
	for (int i = 0; i < 42; i++) if (remainders[i] != 0) count++;

	cout << count << '\n';
	return 0;
}