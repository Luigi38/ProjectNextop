#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> get_number_counts(int n) {
	vector<int> counts;
	string str = to_string(n);

	for (auto ch : str) counts.push_back(ch - 48);
	return counts;
}

int get_total(vector<int>& v) {
	int total = 0;

	for (auto x : v) total += x;
	return total;
}

int get_constructor(int N) {
	for (int i = 1; i <= N; i++) {
		vector<int> nn = get_number_counts(i);
		if (N == i + get_total(nn)) return i;
	}

	return 0;
}

int main() {
	int N;
	cin >> N;

	cout << get_constructor(N) << '\n';
	return 0;
}