#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    vector<char> v(new_id.begin(), new_id.end());

    int vs = 0; //start index
    int ve = new_id.length(); //end
    int vc = new_id.length(); //count

    for (int i = 0; i < 50; i++) v.push_back(' ');

    //step 1 [v]
    for (int i = 0; i < v.size(); i++) if (v[i] >= 'A' && v[i] <= 'Z') v[i] = v[i] + 'a' - 'A';

    //step 2 [v]
    int ei = 0;

    for (int i = vs; i < v.size(); i++) {
        if (i > ve - 1) break;

        bool is_lower_case = v[i] >= 'a' && v[i] <= 'z';
        bool is_digit = v[i] >= '0' && v[i] <= '9';

        if (!is_lower_case && !is_digit && v[i] != '-' && v[i] != '_' && v[i] != '.') {
            v[i] = ' ';
            vc--;

            if (vs == i) vs++;
            if (ve - 1 == i) ve = ei + 1;
        }
        else {
            ei = i;
        }
    }

    //step 3 [v]
    char ch = ' ';
    ei = 0;

    for (int i = vs; i < v.size(); i++) {
        if (i > ve - 1) break;

        if (v[i] == '.' && ch == '.') {
            v[i] = ' ';
            vc--;

            if (vs == i) vs++;
            if (ve - 1 == i) ve = ei + 1;
        }
        else if (v[i] != ' ') {
            ch = v[i];
            ei = i;
        }
    }

    //step 4 [v]
    for (int i = vs; i < v.size(); i++) {
        if (i > ve - 1) break;

        if (v[i] == '.') {
            v[i] = ' ';
            vc--;
            vs++;
        }
        else if (v[i] != ' ') {
            break;
        }
    }

    for (int i = ve - 1; i >= 0; i--) {
        if (i < vs) break;

        if (v[i] == '.') {
            v[i] = ' ';
            vc--;
        }
        else if (v[i] != ' ') {
            ve = i + 1;
            break;
        }
    }

    //step 5 [v]
    if (vc == 0) {
        v[0] = 'a';

        vs = 0;
        ve = 1;
        vc = 1;
    }

    //step 6 [PROBLEM]
    if (vc >= 16) {
        while (vc != 15) {
            if (v[ve - 1] != ' ') {
                v[ve - 1] = ' ';
                vc--;
                
            }
            ve--;
        }
    }

    for (int i = ve - 1; i >= 0; i--) {
        if (i < vs) break;

        if (v[i] == '.') {
            v[i] = ' ';
            vc--;
        }
        else if (v[i] != ' ') {
            ve = i + 1;
            break;
        }
    }

    //step 7
    if (vc <= 2) {
        char ch = v[ve - 1];

        while (vc != 3) {
            v[ve] = ch;
            vc++;
            ve++;
        }
    }

    for (int i = 0; i < v.size(); i++) if (v[i] != ' ') answer += v[i];
    return answer;
}