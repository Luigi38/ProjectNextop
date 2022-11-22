#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main() {
	set<string> s = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	set<char> s2 = { 'c', 'd', 'l', 'n', 's', 'z' };
	set<int> s3;
	int count = 0;
	string word;

	cin >> word;

	for (int i = 0; i < word.size(); i++) {
		string str = "";

		if (s2.find(word[i]) == s2.end()) continue;

		for (int j = i; j < word.size(); j++) {
			str.push_back(word[j]);

			if (s.find(str) != s.end()) {
				for (int k = i; k <= j; k++) s3.insert(k);
				count++;
				i += j - i - 1;

				break;
			}
		}
	}

	for (int i = 0; i < word.size(); i++) {
		if (s3.find(i) != s3.end()) continue;
		count++;
	}
	
	cout << count << '\n';
	return 0;
}