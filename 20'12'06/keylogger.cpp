//2020³â 12¿ù 6ÀÏ
#include <iostream>
#include <queue>
#include <deque>
#include <string>
using namespace std;

void decrypt(string& encrypted, deque<char>& v)
{
	auto cursor = v.end();
	
	for (auto ch : encrypted)
	{
		if (ch == '<')
		{
			if (cursor != v.begin()) cursor--;
		}
		else if (ch == '>')
		{
			if (cursor != v.end()) cursor++;
		}
		else if (ch == '-')
		{
			if (cursor != v.begin()) cursor = v.erase(--cursor);
		}
		else
		{
			cursor = v.insert(cursor, ch);
			if (cursor != v.end()) cursor++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	queue<deque<char>> v;

	cin >> n;

	for (auto i = 0; i < n; i++)
	{
		string encrypted;
		deque<char> password;
		
		cin >> encrypted;

		decrypt(encrypted, password);
		v.push(password);
	}

	while (!v.empty()) {
		auto password = v.front();
		v.pop();
		
		for (auto ch : password) cout << ch;
		cout << '\n';
	}

	return 0;
}