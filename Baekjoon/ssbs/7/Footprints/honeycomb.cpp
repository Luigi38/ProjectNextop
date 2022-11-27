#include <iostream>
using namespace std;

int main() {
	int N;
	int count = 0;

	cin >> N;

	for (int i = 1; i <= 6; i++) {
		int attempt = 1;
		int total = i + 1;

		while (total < N) {
			total += attempt * 6 + i;
			attempt++;
		}
		if (total == N) {
			count = attempt;
			break;
		}
	}

	cout << count + 1 << '\n';
	return 0;
}