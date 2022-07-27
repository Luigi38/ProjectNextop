//2020³â 12¿ù 13ÀÏ
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void convert_to_array(const string& s, const int n, deque<int>& v)
{
	if (n > 0)
	{
		int value = 0;

		for (auto ch : s)
		{
			if (ch == '[') continue;
			if (ch == ',' || ch == ']')
			{
				v.push_back(value);
				value = 0;
			}
			else value = value * 10 + (ch - '0');
		}
	}
}

void start_ac(deque<int>& v, const string& functions, bool& is_error, bool &is_reverse)
{
	is_error = false;
	is_reverse = false;
	
	for (auto f : functions)
	{
		if (f == 'R' && !v.empty()) is_reverse = !is_reverse;
		if (f == 'D' && !v.empty())
		{
			if (is_reverse) v.pop_back();
			else v.pop_front();
		}
		else if (f == 'D') {
			is_error = true;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	deque<int> v;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		v.clear();
		
		string functions;
		int n;

		string arr;
		bool is_error, is_reverse;
		cin >> functions >> n >> arr;

		convert_to_array(arr, n, v);
		start_ac(v, functions, is_error, is_reverse);

		if (!is_error)
		{
			
			cout << '[';
			while (!v.empty())
			{
				int value = is_reverse ? v.back() : v.front();
				if (is_reverse) v.pop_back();
				else v.pop_front();

				cout << value;
				if (!v.empty()) cout << ',';
			}
			cout << "]\n";
		}
		else cout << "error\n";
	}

	return 0;
}