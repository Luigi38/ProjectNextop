#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> s;
    
    for (int i = 0; i < phone_book.size(); i++) {
        string number = phone_book[i];
        string prefix = "";
        
        for (int j = 0; j < number.size() - 1; j++) {
            prefix += number[j];
            
            if (s.find(prefix) == s.end()) {
                s.insert(prefix);
            }
        }
    }
    
    for (int i = 0; i < phone_book.size(); i++) {
        string number = phone_book[i];
        
        if (s.find(number) != s.end()) {
            answer = false;
            break;
        }
    }
    
    return answer;
}
