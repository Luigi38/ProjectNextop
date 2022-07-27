#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> get_sung_won_kilogram(const int G) {
	vector<int> v;
	ll n_start = (ll)sqrt((double)G) + 1LL;

	for (ll n = n_start; n <= 100000LL + n_start; n++) {
		ll current_g = (ll)n * n;
		ll expected = current_g - G;
		ll expected2 = (ll)sqrt(expected);
		
		if (current_g > G && expected == expected2 * expected2) {
			v.push_back((int)n);
		}
	}

	return v;
}

int main() {
	int G;
	cin >> G;

	auto gram = get_sung_won_kilogram(G);

	if (gram.size() > 0) {
		for (int i = 0; i < gram.size(); i++) {
			cout << gram[i] << '\n';
		}
	}
	else {
		cout << "-1\n";
	}
	return 0;
}