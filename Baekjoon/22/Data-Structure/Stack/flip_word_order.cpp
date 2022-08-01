#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

string lets_flip(const string& str) {
	stack<string> s;
	string word = "";
	string flipped = "";

	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			word.push_back(str[i]);
		}
		else {
			s.push(word);
			word = "";
		}
	}
	s.push(word);

	while (!s.empty()) {
		flipped += s.top();
		s.pop();

		if (!s.empty()) flipped.push_back(' ');
	}

	return flipped;
}

int main() {
	int N;
	vector<string> v;

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		
		string flipped = lets_flip(str);
		v.push_back(flipped);
	}

	for (int i = 0; i < N; i++) cout << "Case #" << i + 1 << ": " << v[i] << '\n';
	return 0;
}