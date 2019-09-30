#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int num) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string answer = "";
    bool chk = num%2;
    if(chk) answer = "Odd";
    else answer = "Even";
    return answer;
}
