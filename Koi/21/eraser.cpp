#include <iostream>
#include <vector>
using namespace std;

vector<int> erase(vector<int>& v) {
	vector<int> tmp;

	for (int i = 0; i < v.size(); i += 2) {
		v[i] = 0;
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0) {
			tmp.push_back(v[i]);
		}
	}

	return tmp;
}

int main() {
	int N;
	vector<int> v;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	while (v.size() != 1) {
		v = erase(v);
	}

	cout << v[0] << '\n';
	return 0;
}
