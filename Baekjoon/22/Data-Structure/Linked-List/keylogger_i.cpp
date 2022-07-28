#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main() {
	int T;
	vector<string> v;

	cin >> T;

	for (int t = 0; t < T; t++) {
		list<char> l;
		list<char>::iterator it = l.end();
		string str;

		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			switch (str[i]) {
				case '<': //left arrow
					if (it != l.begin()) it--;
					break;

				case '>': //right arrow
					if (it != l.end()) it++;
					break;

				case '-': //backspace
					if (it != l.begin()) it = l.erase(--it);
					break;

				default: //a part of password (char)
					l.insert(it, str[i]);
					break;
			}
		}

		string password;
		
		for (it = l.begin(); it != l.end(); it++) password += *it;
		v.push_back(password);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}