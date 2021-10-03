#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    vector<char> v(new_id.begin(), new_id.end());
    vector<char> v2;

    //step 1
    int correction = 'a' - 'A';
    for (int i = 0; i < v.size(); i++) if (v[i] >= 'A' && v[i] <= 'Z') v[i] += correction;

    //step 2
    for (int i = 0; i < v.size(); i++) {
        bool is_lower_case = v[i] >= 'a' && v[i] <= 'z';
        bool is_digit = v[i] >= '0' && v[i] <= '9';

        if (is_lower_case || is_digit || v[i] == '-' || v[i] == '_' || v[i] == '.') v2.push_back(v[i]);
    }

    //step 3
    char ch = ' ';
    v.clear();
    
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] != '.' || ch != '.') {
            v.push_back(v2[i]);
            ch = v2[i];
        }
    }

    //step 4
    v2.clear();
    
    int ds = -1;
    int de = v.size();
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == '.') ds = i;
        else break;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == '.') de = i;
        else break;
    }
    
    for (int i = ds + 1; i < de; i++) {
        v2.push_back(v[i]);
    }

    //step 5
    bool step_by_step = false;
    
    v.clear();
    if (v2.size() == 0) {
        v.push_back('a');
        step_by_step = true;
    }

    //step 6
    if (v2.size() >= 16) {
        for (int i = 0; i < 15; i++) {
            v.push_back(v2[i]);
        }
        step_by_step = true;
    }
    if (!step_by_step) v = vector<char>(v2.begin(), v2.end());
    v2.clear();
    de = v.size();

    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == '.') de = i;
        else break;
    }
    
    for (int i = 0; i < de; i++) {
        v2.push_back(v[i]);
    }

    //step 7
    int last_index = v2.size() - 1;
    if (v2.size() <= 2) while (v2.size() != 3) v2.push_back(v2[last_index]);
    
    for (int i = 0; i < v2.size(); i++) answer += v2[i];
    return answer;
}