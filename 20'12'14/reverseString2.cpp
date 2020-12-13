//2020³â 12¿ù 14ÀÏ
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct footprint
{
	size_t start;
	size_t end;
	bool is_reversed;
};

int main()
{
	string sentence;
	getline(cin, sentence);

	vector<footprint> v;

	size_t start = 0U, end = 0U;
	bool is_allocated = false, is_tag = false;
	
	for (size_t i = 0; i < sentence.size(); i++)
	{
		char ch = sentence[i];

		if (ch == '<')
		{
			if (start != 0U || end != 0U) v.push_back({ start, end, true });
			start = i;
			end = 0U;
			is_allocated = false;
			is_tag = true;
		}
		else if (ch == '>')
		{
			end = i;
			v.push_back({ start, end, false });

			start = 0U;
			end = 0U;
			is_allocated = false;
			is_tag = false;
		}
		else if (ch == ' ')
		{
			if (!is_tag) {
				v.push_back({ start, end, true });
				v.push_back({ i, i, false });
				start = 0U;
				end = 0U;
				is_allocated = false;
			}
		}
		else
		{
			if (!is_allocated && !is_tag) {
				start = i;
				is_allocated = true;
			}
			end = i;

			if (i == sentence.size() - 1) v.push_back({ start, end, true });
		}
	}

	for (auto fp : v) {
		if (!fp.is_reversed) for (size_t i = fp.start; i <= fp.end; i++) cout << sentence[i];
		else {
			for (size_t i = fp.end; i >= fp.start; i--) {
				cout << sentence[i];
				if (i == 0) break;
			}
		}
	}
}