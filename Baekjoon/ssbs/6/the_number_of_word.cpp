#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int count = 0;
	
	getline(cin, str);
	
	char prev = str[0];

	if (str.back() != ' ') str.push_back(' ');

	for (int i = 1; i < str.size(); i++) {
		char ch = str[i];

		if (i == 1 && prev == ' ') {
			prev = ch;
			continue;
		}
		if (i == str.size() - 1) {
			count++;
			break;
		}
		if (prev == ' ' && ch != ' ') count++;
		prev = ch;
	}

	cout << count << '\n';
	return 0;
}