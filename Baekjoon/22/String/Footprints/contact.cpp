#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare_by_length(const string& a, const string& b) {
	return a.size() < b.size();
}

bool starts_with(const string& a, const string& prefix) {
	//cout << "starts_with(" << a << ", " << prefix << ")\n";
	
	if (a.size() < prefix.size()) return false;
	
	for (int i = 0; i < prefix.size(); i++) if (a[i] != prefix[i]) return false;
	return true;
}

bool is_consistent(const vector<string>& v) {
	for (int i = 0; i < v.size(); i++) //prefix
		for (int j = i + 1; j < v.size(); j++) //object to compare
			if (starts_with(v[j], v[i])) return false;
	return true;
}

int main()
{
    vector<vector<string> > v;
    int t;
    
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        v.push_back(vector<string>());
        
        for (int i = 0; i < n; i++) {
            string str;
            
            cin >> str;
            v[v.size() - 1].push_back(str);
        }
        
        sort(v[v.size() - 1].begin(), v[v.size() - 1].end(), compare_by_length);
    }
    
    for (int i = 0; i < t; i++) {
    	if (is_consistent(v[i])) cout << "YES\n";
    	else cout << "NO\n";
	}
}
