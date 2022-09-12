#include <iostream>
#include <string>
#include <vector>
using namespace std;

int get_index(const char ch) {
	if (ch >= 'A' && ch <= 'Z') return ch - 'A';
	else if (ch >= 'a' && ch <= 'z') return ch - 'a';
	return -1;
}

int main() {
	vector<int> v;

	while (true) {
		string str;
		vector<bool> how(26, false);
		int count = 0;

		getline(cin, str);

		if (str == "#") break;

		for (char ch : str) {
			int index = get_index(ch);
			if (index != -1 && !how[index]) how[index] = true;
		}

		for (int i = 0; i < how.size(); i++) if (how[i]) count++;
		v.push_back(count);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}