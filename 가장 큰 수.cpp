#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool bigger(string s1, string s2) {
    if(s1+s2 > s2+s1) return true;
    else return false;
}

string solution(vector<int> numbers) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string> numStr;
    for(int i=0; i<numbers.size(); i++) {
        numStr.push_back(to_string(numbers[i]));
    }
    sort(numStr.begin(), numStr.end(), bigger);
    
    string answer = "";
    for(int i=0; i<numStr.size(); i++) {
        answer += numStr[i];
    }
    if (answer[0] == '0')
    return "0";
    return answer;
}
