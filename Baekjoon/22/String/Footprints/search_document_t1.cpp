#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string prefix;

	getline(cin, str);
	getline(cin, prefix);

	int pi = 0;
	int index = 0;
	int count = 0;

	while (true) {

		index++;
	}

	for (int i = 0; i < str.size(); i++) {
		if (prefix[index] == str[i]) {
			if (index == prefix.size() - 1) {
				count++;
				index = 0;

				continue;
			}
			index++;
		}
		else if (index != 0) {
			index = 0;
		}
	}

	cout << count << '\n';
	return 0;
}