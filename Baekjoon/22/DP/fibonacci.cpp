#include <iostream>
#include <vector>
using namespace std;

int fibonacci(const int n, vector<int>& dp) {
	if (n < 2) {
		if (n == 0) return 0;
		if (n == 1) return 1;
	}

	int a = dp[n - 2];
	int b = dp[n - 1];

	if (a == -1) a = fibonacci(n - 2, dp);
	if (b == -1) b = fibonacci(n - 1, dp);

	return a + b;
}

int main() {
	int n;
	vector<int> dp(21, -1);
	
	dp[0] = 0;
	dp[1] = 1;

	cin >> n;
	cout << fibonacci(n, dp);

	return 0;
}