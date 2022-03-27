#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int h;
		
		cin >> h;
		v.push_back(h);
	}
	
	int fh = v[v.size() - 1];
	int count = 1;

	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] > fh) {
			count++;
			fh = v[i];
		}
	}

	cout << count << '\n';
	return 0;
}