#include <iostream>
#include <list>
#include <string>
using namespace std;

int search(list<char>& v, string& pattern) {
	int length = v.size();
	char ch;
	bool pp;

	for (auto it = v.begin(); it != v.end();) {
		ch = *it;
		pp = true;

		if (ch == pattern[0]) {
			auto it2 = it;
			for (int i = 0; i < pattern.size(); i++) if (it2 != v.end()) it2++;

			if (equal(it, it2, pattern.begin())) {
				it = v.erase(it, it2);
				pp = false;
			}
		}

		if (pp) it++;
	}

	return length;
}

int main() {
	string str;
	string explosion;

	list<char> v;

	cin >> str >> explosion;
	for (char c : str) v.push_back(c);

	while (true) {
		int length = search(v, explosion);
		if (v.size() == length) break;
	}

	if (v.empty()) cout << "FRULA" << endl;
	else {
		for (char c : v) cout << c;
		cout << endl;
	}

	return 0;
}