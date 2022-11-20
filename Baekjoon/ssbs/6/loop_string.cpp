#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int T;
	vector<string> v;

	cin >> T;

	for (int i = 0; i < T; i++) {
		string S;
		int R;
		string P = "";

		cin >> R >> S;

		for (char ch : S)
			for (int i = 0; i < R; i++)
				P.push_back(ch);

		v.push_back(P);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}