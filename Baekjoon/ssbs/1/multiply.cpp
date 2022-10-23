#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int A, B;

	cin >> A >> B;

	string B2 = to_string(B);
	vector<int> v;

	for (int i = 2; i >= 0; i--) {
		v.push_back(A * (B2[i] - '0'));
	}
	v.push_back(A * B);

	for (int i = 0; i < 4; i++) {
		cout << v[i] << '\n';
	}
	return 0;
}