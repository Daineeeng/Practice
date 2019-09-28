#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool answer = true;
    int slen = s.length();
    if(slen!=4 && slen!=6) {
        answer = false;
    } else {
        for(int i=0; i<slen; i++) {
           if(!('0' <= s[i] && s[i] <= '9')) {
               answer = false;
                break;
           }
        }
    }
    return answer;
}
