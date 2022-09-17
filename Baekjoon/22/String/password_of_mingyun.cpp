#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
	vector<string> v;
	set<string> s;
	int N;

	int length = 0;
	char ch = ' ';

	cin >> N;

	for (int i = 0; i < N; i++) {
		string word;

		cin >> word;
		v.push_back(word);
	}

	for (int i = 0; i < N; i++) {
		string word = v[i];
		string wordr = word;

		reverse(wordr.begin(), wordr.end());
		
		if (!s.insert(word).second || !s.insert(wordr).second) {
			length = word.size();
			ch = word[word.size() / 2];
			
			break;
		}
	}

	cout << length << ' ' << ch << '\n';
	return 0;
}