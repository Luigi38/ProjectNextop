#include <iostream>
#include <vector>
#include <string>
using namespace std;

int d(const int number) {
	int a = number;
	string numstr = to_string(number);

	for (int i = 0; i < numstr.size(); i++) a += numstr[i] - '0';
	return a;
}

int main() {
	vector<vector<int>> v(10000, vector<int>());

	for (int i = 1; i <= 10000; i++) {
		int index = d(i) - 1;
		
		if (index >= 10000) continue;
		v[index].push_back(i);
	}
	for (int i = 0; i < 10000; i++) if (v[i].size() == 0) cout << i + 1 << '\n';

	return 0;
}