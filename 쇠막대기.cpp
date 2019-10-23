#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    vector<char> v;
    for(int i=0; i<arrangement.size(); i++) {
        if(arrangement[i] == '(') v.push_back(arrangement[i]);
        else {
            v.pop_back();
            if(arrangement[i-1]=='(') answer += v.size();
            else answer++;
        }
    }
    return answer;
}
