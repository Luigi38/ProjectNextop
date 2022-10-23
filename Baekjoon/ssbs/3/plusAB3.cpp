#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	vector<int> v;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int A, B;

		cin >> A >> B;
		v.push_back(A + B);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}