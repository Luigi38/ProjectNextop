#include <iostream>
#include <vector>
using namespace std;

int main() {
	//honey
	int N;
	vector<int> S;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int honey;
		cin >> honey;

		S.push_back(honey);
	}

	int dog_honey = 0;

	for (int i = 0; i < N; i++) { //honey bee 1
		for (int j = i + 1; j < N; j++) { //honey bee 2
			for (int k = 0; k < N; k++) { //honey barrel
				if (i == k || j == k) continue;

				int h = 0;
				int sw = i < k ? 1 : -1;
				int x = i + sw;

				while (x >= 0 && x < N) {
					if (x != i && x != j) {
						h += S[x];
					}
					if (x == k) {
						break;
					}
					x += sw;
				}

				sw = j < k ? 1 : -1;
				x = j + sw;

				while (x >= 0 && x < N) {
					if (x != i && x != j) {
						h += S[x];
					}
					if (x == k) {
						break;
					}
					x += sw;
				}

				dog_honey = max(dog_honey, h);
			}
		}
	}

	cout << dog_honey << '\n';
	return 0;
}