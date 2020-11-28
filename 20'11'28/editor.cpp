#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	list<char> editor;
	list<char>::iterator cursor;

	string str;
	int M;

	cin >> str >> M;
	
	for (char c : str) editor.push_back(c);
	cursor = editor.end();

	for (int i = 0; i < M; i++) {
		char cmd;
		cin >> cmd;

		switch (cmd) {
		case 'L':
			if (cursor != editor.begin()) cursor--;
			break;

		case 'D':
			if (cursor != editor.end()) cursor++;
			break;

		case 'B':
			if (cursor != editor.begin()) {
				cursor--;
				cursor = editor.erase(cursor);
			}
			break;

		case 'P':
			char ch;
			cin >> ch;

			editor.insert(cursor, ch);
			break;
		}
	}

	for (auto it = editor.begin(); it != editor.end(); it++) cout << *it;
	cout << endl;
	return 0;
}