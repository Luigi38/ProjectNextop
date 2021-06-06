#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> S;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int honey;
		cin >> honey;

		S.push_back(honey);
	}

	int dog_honey = 0;
	vector<int> max_v;

	int h = 0;

	for (int i = 0; i < N; i++) {
		h += S[i];
		max_v.push_back(h);
	}


}
