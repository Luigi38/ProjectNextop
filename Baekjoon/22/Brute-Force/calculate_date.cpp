#define ME 15
#define MS 28
#define MM 19
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int E, S, M;
	int e = 1;
	int s = 1;
	int m = 1;
	int year = 1;

	cin >> E >> S >> M;

	for (int i = 1; i <= 7980; i++) {
		if (e == E && s == S && m == M) {
			year = i;
			break;
		}

		if (e++ == ME) e = 1;
		if (s++ == MS) s = 1;
		if (m++ == MM) m = 1;
	}

	cout << year << '\n';
	return 0;
}