#include <iostream>
#include <string>
using namespace std;

bool han(const int number) {
	string numstr = to_string(number);
	int common = 0;

	if (numstr.size() <= 2) return true;
	common = numstr[1] - numstr[0];

	for (int i = 2; i < numstr.size(); i++) {
		int jari = numstr[i] - '0';

		if (common != numstr[i] - numstr[i - 1]) return false;
	}

	return true;
}

int main() {
	int N;
	int count = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) if (han(i)) count++;
	cout << count << '\n';

	return 0;
}