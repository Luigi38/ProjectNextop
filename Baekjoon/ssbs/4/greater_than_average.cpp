#include <iostream>
#include <vector>
using namespace std;

int main() {
	int C;
	vector<vector<int>> v;
	vector<float> averages;

	cout << std::fixed;
	cout.precision(3);
	cin >> C;

	for (int i = 0; i < C; i++) {
		int N;
		vector<int> v2;
		float total = 0;

		cin >> N;

		for (int j = 0; j < N; j++) {
			int score;

			cin >> score;
			total += score;

			v2.push_back(score);
		}
		v.push_back(v2);
		total /= N;
		averages.push_back(total);
	}

	for (int c = 0; c < C; c++) {
		int count = 0;
		float average = averages[c];

		for (int i = 0; i < v[c].size(); i++) if (v[c][i] > average) count++;

		float ratio = (float)count / v[c].size() * 100;
		cout << ratio << "%\n";
	}

	return 0;
}