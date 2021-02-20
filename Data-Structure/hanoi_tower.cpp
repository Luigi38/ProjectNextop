#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
using namespace std;

map<char, stack<int>> m;

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n != 1) {
		hanoi_tower(n - 1, from, to, tmp);
		m[to].push(m[from].top());
		m[from].pop();
		hanoi_tower(n - 1, tmp, from, to);
	}
	else {
		m[to].push(m[from].top());
		m[from].pop();
	}
}

int main() {
	int N = 3;

	int i;
	for (i = 0; i < N; i++) {
		char tower = (char)(i + 65);
		m[tower] = stack<int>();
	}
	for (i = N; i > 0; i--) m['A'].push(i);

	hanoi_tower(N, 'A', 'B', 'C');

	for (i = 0; i < N; i++) {
		char tower = (char)(i + 65);
		stack<int> s = m[tower];

		while (!s.empty()) {
			cout << tower << ": " << s.top() << endl;
			s.pop();
		}
	}

	return 0;
}