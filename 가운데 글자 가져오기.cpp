#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int slen = s.length();
    string answer = "";
    if(slen%2==1) {
        answer = s[(slen-1)/2];
    } else {
        answer = s[slen/2-1];
        answer += s[slen/2];
    }
    return answer;
}
