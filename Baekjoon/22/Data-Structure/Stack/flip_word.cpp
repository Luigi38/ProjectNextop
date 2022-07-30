#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

void get_flipped(string& flipped, stack<char>& s) {
	while (!s.empty()) {
		flipped.push_back(s.top());
		s.pop();
	}
}

string flip(const string& str) {
	stack<char> s;
	string flipped = "";

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			get_flipped(flipped, s);
			flipped.push_back(' ');
		}
		else {
			s.push(str[i]);
		}
	}

	get_flipped(flipped, s);
	return flipped;
}

int main() {
	int T;
	vector<string> v;

	cin >> T;
	cin.ignore();

	for (int t = 0; t < T; t++) {
		string str;

		getline(cin, str);
		string flipped = flip(str);

		v.push_back(flipped);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}