#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	string s;

	cin >> N >> s;

	vector<int> count_g(N, 0);
	vector<int> count_h(N, 0);
	int sum = 0;

	long long photos = 0;

	for (int i = 0; i < N; i++) {
		if (s[i] == 'G') sum++;
		count_g[i] = sum;
	}
	sum = 0;

	for (int i = 0; i < N; i++) {
		if (s[i] == 'H') sum++;
		count_h[i] = sum;
	}

	for (int step = 3; step <= N; step++) {
		for (int i = 0; i < N; i++) { //start point
			if (N - i < step) break;

			int start = i - 1;
			int end = i + step - 1;

			int length_g = count_g[end] - (start != -1 ? count_g[start] : 0);
			int length_h = count_h[end] - (start != -1 ? count_h[start] : 0);

			if (length_g == 1 || length_h == 1) photos++;
		}
	}
	
	cout << photos << '\n';
	return 0;
}