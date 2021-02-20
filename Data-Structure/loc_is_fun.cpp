#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

void insert(int item, int loc) {
	v.push_back(0);

	int i;
	for (i = v.size() - 2; i >= loc; i--) {
		v[i + 1] = v[i];
	}

	v[loc] = item;
}

int main() {
	int i;
	for (i = 0; i < 3; i++) v.push_back(i);

	int item;
	cin >> item;

	int loc;
	cin >> loc;

	insert(item, loc);

	for (i = 0; i < v.size(); i++) cout << v[i] << endl;
	return 0;
}