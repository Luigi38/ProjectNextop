#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for (int i = 0; i < participant.size(); i++) {
        string person = participant[i];
        m[person]++;
    }
    
    for (int i = 0; i < completion.size(); i++) {
        string person = completion[i];
        m[person]--;
    }
    
    for (int i = 0; i < participant.size(); i++) {
        string person = participant[i];
        
        if (m[person] != 0) {
            answer = person;
            break;
        }
    }
    
    return answer;
}
