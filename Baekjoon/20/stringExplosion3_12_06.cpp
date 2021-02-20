//2020³â 12¿ù 6ÀÏ
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	deque<char> v;
	
	string str;
	string explosion;
	cin >> str >> explosion;

	for (auto ch : str)
	{
		bool found = true;
		
		v.push_back(ch);
		if (v.size() < explosion.size() || ch != explosion.back()) continue;

		for (size_t i = 0; i < explosion.size(); i++)
		{
			if (v[v.size() - i - 1] != explosion[explosion.size() - i - 1])
			{
				found = false;
				break;
			}
		}

		if (found) for (size_t i = 0; i < explosion.size(); i++) v.pop_back();
	}

	if (v.empty()) cout << "FRULA";
	else for (size_t i = 0; i < v.size(); i++) cout << v[i];
	cout << '\n';
	
	return 0;
}