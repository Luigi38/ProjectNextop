#include <iostream>
#include <vector>
using namespace std;

struct zto {
	int zero;
	int one;
};

zto operator +(const zto& a, const zto& b) {
	return { a.zero + b.zero, a.one + b.one };
}

zto fibonacci(const int n, vector<zto>& counts) {
	if (counts[n].zero != 0 || counts[n].one != 0) {
		return counts[n];
	}

	counts[n] = fibonacci(n - 1, counts) + fibonacci(n - 2, counts);
	return counts[n];
}

int main() {
	int T;

	vector<zto> v;
	vector<zto> counts(41, { 0, 0 });

	counts[0] = { 1, 0 };
	counts[1] = { 0, 1 };

	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		zto s = fibonacci(N, counts);
		v.push_back(s);
	}

	for (int i = 0; i < T; i++) {
		zto x = v[i];
		cout << x.zero << " " << x.one << '\n';
	}

	return 0;
}