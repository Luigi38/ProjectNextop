#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string a;
	int total = 0;

	cin >> N >> a;

	for (int i = 0; i < N; i++) {
		char ch = a[i];
		int n = ch - '0';

		total += n;
	}

	cout << total << '\n';
	return 0;
}