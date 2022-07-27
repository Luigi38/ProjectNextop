#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	int M;
	string str;
	list<char> l;

	cin >> str >> M;

	for (int i = 0; i < str.size(); i++) l.push_back(str[i]);

	auto it = l.end();

	for (int i = 0; i < M; i++) {
		char f;

		cin >> f;

		switch (f) {
			case 'L':
				if (it != l.begin()) it--;
				break;

			case 'D':
				if (it != l.end()) it++;
				break;

			case 'B':
				if (it != l.begin()) it = l.erase(--it);
				break;

			case 'P':
				char param;
				cin >> param;

				l.insert(it, param);
				break;
		}
	}

	for (it = l.begin(); it != l.end(); it++) cout << *it;
	cout << '\n';

	return 0;
}