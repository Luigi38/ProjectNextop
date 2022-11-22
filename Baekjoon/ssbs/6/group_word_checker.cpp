#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int N;
	int count = 0;

	cin >> N;

	for (int n = 0; n < N; n++) {
		set<char> s;
		string word;
		char prev;
		bool isGrouped = true;

		cin >> word;
		
		prev = word[0];
		s.insert(prev);

		for (int i = 1; i < word.size(); i++) {
			char ch = word[i];

			if (prev == ch) continue;
			if (s.find(ch) != s.end()) {
				isGrouped = false;
				break;
			}

			prev = ch;
			s.insert(ch);
		}

		if (isGrouped) {
			count++;
		}
	}

	cout << count << '\n';
	return 0;
}