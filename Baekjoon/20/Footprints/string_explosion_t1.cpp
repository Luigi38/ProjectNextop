#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

namespace ftp {
	struct footprint {
		int start;
		int end;
	};

	footprint empty() {
		return { 0, 0 };
	}

	void search(vector<char>& v, string &str, string &pattern) {
		int count = 0;

		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];

			if (count > 0) {
				count--;
				continue;
			}

			if (ch == pattern[0]) {
				int length = (int)pattern.size();

				if (str.substr(i, length) == pattern) {
					count = length;
				}
			}
			else {
				v.push_back(ch);
			}
		}
	}

	footprint find(vector<char>& v, string& str, string& pattern) {
		footprint fp = empty();

		int count = 0;

		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];

			if (count > 0) {
				count--;
				continue;
			}

			if (ch == pattern[0]) {
				int length = (int)pattern.size();

				if (str.substr(i, length) == pattern) {
					fp = { i, i + length };
					count = length;
				}
			}
		}

		return fp;
	}

	bool operator==(footprint fp1, footprint fp2) {
		return fp1.start == fp2.start && fp1.end == fp2.end;
	}

	bool operator!=(footprint fp1, footprint fp2) {
		return !(fp1 == fp2);
	}
}

int main() {
	string str;
	string explosion;

	vector<char> v;
	ftp::footprint fp = ftp::empty();

	cin >> str >> explosion;

	while (true) {
		ftp::search(v, str, explosion);

		string tmp(v.begin(), v.end());
		str = tmp;

		if (ftp::find(v, str, explosion) == ftp::empty()) break;
	}

	string str2(v.begin(), v.end());

	if (str2.empty()) str2 = "FRULA";
	cout << str2 << endl;

	return 0;
}