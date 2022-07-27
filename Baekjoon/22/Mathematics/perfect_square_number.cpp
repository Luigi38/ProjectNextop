#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	int rn = (int)sqrt(N);
	int rm = (int)sqrt(M);

	int sum = 0;
	int m = 0;

	for (int i = rn; i <= rm; i++) {
		if (i == rn && ((int)pow(rn, 2) != N)) continue;

		int i2 = (int)pow(i, 2);

		sum += i2;
		if (m == 0) m = i2;
	}

	if (sum == 0 && m == 0) cout << "-1\n";
	else cout << sum << '\n' << m << '\n';

	return 0;
}