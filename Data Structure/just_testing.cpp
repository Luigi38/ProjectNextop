#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct test {
	int a;
	string b;
};

int main() {
	test t = { 100, "just testing" };
	cout << t.a << "," << t.b << endl;

	return 0;
}