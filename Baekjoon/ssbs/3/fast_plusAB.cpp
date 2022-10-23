#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	vector<int> v;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;

		cin >> a >> b;
		v.push_back(a + b);
	}

	for (int i = 0; i < T; i++) cout << v[i] << '\n';
	return 0;
}