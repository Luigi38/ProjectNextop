#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	int Q, R;
	int maxx = 0;

	cin >> N;

	if (N == 1) {
		cout << "1\n";
		return 0;
	}

	Q = (N - 1) / 6;
	R = (N - 1) % 6;

	bool equals = true;

	maxx = ceil((double)(N - 1) / 6.0);
	int total = 0;

	for (int i = 1; i <= 100000000; i++) {
		total += i;

		if (maxx <= total) {
			maxx = i + 1;
			equals = maxx == total;
			break;
		}
	}

	cout << maxx << '\n';
	return 0;
}
