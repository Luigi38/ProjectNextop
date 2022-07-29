#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

void to_X(list<int>& l, const bool is_reverse, string& X) {
	int i = 0;

	X += "[";

	while (!l.empty()) {
		int xi = 0;

		if (!is_reverse) {
			xi = l.front();
			l.pop_front();
		}
		else {
			xi = l.back();
			l.pop_back();
		}

		X += to_string(xi);
		if (!l.empty()) X += ",";
	}

	X += "]";
}

void to_L(const string& X, list<int>& l) {
	int xi = 0;

	for (char ch : X) {
		if (ch == '[') continue;
		if ((ch == ',' || ch == ']') && xi != 0) {
			l.push_back(xi);
			xi = 0;
		}
		else {
			xi = xi * 10 + ch - '0';
		}
	}
}

int main() {
	int T;
	vector<string> v;

	cin >> T;

	for (int t = 0; t < T; t++) {
		string p; //functions
		int N;
		string X;

		list<int> l;
		bool is_reverse = false;
		bool is_error = false;

		cin >> p >> N >> X;

		to_L(X, l);

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				is_reverse = !is_reverse;
			}
			else if (p[i] == 'D') {
				if (l.empty()) {
					is_error = true;
					break;
				}

				if (!is_reverse) l.pop_front();
				else l.pop_back();
			}
		}

		if (is_error) {
			v.push_back("error");
			continue;
		}

		string modified_X = "";
		to_X(l, is_reverse, modified_X);

		v.push_back(modified_X);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}