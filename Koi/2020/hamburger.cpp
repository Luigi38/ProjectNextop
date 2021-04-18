#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

inline bool valid(vector<char>& v, const int index) {
	if (index >= 0 && index < v.size() && v[index] == 'H') {
		v[index] = 'X'; //this hamburger can't be reused (eaten)
		return true;
	}
	return false;
}

int eat_hamburger(const string& restaurant, const int N, const int k) {
	vector<char> v(restaurant.begin(), restaurant.end());
	int count = 0;

	for (int i = 0; i < N; i++) {
		char ch = v[i];

		if (ch == 'P') { //Person
			for (int j = i - k; j <= i + k; j++) {
				if (valid(v, j)) {
					count++;
					break;
				}
			}
		}
	}

	return count;
}

int main() {
	string restaurant;
	int N, k;

	cin >> N >> k;
	cin >> restaurant;

	cout << eat_hamburger(restaurant, N, k) << '\n';
	return 0;
}