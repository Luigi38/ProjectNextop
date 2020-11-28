#include <iostream>
#include <vector>
#include <string>
using namespace std;

void search(vector<char>& v, vector<char>& v2, string& pattern) {
	int count = 0;
	char ch;

	for (auto it = v.begin(); it != v.end(); it++) {
		ch = *it;

		if (count > 0) {
			count--;
			continue;
		}

		if (equal(it, it + pattern.size(), pattern.begin())) count = pattern.size() - 1;
		else v2.push_back(ch);
	}
}

int main() {
	string str;
	string explosion;

	vector<char> v;
	vector<char> v2;

	cin >> str >> explosion;
	for (char c : str) v.push_back(c);

	while (true) {
		search(v, v2, explosion);
		if (v.size() == v2.size()) break;

		v = v2;
		v2.clear();
	}

	if (v.empty()) cout << "FRULA" << endl;
	else {
		for (char c : v) cout << c;
		cout << endl;
	}

	return 0;
}