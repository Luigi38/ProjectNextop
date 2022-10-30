#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v2;
	int N, v;
	int count = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int value;

		cin >> value;
		v2.push_back(value);
	}

	cin >> v;

	for (int i = 0; i < N; i++) if (v2[i] == v) count++;
	cout << count << '\n';

	return 0;
}