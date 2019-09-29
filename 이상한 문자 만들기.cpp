#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string answer = "";
    bool ch = true;
    for(int i=0; i<(int)s.size(); i++) {
        if(s[i]==' ') {
            ch = true;
            answer += ' ';
        }
        else {
            if(ch) {
                ch = false;
                answer += toupper(s[i]);
            } else {
                ch = true;
                answer += tolower(s[i]);
            }
        }
    }
    return answer;
}
