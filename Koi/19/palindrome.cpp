#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_real(string& str) {
	for (int i = 0; i < (str.size() / 2); i++) if (str[i] != str[str.size() - i - 1]) return false;
	return true;
}

bool is_pseudo(string& str) {
	for (int i = 0; i < (str.size() / 2); i++) {
		int i2 = str.size() - i - 1;

		if (str[i] != str[i2]) {
			string str1(str);
			string str2(str);

			str1.erase(i, 1);
			str2.erase(i2, 1);

			if (is_real(str1) || is_real(str2)) return true;
			return false;
		}
	}
	return true;
}

int get_palindrome(string& str) {
	if (is_real(str)) return 0;
	if (is_pseudo(str)) return 1;
	return 2;
}

int main() {
	int T;
	vector<string> v;

	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;

		cin >> s;
		v.push_back(s);
	}
	
	for (int i = 0; i < T; i++) {
		cout << get_palindrome(v[i]) << '\n';
	}

	return 0;
}