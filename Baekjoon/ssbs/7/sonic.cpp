#define MAX 2147483647
#define ull unsigned long long
#include <iostream>
using namespace std;

int main() {
	//break-even point
	int A, B, C;
	int sonic = -1;
	ull sale;
	ull fixed;
	ull unfixed;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	int prev = MAX;
	int maxx = MAX;

	while (maxx > 0) {
		sale = maxx * (ull)C;
		fixed = A;
		unfixed = maxx * (ull)B;

		if (sale <= fixed + unfixed) {
			break;
		}

		prev = maxx;
		maxx = (int)(maxx / 1.01);
	}

	if (maxx != MAX) {
		for (ull i = maxx; i <= prev; i++) {
			sale = i * C;
			fixed = A;
			unfixed = i * B;

			if (sale > fixed + unfixed) {
				sonic = i;
				break;
			}
		}
	}
	
	cout << sonic << '\n';
	return 0;
}