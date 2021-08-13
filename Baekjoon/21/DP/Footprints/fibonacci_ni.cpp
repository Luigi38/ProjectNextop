#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

struct zto {
	ll zero;
	ll one;
};

zto operator +(const zto& a, const zto& b) {
	return { a.zero + b.zero, a.one + b.one };
}

zto get_fibonacci(const int n) {
	zto s = { 0, 0 };

	if (n == 0) {
		s.zero++;
		return s;
	}
	else if (n == 1) {
		s.one++;
		return s;
	}

	zto odd = { 1, 2 }; //3 : 0
	zto even = { 2, 3 }; //4 : 1
	zto oe = { 3, 5 }; //5 : 2

	if (n == 2) {
		return { 1, 1 };
	}
	else if (n == 3) {
		return odd;
	}
	else if (n == 4) {
		return even;
	}
	else if (n == 5) {
		return oe;
	}
	
	s = { 3, 5 }; //init with 5

	for (int i = 6; i <= n; i++) {
		s = { s.one, s.zero + s.one };
	}

	return s;
}

int main() {
	int T;
	vector<zto> v;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		zto s = get_fibonacci(N);
		v.push_back(s);
	}

	for (int i = 0; i < T; i++) {
		zto x = v[i];
		cout << x.zero << " " << x.one << '\n';
	}

	return 0;
}
