#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string phone_number) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int pn_sz = phone_number.length();
    string answer = "";
    for(int i=0; i < pn_sz; i++) {
        if(i < pn_sz - 4) answer += '*';
        else answer += phone_number.at(i);
    }
    return answer;
}
