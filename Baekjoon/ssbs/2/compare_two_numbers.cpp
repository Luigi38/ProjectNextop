#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B;

	cin >> A >> B;

	string a = "==";
	if (A < B) a = "<";
	else if (A > B) a = ">";

	cout << a << '\n';
	return 0;
}