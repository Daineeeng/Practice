#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> seoul) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string answer = "김서방은 ";
    for(int i=0; i<(int)seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            answer += to_string(i);
            break;
        }
    }
    answer += "에 있다";
    return answer;
}
