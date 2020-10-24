#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void delete_item(vector<int> &v, int loc) {
	int i;
	for (i = loc; i < v.size() - 1; i++) {
		v[i] = v[i + 1];
	}

	v.pop_back();
}

int main() {
	vector<int> v;

	int i;
	for (i = 0; i < 3; i++) {
		v.push_back(i + 1);
	}

	int loc;
	cin >> loc;

	delete_item(v, loc);
	
	for (i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}