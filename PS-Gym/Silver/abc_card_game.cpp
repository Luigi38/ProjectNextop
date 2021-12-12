#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	vector<stack<char>> v;
	int index = 0;
	int the_winner = 0;

	for (int i = 0; i < 3; i++) {
		string str;
		stack<char> s;

		cin >> str;

		for (char ch : str) s.push(ch);
		v.push_back(s);
	}

	while (!v[index].empty()) {
		char dummy = v[index].top();
		
		v[index].pop();
		index = dummy - 'A';
	}

	cout << index + 1 << '\n';
	return 0;
}