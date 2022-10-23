#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int award = 0;

	cin >> a >> b >> c;

	if (a == b && b == c && c == a) award = 10000 + (a * 1000);
	else if (a == b && b != c) award = 1000 + (a * 100);
	else if (b == c && c != a) award = 1000 + (b * 100);
	else if (c == a && a != b) award = 1000 + (c * 100);
	else if (a != b && b != c && c != a) award = max(max(a, b), c) * 100;

	cout << award << '\n';
	return 0;
}