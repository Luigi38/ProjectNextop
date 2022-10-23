#include <iostream>
using namespace std;

int main() {
	int H, M;

	cin >> H >> M;

	H += 24;

	if (M < 45) {
		H--;
		M = 60 + M - 45;
	}
	else {
		M -= 45;
	}

	cout << H % 24 << ' ' << M % 60 << '\n';
	return 0;
}