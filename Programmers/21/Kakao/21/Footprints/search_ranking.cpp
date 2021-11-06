#include <string>
#include <vector>

using namespace std;

struct privacy {
    string lang;
    string job;
    string career;
    string food;
    int score;
};

bool operator ==(const privacy& a, const privacy& b) {
    bool equals = true;
    
    if (b.lang != "-") equals = a.lang == b.lang;
    if (b.job != "-") equals = a.job == b.job;
    if (b.career != "-") equals = a.career == b.career;
    if (b.food != "-") equals = a.food == b.food;
    if (b.score != -1) equals = a.score == b.score;
    
    return equals;
}

void get_privacies(const vector<string>& info, vector<privacy>& v) {
    
}

privacy get_privacy_from_string(string query) {
    
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<privacy> v;
    get_privacies(info, v);
    
    for (auto str : query) {
        privacy pr = get_privacy_from_string(str);
        
        
    }
    
    return answer;
}