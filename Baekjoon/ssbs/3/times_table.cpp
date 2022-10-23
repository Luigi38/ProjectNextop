#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int a = 1; a <= 9; a++) {
		cout << N << " * " << a << " = " << N * a << '\n';
	}

	return 0;
}