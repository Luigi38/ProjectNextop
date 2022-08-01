#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> get_first_priorited(const string& word, const int start, const int end) {
	vector<pair<int, int>> v;
	vector<int> indicies;

	for (int i = start; i <= end; i++) v.push_back({ word[i] - 'a', i });
	sort(v.begin(), v.end());

	indicies.push_back(v[0].second);

	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1].first == v[i].first) indicies.push_back(v[i].second);
		else break;
	}

	return indicies;
}

void apply_splitted_string(stack<char>& s, string& splitted) {
	while (!s.empty()) {
		splitted.push_back(s.top());
		s.pop();
	}
}

int main() {
	string word;
	cin >> word;

	vector<string> words;
	vector<int> indicies_first = get_first_priorited(word, 0, word.size() - 3);

	for (int index_first : indicies_first) {
		vector<int> indicies_second = get_first_priorited(word, index_first + 1, word.size() - 2);

		for (int index_second : indicies_second) {
			string splitted = "";
			stack<char> s;

			for (int i = 0; i < word.size(); i++) {
				s.push(word[i]);
				if (i == index_first || i == index_second || i == word.size() - 1) apply_splitted_string(s, splitted);
			}
			words.push_back(splitted);
		}
	}

	sort(words.begin(), words.end());
	cout << words[0] << '\n';

	return 0;
}