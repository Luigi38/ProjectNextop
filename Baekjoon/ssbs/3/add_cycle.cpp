#include <iostream>
using namespace std;

pair<int, int> get_jari(const int a) {
	return { a / 10, a % 10 };
}

int main() {
	int count = 0;
	int N;

	cin >> N;
	int N2 = N;

	while (true) {
		auto a12 = get_jari(N2);
		N2 = a12.second * 10 + get_jari(a12.first + a12.second).second;

		count++;
		if (N == N2) break;
	}

	cout << count << '\n';
	return 0;
}