#include <iostream>
#include <stack>
#include <string>
using namespace std;

void apply_flipped_reversed(stack<char>& s, string& flipped) {
	while (!s.empty()) {
		flipped.push_back(s.top());
		s.pop();
	}
}

int main() {
	string S;

	stack<char> s;
	string flipped = "";
	bool is_tagged = false;

	getline(cin, S);

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '<') {
			is_tagged = true;

			apply_flipped_reversed(s, flipped);
			flipped.push_back('<');

			continue;
		}
		else if (S[i] == '>') {
			is_tagged = false;
			flipped.push_back('>');

			continue;
		}
		else if (S[i] == ' ') {
			apply_flipped_reversed(s, flipped);
			flipped.push_back(' ');

			continue;
		}
		if (!is_tagged) {
			s.push(S[i]);
		}
		else {
			flipped.push_back(S[i]);
		}
	}
	apply_flipped_reversed(s, flipped);

	cout << flipped << '\n';
	return 0;
}