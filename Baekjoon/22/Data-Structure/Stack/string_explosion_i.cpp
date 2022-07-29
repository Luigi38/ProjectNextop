#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	string explosion;

	cin >> str >> explosion;

	vector<string> s;
	bool is_guaranteed = false;

	for (int i = 0; i < str.size(); i++) {
		if (s.empty() || !is_guaranteed || str[i] != explosion[s.back().size()]) {
			string strin = "";
			
			strin += str[i];
			s.push_back(strin);
		}
		else {
			s.back() += str[i];
		}

		if (s.back() == explosion) {
			s.pop_back();
			if (!s.empty()) is_guaranteed = s.back().back() == explosion[s.back().size() - 1];
		}
		else {
			is_guaranteed = str[i] == explosion[s.back().size() - 1];
		}
	}

	if (s.empty()) {
		cout << "FRULA\n";
		return 0;
	}

	string exploded = "";

	for (int i = 0; i < s.size(); i++) exploded += s[i];
	cout << exploded << '\n';

	return 0;
}