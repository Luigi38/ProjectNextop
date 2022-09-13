#include <iostream>
#include <string>
using namespace std;

void modify_count(int& i, const int size) {
	if (i == size - 1) i = 0;
	else i++;
}

int main() {
	string s;
	string t;

	int result = 1;

	cin >> s >> t;

	string prefix;
	string str;

	if (s.size() < t.size()) {
		prefix = s;
		str = t;
	}
	else {
		prefix = t;
		str = s;
	}

	int j = 0; //prefix index

	for (int c = 0; c < 2; c++) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != prefix[j]) {
				result = 0;
				break;
			}
			modify_count(j, prefix.size());
		}
		if (result == 0) break;
	}
	
	cout << result << '\n';
	return 0;
}