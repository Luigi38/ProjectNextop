#define N 10
#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int mushroom = -100;

	for (int i = 0; i < N; i++) {
		int score;

		cin >> score;
		sum += score;

		if (abs(mushroom) > abs(sum - 100)) mushroom = sum - 100;
		else if (abs(mushroom) == abs(sum - 100)) mushroom = (mushroom >= sum - 100 ? mushroom : sum - 100);
	}

	cout << mushroom + 100 << '\n';
	return 0;
}