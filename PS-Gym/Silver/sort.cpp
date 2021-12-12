#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int value;
		
		cin >> value;
		v.push_back(value);
	}

	sort(v.begin(), v.end());

	for (int value : v) cout << value << " ";
	return 0;
}