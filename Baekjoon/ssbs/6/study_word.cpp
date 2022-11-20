#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string word;
	vector<int> v(26, 0);
	int maxx = 0;
	int maxxi = -1;
	int maxxc = 0;
	char most = '?';

	cin >> word;

	for (char ch : word) {
		if (ch >= 'A' && ch <= 'Z') v[ch - 'A']++;
		else if (ch >= 'a' && ch <= 'z') v[ch - 'a']++;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > maxx) {
			maxx = v[i];
			maxxi = i;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (maxx != 0 && v[i] == maxx) maxxc++;
	}

	if (maxxc == 1) most = maxxi + 'A';

	cout << most << '\n';
	return 0;
}