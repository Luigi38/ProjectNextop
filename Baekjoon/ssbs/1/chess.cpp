#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> max = { 1, 1, 2, 2, 2, 8 };
	vector<int> v;
	vector<int> need(max.size(), 0);

	for (int i = 0; i < max.size(); i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] != max[i]) {
			need[i] = max[i] - v[i];
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << need[i] << ' ';
	}
	cout << '\n';
	return 0;
}