#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int idx=0;
    for(int i=0; i<seoul.size(); i++){
        if(seoul[i]=="Kim") idx=i;
    }
    string answer = "김서방은 ";
    answer += to_string(idx);
    answer += "에 있다";
    return answer;
}
