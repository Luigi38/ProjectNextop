#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	double Q;
	int maxx = 0;

	cin >> N;

	if (N == 1) {
		cout << "1\n";
		return 0;
	}

	Q = (N - 1) / 6.0;

	maxx = ceil(Q);
	int total = 0;

	for (int i = 1; i <= 100000000; i++) {
		total += i;

		if (maxx <= total) {
			maxx = i + 1;
			break;
		}
	}

	cout << maxx << '\n';
	return 0;
}
