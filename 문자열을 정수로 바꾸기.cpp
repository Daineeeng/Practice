#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool buho = true;
    if(s[0]=='-') {bool buho=false;}
    int answer = stoi(s);
    if(!buho) answer = -answer;
    return answer;
}
