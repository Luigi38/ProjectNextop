#include <iostream>
#include <vector>

using namespace std;
struct value {
	int value;
	int index;
};

int main() {
	vector<int> v;

	for (int i = 0; i < 9; i++) {
		int value;

		cin >> value;
		v.push_back(value);
	}

	value val = { v[0], 1 };

	for (int i = 0; i < 9; i++) {
		if (v[i] > val.value) {
			val = { v[i], i + 1 };
		}
	}

	cout << val.value << '\n' << val.index << '\n';
	return 0;
}