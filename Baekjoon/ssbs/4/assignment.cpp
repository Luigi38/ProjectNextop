#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<bool> v(30, false);

	for (int i = 0; i < 28; i++) {
		int roll;

		cin >> roll;
		v[roll - 1] = true;
	}

	for (int i = 0; i < v.size(); i++) if (!v[i]) cout << i + 1 << '\n';
	return 0;
}