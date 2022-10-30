#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> v;
	vector<float> v2;
	float average = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int value;

		cin >> value;
		v.push_back(value);
	}

	int max = v[0];
	for (int i = 1; i < N; i++) if (v[i] > max) max = v[i];

	for (int i = 0; i < N; i++) {
		v2.push_back((float)v[i] / max * 100);
		average += v2[i];
	}
	average /= N;

	cout << average << '\n';
	return 0;
}