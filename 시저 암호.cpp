#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string answer = "";
    for(int i=0; i<(int)s.size(); i++) {
        if (s[i]==' ') {answer += ' ';}
        else {
            if ('a' <= s[i] && s[i] <= 'z') {
                answer += ((s[i] + n -'a')%26) + 'a';
            } else if ('A' <= s[i] && s[i] <='Z') {
                answer += ((s[i] + n -'A')%26) + 'A';
            }
        }
    }
    return answer;
}
