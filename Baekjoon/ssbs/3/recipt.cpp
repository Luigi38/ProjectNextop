#include <iostream>
using namespace std;

int main() {
	int X;
	int X2 = 0;
	int N;

	cin >> X >> N;

	for (int i = 0; i < N; i++) {
		int a, b;

		cin >> a >> b;
		X2 += a * b;
	}

	cout << (X == X2 ? "Yes" : "No") << '\n';
	return 0;
}