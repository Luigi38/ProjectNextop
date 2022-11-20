#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int A;
	int B;

	cin >> A >> B;

	string A2 = to_string(A);
	string B2 = to_string(B);

	reverse(A2.begin(), A2.end());
	reverse(B2.begin(), B2.end());

	int A3 = stoi(A2);
	int B3 = stoi(B2);

	cout << max(A3, B3) << '\n';
	return 0;
}